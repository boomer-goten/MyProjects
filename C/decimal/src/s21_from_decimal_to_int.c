// Конвертация числа из типа децимал в тип инт
#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (dst == NULL) return 1;
  char d[BUF] = {'\0'};
  dec_to_string(&src, d);
  *dst = atoi(d);
  return 0;
}
