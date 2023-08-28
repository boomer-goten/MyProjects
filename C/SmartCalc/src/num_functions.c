#include "s21_calc.h"

void push_num(number_t** head, double value) {
  number_t* tmp = (number_t*)malloc(sizeof(number_t));
  if (tmp == NULL) {
    exit(1);
  }
  tmp->next = *head;
  tmp->unit = value;
  *head = tmp;
}

void print_num(number_t* head) {
  while (head) {
    printf("%lf ", head->unit);
    head = head->next;
  }
  printf("\n");
}

double pop_num(number_t** head) {
  if (*head == NULL) {
    exit(1);
  }
  number_t* out = *head;
  *head = (*head)->next;
  double value = out->unit;
  free(out);
  return value;
}