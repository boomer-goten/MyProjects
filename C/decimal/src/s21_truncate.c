//Возвращает целые цифры указанного Decimal числа; любые дробные цифры
//отбрасываются, включая конечные нули.

#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
  result->bits[3] = 0;
  int status = 0;
  char d[BUF] = {'\0'};
  dec_to_string(&value, d);
  char *ukaz = d;
  while (1) {
    if (*ukaz == '\0' || *ukaz == '.') {
      *ukaz = '\0';
      break;
    }
    ukaz++;
  }
  *result = char_to_decimal(d);
  return status;
}
