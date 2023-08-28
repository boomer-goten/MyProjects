#ifndef CALC_HEADERS_CALCULATORMODEL_H_
#define CALC_HEADERS_CALCULATORMODEL_H_

#include <clocale>
#include <cmath>
#include <cstdarg>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

using std::domain_error;
using std::invalid_argument;
using std::isalpha;
using std::isdigit;
using std::stack;
using std::string;
using std::to_string;
using std::vector;

namespace s21 {
class CalculatorModel {
 public:
  CalculatorModel() : calculation_result_(0), x_value_(0){};
  ~CalculatorModel(){};
  string TakeResult(const string& expression, const string& x_value);

 private:
  enum type { NUMBER, OPERATION_1_OPERAND, OPERATION_2_OPERAND };

  // structure of one lexem
  struct lexem {
    string value;
    // unary = 0 -> работаем с числом
    // unary = 1 -> нужен один операнд
    // unary = 2 -> нужно два операнда
    type unary;
    lexem(string values, type type_unary) : value(values), unary(type_unary){};
  };

  struct operation {
    string name_operation;
    type unary;
    // priority = 3 все унарные операции и "^", "e".
    // priority = 2 у "*" "/" "mod"
    // priority = 1 у бинарных "+" "-"
    int priority;
    operation(string operation, type type_unary, int prioritys)
        : name_operation(operation), unary(type_unary), priority(prioritys){};
  };
  double calculation_result_;
  double x_value_;
  vector<lexem> lexems_;
  stack<double> stack_numbers_;
  stack<operation> stack_operations_;

  bool CheckXValue(const string& xValue);

  // для грамматического анализа слова используется метод рекурсивного спуска
  // выражения
  void GrammarParser(const string& expression, const string& xValue);
  // грамматическая обработка числа и x
  void NumberGrammarCheck(int& index, const string& expression,
                          const int& begin_lexema);
  // Обработка функций типа log, sin и т.д.
  void FunctionGrammarCheck(int& index, const string& expression,
                            const int& begin_lexema);
  // Обработка +, - и т.д.
  void OperationsGrammarCheck(int& index, const string& expression,
                              const int& begin_lexema);

  // семантический анализ выражения. Поиск математических логических ошибок
  void SemanticParser();

  // Семантическая обработка отдельных лексем
  void CheckOpenBrackets(const int& index) const;
  void CheckClosingBrackets(const int& index) const;
  void CheckUnaryTwo(const int& index) const;
  void CheckNumber(const int& index) const;

  double CalculateExpression() noexcept;
  // calculate helper methods
  void GivePriority(int& priority, const lexem& index) const noexcept;
  void DoOperation() noexcept;
  void DoUnaryOperation(const string& unary_operation) noexcept;
  void DoBinaryOperation(const string& binary_operation,
                         const double& second_value) noexcept;
};
}  // namespace s21

#endif  // CALC_HEADERS_CALCULATORMODEL_H_
