#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  for (int i = 0; i < 4; i++) result->bits[i] = 0;
  str_decimal v1, v2, res;
  s21_dec_to_str_dec(value_1, &v1);
  s21_dec_to_str_dec(value_2, &v2);
  v2.sign = (v2.sign + 1) % 2;  // меняем знак при вычитании
  int err = dec_str_universal_add_sub(v1, v2, &res);
  if (!err) {
    str_dec_to_s21_dec(res, result);
  }
  return err;
}