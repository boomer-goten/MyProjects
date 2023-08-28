// Сравнивает децимал числа, если src меньше или равно числу dst возвращает 1 во
// всех других случаях 0
#include "s21_decimal.h"

int s21_is_less_or_equal(s21_decimal src, s21_decimal dst) {
  int status = 0;
  if (s21_is_less(src, dst) == 1 || s21_is_equal(src, dst) == 1) {
    status = 1;
  }
  return status;
}