#include "s21_calc.h"

int parser_of_expression(char* expression, char* x_str, double* result) {
  int front = -1;
  int rear = -1;
  lexema* mass = (lexema*)malloc(256 * sizeof(lexema));
  int status = OK;
  double x = 0;
  if (x_str[0] == '\0' && strchr(expression, 'x') != NULL) {
    status = X;
  } else {
    status = double_is_true_for_x(x_str, &x);
  }
  int size = strlen(expression);
  int unarnost = OPERATION_2;
  char tmp[48];
  int j = 0;
  for (int i = 0; i < size;) {
    lexema uni;
    memset(tmp, '\0', 48);
    j = 0;
    if (expression[i] >= '0' && expression[i] <= '9') {
      unarnost = CHISLO;
      int count_tochka = 0;
      while ((expression[i] >= '0' && expression[i] <= '9') ||
             expression[i] == '.') {
        if (expression[i] == '.') count_tochka++;
        tmp[j] = expression[i];
        i++;
        j++;
        if (count_tochka > 1) {
          status = BAD_EXPRESSION;
          break;
        }
      }
    } else if (expression[i] == 'x') {
      unarnost = CHISLO;
      tmp[j] = expression[i];
      i++;
      j++;
    } else if (expression[i] == 'm' || expression[i] == 'c' ||
               expression[i] == 's' || expression[i] == 't' ||
               expression[i] == 'a' || expression[i] == 'l') {
      while (expression[i] >= 'a' && expression[i] <= 'w') {
        tmp[j] = expression[i];
        i++;
        j++;
      }
      if (!strcmp(tmp, "cos") || !strcmp(tmp, "sin") || !strcmp(tmp, "tan") ||
          !strcmp(tmp, "acos") || !strcmp(tmp, "asin") ||
          !strcmp(tmp, "atan") || !strcmp(tmp, "sqrt") || !strcmp(tmp, "ln") ||
          !strcmp(tmp, "log")) {
        unarnost = OPERATION_1;
      } else if (!strcmp(tmp, "mod")) {
        unarnost = OPERATION_2;
      } else {
        status = BAD_EXPRESSION;
      }
    } else if (expression[i] == '(' || expression[i] == ')' ||
               expression[i] == '+' || expression[i] == '-' ||
               expression[i] == '*' || expression[i] == '/' ||
               expression[i] == '^') {
      tmp[j] = expression[i];
      if ((i == 0 || expression[i - 1] == '(' ||
           (unarnost == OPERATION_1 && expression[i - 1] != '+' &&
            expression[i - 1] != '-') ||
           (unarnost == OPERATION_2 && expression[i - 1] != ')')) &&
          (expression[i] == '+' || expression[i] == '-')) {
        unarnost = OPERATION_1;
      } else {
        unarnost = OPERATION_2;
      }
      i++;
    } else {
      status = BAD_EXPRESSION;
      break;
    }
    int count = 0;
    while (tmp[count] != '\0') {
      uni.value[count] = tmp[count];
      count++;
    }
    uni.value[count] = '\0';
    uni.unarnost = unarnost;
    if (status == OK) {
      push_lex(uni, mass, &front, &rear);
    }
  }
  // print_lex(mass, &front, &rear);
  if (status == OK) {
    status = check_lexems(mass, &front, &rear);
    if (status == OK) {
      *result = parser_of_lexems(mass, &front, &rear, x, &status);
    }
  }
  free(mass);
  return status;
}

// int main() {
//   char* x = "100";
//   double result = 0;
//   int status = OK;
//   // char primer[] = "-logx+10*2+lnx+(2*4)-12+lnx+2^4-12+2*x";
//   char primer[] = "-logx+2";
//   status = parser_of_expression(primer, x, &result);
//   printf("status=%d\n", status);
//   printf("result=%lf\n", result);
// }