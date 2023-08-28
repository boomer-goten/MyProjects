#include "s21_calc.h"

void do_oper_1(number_t* head, operator operation) {
  if (!strcmp(operation.operation, "+")) {
    head->unit *= 1;
  } else if (!strcmp(operation.operation, "-")) {
    head->unit *= -1;
  } else if (!strcmp(operation.operation, "cos")) {
    head->unit = cos(head->unit);
  } else if (!strcmp(operation.operation, "sin")) {
    head->unit = sin(head->unit);
  } else if (!strcmp(operation.operation, "tan")) {
    head->unit = tan(head->unit);
  } else if (!strcmp(operation.operation, "acos")) {
    head->unit = acos(head->unit);
  } else if (!strcmp(operation.operation, "asin")) {
    head->unit = asin(head->unit);
  } else if (!strcmp(operation.operation, "atan")) {
    head->unit = atan(head->unit);
  } else if (!strcmp(operation.operation, "sqrt")) {
    head->unit = sqrt(head->unit);
  } else if (!strcmp(operation.operation, "ln")) {
    head->unit = log(head->unit);
  } else if (!strcmp(operation.operation, "log")) {
    head->unit = log10(head->unit);
  }
}

void do_oper_2(number_t* head, operator operation, double tmp, int* status) {
  if (!strcmp(operation.operation, "+")) {
    head->unit += tmp;
  } else if (!strcmp(operation.operation, "-")) {
    head->unit -= tmp;
  } else if (!strcmp(operation.operation, "*")) {
    head->unit *= tmp;
  } else if (!strcmp(operation.operation, "/")) {
    head->unit /= tmp;
  } else if (!strcmp(operation.operation, "^")) {
    head->unit = pow(head->unit, tmp);
  } else if (!strcmp(operation.operation, "mod")) {
    if (fabs(head->unit) - labs((long int)head->unit) < 1e-7 &&
        fabs(tmp) - labs((long int)tmp) < 1e-7) {
      head->unit = (long int)head->unit % (long int)tmp;
    } else {
      *status = BAD_EXPRESSION;
    }
  }
}

void do_oper(number_t** head, operator operation, int* status) {
  if (operation.unarnost == 1) {
    do_oper_1(*head, operation);
  } else {
    double tmp = pop_num(head);
    do_oper_2(*head, operation, tmp, status);
  }
}
