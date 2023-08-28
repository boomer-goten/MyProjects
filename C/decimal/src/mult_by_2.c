/* Функция mult_by_2(char *a, char *result).
 * Получает число, цифры которого записаны в виде строки и умножает его на 2.
 * Ответ возвращается в виде строки.
 */

#include "s21_decimal.h"

int mult_by_2(char *a, char *result) {
  int carry = 0;
  int interm = 0;
  size_t i = 0;
  for (; i < strlen(a); i++) {
    if ((interm = ((a[i] - '0') * 2 + carry)) > 9) {
      carry = 1;
    }
    result[i] = interm % 10 + 48;
    if (interm < 10) carry = 0;
  }
  if (carry > 0) result[i] = carry + 48;
  return EXIT_SUCCESS;
}