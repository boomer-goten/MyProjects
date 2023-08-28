// Конвертация децимал числа в тип флоат
#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  char d[BUF] = {'\0'};
  dec_to_string(&src, d);
  *dst = atof(d);
  return 0;
}
