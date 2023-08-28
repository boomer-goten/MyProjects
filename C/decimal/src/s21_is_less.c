// Сравнивает децимал числа, если src меньше числа dst возвращает 1 во
// всех других случаях 0
#include "s21_decimal.h"

int s21_is_less(s21_decimal src, s21_decimal dst) {
  int status = 0;
  char d[BUF] = {'\0'};
  dec_to_string(&src, d);
  char d1[BUF];
  dec_to_string(&dst, d1);
  if (src.bits[0] == 0 && src.bits[1] == 0 && src.bits[2] == 0 &&
      dst.bits[0] == 0 && dst.bits[1] == 0 && dst.bits[2] == 0) {
  } else if ((checkbit(src.bits[3], 31)) == 0 &&
             (checkbit(dst.bits[3], 31)) == 1) {
  } else if ((checkbit(src.bits[3], 31)) == 1 &&
             (checkbit(dst.bits[3], 31)) == 0) {
    status = 1;
  } else {
    char *ukaz_src = d;
    char *ukaz_dst = d1;
    int chet_do_t_src = 0;
    int chet_do_t_dst = 0;
    while (*ukaz_src != '.' && *ukaz_src != '\0') {
      chet_do_t_src++;
      ukaz_src++;
    }
    while (*ukaz_dst != '.' && *ukaz_dst != '\0') {
      chet_do_t_dst++;
      ukaz_dst++;
    }
    if (chet_do_t_src < chet_do_t_dst) {
      if (checkbit(src.bits[3], 31) == 1) {
        status = 0;
      } else {
        status = 1;
      }
    } else if (chet_do_t_src == chet_do_t_dst) {
      int count = 0;
      while (d[count] != '\0' && d1[count] != '\0') {
        int a = char_to_int(d[count]);
        int b = char_to_int(d1[count]);
        if ((a > b && ((checkbit(src.bits[3], 31)) == 0)) ||
            (a < b && ((checkbit(src.bits[3], 31)) == 1))) {
          status = 0;
          break;
        } else if ((a > b && (checkbit(src.bits[3], 31)) == 1) ||
                   (a < b && (checkbit(src.bits[3], 31)) == 0)) {
          status = 1;
          break;
        }
        count++;
      }
      if (d[count] == '\0' || d1[count] == '\0') {
        if ((d1[count] == '\0' && (checkbit(src.bits[3], 31)) == 0) ||
            (d[count] == '\0' && (checkbit(src.bits[3], 31)) == 1)) {
          status = 0;
        } else if ((d1[count] == '\0' && (checkbit(src.bits[3], 31)) == 1) ||
                   (d[count] == '\0' && (checkbit(src.bits[3], 31)) == 0)) {
          if (d[count] == '.' || d1[count] == '.') {
            count++;
            if (d[count] == '\0') {
              while (d1[count] != '\0') {
                if (d1[count] != '0') {
                  status = 1;
                  break;
                }
                count++;
                status = 0;
              }
            } else if (d1[count] == '\0') {
              while (d[count] != '\0') {
                if (d[count] != '0') {
                  status = 1;
                  break;
                }
                count++;
                status = 0;
              }
            }
          }
        }
      }
    }
  }
  return status;
}