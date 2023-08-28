#include "s21_calc.h"

double parser_of_lexems(lexema* mass, int* front, int* rear, double x,
                        int* status) {
  number_t* head = NULL;
  operators_t* head_op = NULL;
  double tmp_value = 0;
  int count = 0;
  for (int i = *front; i <= *rear; i++) {
    if (mass[i].unarnost == 0 && !strcmp(mass[i].value, "x")) {
      push_num(&head, x);
    } else if (mass[i].unarnost == 0) {
      if (strchr(mass[i].value, '.') != NULL) {
        int cnt = 0;
        while (mass[i].value[cnt] != '\0') {
          if (mass[i].value[cnt] == '.') {
            mass[i].value[cnt] = ',';
            break;
          }
          cnt++;
        }
      }
      tmp_value = atof(mass[i].value);
      push_num(&head, tmp_value);
    } else {
      operator oper = {0};
      count = 0;
      while (mass[i].value[count] != '\0') {
        oper.operation[count] = mass[i].value[count];
        count++;
      }
      oper.unarnost = mass[i].unarnost;
      if (mass[i].unarnost == 1) {
        oper.prioritet = 3;
      } else if (mass[i].unarnost == 2 &&
                 (!strcmp(mass[i].value, "+") || !strcmp(mass[i].value, "-"))) {
        oper.prioritet = 1;
      } else if (mass[i].unarnost == 2 &&
                 (!strcmp(mass[i].value, "*") || !strcmp(mass[i].value, "/") ||
                  !strcmp(mass[i].value, "mod"))) {
        oper.prioritet = 2;
      } else if (mass[i].unarnost == 2 && !strcmp(mass[i].value, "^")) {
        oper.prioritet = 3;
      } else {
        oper.prioritet = 0;
      }
      if (stack_is_empty(head_op) == TRUE_CH || !strcmp(mass[i].value, "(")) {
        push_operation(&head_op, oper);
      } else {
        if (!strcmp(mass[i].value, ")")) {
          operators_t* oper_tmp = take_operation(&head_op);
          while (strcmp(oper_tmp->unit.operation, "(")) {
            do_oper(&head, oper_tmp->unit, status);
            free_op(&head_op);
            oper_tmp = take_operation(&head_op);
          }
          free_op(&head_op);
        } else {
          operators_t* tmp = take_operation(&head_op);
          if (!strcmp(tmp->unit.operation, "(")) {
            push_operation(&head_op, oper);
          } else {
            operators_t* oper_tmp = take_operation(&head_op);
            if (oper.unarnost == 1 && oper_tmp->unit.unarnost == 1) {
              push_operation(&head_op, oper);
            } else {
              if (oper.prioritet > oper_tmp->unit.prioritet) {
                push_operation(&head_op, oper);
              } else {
                if (oper_tmp->unit.unarnost == 1) {
                  while (oper_tmp->unit.unarnost == 1) {
                    do_oper(&head, oper_tmp->unit, status);
                    free_op(&head_op);
                    oper_tmp = take_operation(&head_op);
                    if (oper_tmp == NULL) break;
                  }
                } else {
                  do_oper(&head, oper_tmp->unit, status);
                  free_op(&head_op);
                }
                push_operation(&head_op, oper);
              }
            }
          }
        }
      }
    }
  }
  // print_num(head);
  // print_operations(head_op);
  if (*status == OK) {
    while (stack_is_empty(head_op) == FALSE_CH) {
      operators_t* oper_tmp = take_operation(&head_op);
      do_oper(&head, oper_tmp->unit, status);
      free_op(&head_op);
    }
  }
  // print_num(head);
  // if (stack_is_empty(head_op) == FALSE_CH) {
  //   print_operations(head_op);
  // } else {
  //   printf("stack is empty:)\n");
  // }
  double result = pop_num(&head);
  return result;
}