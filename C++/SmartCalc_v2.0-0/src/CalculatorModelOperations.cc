#include "headers/CalculatorModel.h"

namespace s21 {
void CalculatorModel::GrammarParser(const string& expression,
                                    const string& x_value) {
  if ((x_value.empty() && expression.find('x') != string::npos) ||
      (!CheckXValue(x_value))) {
    throw invalid_argument("x is invalid");
  }
  int SizeExpression = expression.size();
  for (int index = 0; index < SizeExpression;) {
    int begin_lexema = index;
    if (isdigit(expression[index]) || expression[index] == 'x') {
      NumberGrammarCheck(index, expression, begin_lexema);
    } else if (expression[index] == 'e') {
      index++;
      lexems_.push_back({expression.substr(begin_lexema, index - begin_lexema),
                         OPERATION_2_OPERAND});
    } else if (isalpha(expression[index])) {
      FunctionGrammarCheck(index, expression, begin_lexema);
    } else if (expression[index] == '(' || expression[index] == ')' ||
               expression[index] == '+' || expression[index] == '-' ||
               expression[index] == '*' || expression[index] == '/' ||
               expression[index] == '^') {
      OperationsGrammarCheck(index, expression, begin_lexema);
    } else {
      throw invalid_argument("unknown character symbol " + to_string(index));
    }
  }
}

bool CalculatorModel::CheckXValue(const string& x_value) {
  int amount_point = 0, index = 0;
  if (x_value[index] == '+' || x_value[index] == '-') index++;
  while (isdigit(x_value[index]) || x_value[index] == '.') {
    if (x_value[index] == '.') amount_point++;
    index++;
    if (amount_point > 1) {
      break;
    }
  }
  if ((int)x_value.size() != index) {
    return false;
  }
  this->x_value_ = std::stod(x_value);
  return true;
}

void CalculatorModel::NumberGrammarCheck(int& index, const string& expression,
                                         const int& begin_lexema) {
  short amount_points = 0;
  if (expression[index] == 'x')
    index++;
  else {
    while (isdigit(expression[index]) || expression[index] == '.') {
      if (expression[index] == '.') amount_points++;
      index++;
      if (amount_points > 1)
        throw invalid_argument("invalid number symbol " + to_string(index));
    }
  }
  lexems_.push_back(
      {expression.substr(begin_lexema, index - begin_lexema), NUMBER});
}

void CalculatorModel::FunctionGrammarCheck(int& index, const string& expression,
                                           const int& begin_lexema) {
  while (isalpha(expression[index]) && expression[index] != 'x') index++;
  string lexema = expression.substr(begin_lexema, index - begin_lexema);
  type unary = OPERATION_1_OPERAND;
  if (lexema == "cos" || lexema == "sin" || lexema == "tan" ||
      lexema == "acos" || lexema == "asin" || lexema == "atan" ||
      lexema == "sqrt" || lexema == "ln" || lexema == "log") {
  } else if (lexema == "mod") {
    unary = OPERATION_2_OPERAND;
  } else {
    throw invalid_argument("invalid operation symbol " + to_string(index));
  }
  lexems_.push_back({lexema, unary});
}

void CalculatorModel::OperationsGrammarCheck(int& index,
                                             const string& expression,
                                             const int& begin_lexema) {
  type unary = OPERATION_1_OPERAND;
  if ((index == 0 || expression[index - 1] == '(' ||
       (lexems_.back().unary == OPERATION_1_OPERAND) ||
       (lexems_.back().unary == OPERATION_2_OPERAND &&
        expression[index - 1] != ')')) &&
      (expression[index] == '+' || expression[index] == '-')) {
  } else {
    unary = OPERATION_2_OPERAND;
  }
  index++;
  lexems_.push_back(
      {expression.substr(begin_lexema, index - begin_lexema), unary});
}

void CalculatorModel::SemanticParser() {
  int CountBracket = 0;
  int SizeVector = this->lexems_.size();
  for (int i = 0; i < SizeVector; i++) {
    if (lexems_[i].unary == OPERATION_1_OPERAND) {
      if (i == SizeVector - 1)
        throw domain_error(
            "Унарный оператор не может быть последним элементом символ " +
            to_string(i));
    } else if (lexems_[i].unary == OPERATION_2_OPERAND) {
      if (lexems_[i].value == "(") {
        CheckOpenBrackets(i);
        CountBracket++;
      } else if (lexems_[i].value == ")") {
        CheckClosingBrackets(i);
        CountBracket--;
      } else {
        CheckUnaryTwo(i);
      }
    } else if (lexems_[i].unary == NUMBER) {
      CheckNumber(i);
    }
    if (CountBracket < 0) {
      throw domain_error(
          "Количество закрывающих скобок больше чем открывающих символ " +
          to_string(i));
    }
  }
  if (CountBracket != 0) {
    throw domain_error("Количество открывающих и закрывающих скобок различное");
  }
}

void CalculatorModel::CheckOpenBrackets(const int& index) const {
  if (lexems_[index + 1].unary == OPERATION_2_OPERAND &&
      lexems_[index + 1].value != "(") {
    throw domain_error(
        "После открывающей скобки из бинарных операторов может быть только "
        "открывающая скобка символ " +
        to_string(index));
  }
}

void CalculatorModel::CheckClosingBrackets(const int& index) const {
  if (index != 0) {
    if (lexems_[index - 1].unary == OPERATION_1_OPERAND ||
        (lexems_[index - 1].unary == OPERATION_2_OPERAND &&
         lexems_[index - 1].value != ")")) {
      throw domain_error(
          "Перед закрывающей скобкой может быть либо число либо другая скобка "
          "символ " +
          to_string(index));
    }
  }
  if (index != (int)lexems_.size() - 1) {
    if (lexems_[index + 1].unary == OPERATION_2_OPERAND) {
      if (lexems_[index + 1].value == "(") {
        throw domain_error(
            "После закрывающей скобки, открывающая скобка стоять не может "
            "символ " +
            to_string(index));
      }
    }
  }
}
void CalculatorModel::CheckUnaryTwo(const int& index) const {
  if (lexems_[index].value == "e" &&
      (lexems_[index + 1].unary != NUMBER && lexems_[index + 1].value != "(")) {
    throw domain_error(
        "После е может быть либо число ли открывающая скобка символ " +
        to_string(index));
  }
  if (index == 0 || index == (int)lexems_.size() - 1) {
    throw domain_error(
        "Кроме скобок бинарные операторы не могут стоять в начале и конце");
  } else {
    if (lexems_[index - 1].unary == OPERATION_1_OPERAND ||
        (lexems_[index - 1].unary == OPERATION_2_OPERAND &&
         lexems_[index - 1].value != ")")) {
      throw domain_error(
          "Перед бинарным оператором может стоять либо число либо "
          "закрывающая "
          "скобка символ " +
          to_string(index));
    }
    if (lexems_[index + 1].unary == OPERATION_2_OPERAND &&
        lexems_[index + 1].value != "(") {
      throw domain_error(
          "После бинарного оператора могут стоять числа унарные операторы и "
          "открывающая скобка символ " +
          to_string(index));
    }
  }
}

void CalculatorModel::CheckNumber(const int& index) const {
  if (index != (int)lexems_.size() - 1) {
    if (lexems_[index + 1].value == "(" ||
        lexems_[index + 1].unary == OPERATION_1_OPERAND) {
      throw domain_error(
          "После числа не может стоять унарный оператор или открывающая "
          "скобка символ " +
          to_string(index));
    }
  }
  if (index != 0 && lexems_[index - 1].value == ")") {
    throw domain_error("Перед числом не может стоять закрывающая скобка " +
                       to_string(index));
  }
}

double CalculatorModel::CalculateExpression() noexcept {
  std::setlocale(LC_ALL, "en_US.UTF-8");
  for (lexem index : lexems_) {
    if (index.unary == NUMBER && index.value == "x") {
      stack_numbers_.push(x_value_);
    } else if (index.unary == NUMBER) {
      stack_numbers_.push(std::stod(index.value));
    } else {
      int priority = 0;
      GivePriority(priority, index);
      if (stack_operations_.empty() || index.value == "(" ||
          (stack_operations_.top().name_operation == "(" &&
           index.value != ")")) {
        stack_operations_.push({index.value, index.unary, priority});
      } else if (index.value == ")") {
        while (stack_operations_.top().name_operation != "(") {
          DoOperation();
          stack_operations_.pop();
        }
        stack_operations_.pop();
      } else if (priority > stack_operations_.top().priority) {
        stack_operations_.push({index.value, index.unary, priority});
      } else if (priority == stack_operations_.top().priority) {
        if (priority == 3) {
          stack_operations_.push({index.value, index.unary, priority});
        } else {
          DoOperation();
          stack_operations_.pop();
          stack_operations_.push({index.value, index.unary, priority});
        }
      } else if (priority < stack_operations_.top().priority) {
        DoOperation();
        stack_operations_.pop();
        while (!stack_operations_.empty() &&
               priority <= stack_operations_.top().priority) {
          DoOperation();
          stack_operations_.pop();
        }
        stack_operations_.push({index.value, index.unary, priority});
      }
    }
  }
  while (stack_operations_.empty() == false) {
    DoOperation();
    stack_operations_.pop();
  }
  this->calculation_result_ = stack_numbers_.top();
  stack_numbers_.pop();
  lexems_.clear();
  return this->calculation_result_;
}

void CalculatorModel::GivePriority(int& priority,
                                   const lexem& index) const noexcept {
  if (index.unary == 1 || index.value == "^" || index.value == "e") {
    priority = 3;
  } else if (index.unary == 2 && (index.value == "+" || index.value == "-")) {
    priority = 1;
  } else if (index.value == "*" || index.value == "/" || index.value == "mod") {
    priority = 2;
  }
}

void CalculatorModel::DoOperation() noexcept {
  if (stack_operations_.top().unary == 1) {
    DoUnaryOperation(stack_operations_.top().name_operation);
  } else {
    double second_value = stack_numbers_.top();
    stack_numbers_.pop();
    DoBinaryOperation(stack_operations_.top().name_operation, second_value);
  }
}

void CalculatorModel::DoUnaryOperation(const string& unary_operation) noexcept {
  if (unary_operation == "+") {
    stack_numbers_.top() *= 1;
  } else if (unary_operation == "-") {
    stack_numbers_.top() *= -1;
  } else if (unary_operation == "cos") {
    stack_numbers_.top() = cos(stack_numbers_.top());
  } else if (unary_operation == "sin") {
    stack_numbers_.top() = sin(stack_numbers_.top());
  } else if (unary_operation == "tan") {
    stack_numbers_.top() = tan(stack_numbers_.top());
  } else if (unary_operation == "acos") {
    stack_numbers_.top() = acos(stack_numbers_.top());
  } else if (unary_operation == "asin") {
    stack_numbers_.top() = asin(stack_numbers_.top());
  } else if (unary_operation == "atan") {
    stack_numbers_.top() = atan(stack_numbers_.top());
  } else if (unary_operation == "sqrt") {
    stack_numbers_.top() = sqrt(stack_numbers_.top());
  } else if (unary_operation == "ln") {
    stack_numbers_.top() = log(stack_numbers_.top());
  } else if (unary_operation == "log") {
    stack_numbers_.top() = log10(stack_numbers_.top());
  }
}

void CalculatorModel::DoBinaryOperation(const string& binary_operation,
                                        const double& second_value) noexcept {
  if (binary_operation == "+") {
    stack_numbers_.top() += second_value;
  } else if (binary_operation == "-") {
    stack_numbers_.top() -= second_value;
  } else if (binary_operation == "*") {
    stack_numbers_.top() *= second_value;
  } else if (binary_operation == "/") {
    stack_numbers_.top() /= second_value;
  } else if (binary_operation == "^") {
    stack_numbers_.top() = pow(stack_numbers_.top(), second_value);
  } else if (binary_operation == "mod") {
    stack_numbers_.top() = std::fmod(stack_numbers_.top(), second_value);
  } else if (binary_operation == "e") {
    stack_numbers_.top() *= pow(10, second_value);
  }
}

string CalculatorModel::TakeResult(const string& expression,
                                   const string& x_value) {
  try {
    GrammarParser(expression, x_value);
    SemanticParser();
    double result_expression = CalculateExpression();
    return std::to_string(result_expression);
  } catch (invalid_argument& invalid_argument_expression) {
    lexems_.clear();
    return invalid_argument_expression.what();
  } catch (domain_error& domain_error_expression) {
    lexems_.clear();
    return domain_error_expression.what();
  }
}
}  // namespace s21
