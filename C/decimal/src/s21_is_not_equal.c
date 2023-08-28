// Сравнивает децимал числа на равенства при равенсте 0 при неравенстве 1
#include "s21_decimal.h"

int s21_is_not_equal(s21_decimal src, s21_decimal dst) {
  int status = 0;
  char d[BUF] = {'\0'};
  dec_to_string(&src, d);
  char d1[BUF] = {'\0'};
  dec_to_string(&dst, d1);
  if (src.bits[0] == 0 && src.bits[1] == 0 && src.bits[2] == 0 &&
      dst.bits[0] == 0 && dst.bits[1] == 0 && dst.bits[2] == 0) {
  } else {
    char *ukaz_first = d;
    char *ukaz_second = d1;
    while (*ukaz_first != '\0' && *ukaz_second != '\0') {
      if (*ukaz_first != *ukaz_second) {
        status = 1;
        break;
      }
      ukaz_first++;
      ukaz_second++;
    }
    char *ukaz_tmp = NULL;
    if (*ukaz_first != '\0' || *ukaz_second != '\0') {
      if (*ukaz_first == '\0') {
        ukaz_tmp = ukaz_second;
      } else {
        ukaz_tmp = ukaz_first;
      }
      if (*ukaz_tmp == '.') {
        ukaz_tmp++;
        while (*ukaz_tmp != '\0') {
          if (*ukaz_tmp != '0') {
            status = 1;
            break;
          }
          ukaz_tmp++;
          status = 0;
        }
      }
    } else {
      status = 0;
    }
  }
  return status;
}
