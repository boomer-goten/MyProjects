// Функция записывает степень в децимал
// На вход подается число степень с типом инт и записывает необходимую степень в
// децимал
// Функция не обрабатывает числа превышающая степень 28, просто ничего
// не запишется
//
#include "s21_decimal.h"

void zapis_stepeni_v_decimal(const unsigned int a, s21_decimal *dst) {
  int znak = 0;
  if (checkbit(dst->bits[3], 31)) {
    znak = 1;
  }
  if (dst->bits[3] != 0) {
    dst->bits[3] = 0;
  }
  if (a <= 28) {
    dst->bits[3] |= (a << 16);
  }
  if (znak == 1) {
    dst->bits[3] |= SIGN;
  }
}
