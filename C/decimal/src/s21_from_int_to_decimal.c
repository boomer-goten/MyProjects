// Конвертация числа типа инт в тиц децимал
#include "./s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if ((src & (1 << MAX_INT_SHIFT)) != 0) {
    dst->bits[0] = ~src + 1;
    dst->bits[3] |= SIGN;
  } else {
    dst->bits[0] |= src;
  }
  return 0;
}
