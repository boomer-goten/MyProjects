#include "s21_decimal.h"

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  for (int i = 0; i < 4; i++) result->bits[i] = 0;
  str_decimal val_1, val_2, res;
  s21_dec_to_str_dec(value_1, &val_1);
  s21_dec_to_str_dec(value_2, &val_2);
  int err = dec_str_mod(&val_1, &val_2, &res);
  if (!err) {
    str_dec_to_s21_dec(res, result);
  }
  return err;
}