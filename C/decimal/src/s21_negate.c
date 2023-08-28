#include "./s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  s21_decimal_copy(value, result);
  if (checkbit(result->bits[3], MAX_INT_SHIFT) == 1) {
    result->bits[3] ^= SIGN;
  } else {
    result->bits[3] |= SIGN;
  }
  return EXIT_SUCCESS;
}
