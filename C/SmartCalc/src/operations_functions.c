#include "s21_calc.h"

int stack_is_empty(operators_t* head) {
  int status = TRUE_CH;
  if (head) {
    status = FALSE_CH;
  }
  return status;
}

void push_operation(operators_t** head, operator operation) {
  operators_t* tmp = malloc(sizeof(operators_t));
  if (tmp == NULL) {
    exit(1);
  }
  tmp->next = *head;
  tmp->unit = operation;
  *head = tmp;
}

operators_t* take_operation_del(operators_t** head) {
  operators_t* out;
  if ((*head) == NULL) {
    exit(1);
  }
  out = *head;
  *head = (*head)->next;
  return out;
}

operators_t* take_operation(operators_t** head) {
  operators_t* out;
  // if ((*head) == NULL) {
  //   exit(1);
  // }
  out = *head;
  return out;
}

void print_operations(operators_t* head) {
  while (head) {
    printf("%s ", head->unit.operation);
    head = head->next;
  }
  printf("\n");
}

void free_op(operators_t** head) {
  operators_t* out;
  if (*head == NULL) {
    exit(1);
  }
  out = *head;
  *head = (*head)->next;
  free(out);
}