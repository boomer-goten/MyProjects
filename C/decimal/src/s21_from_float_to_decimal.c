//Конвертация числа флоат в тип децимал
#include "./s21_decimal.h"

void slozhenie(s21_decimal *dst, int exponent) {
  if (exponent >= 64) {
    if ((dst->bits[2] & 1 << (exponent - 64)) == 0) {
      dst->bits[2] |= 1 << (exponent - 64);
    } else {
      dst->bits[2] -= pow(2, (exponent - 64));
      exponent += 1;
      slozhenie(dst, exponent);
    }
  } else if (exponent >= 32) {
    if ((dst->bits[1] & 1 << (exponent - 32)) == 0) {
      dst->bits[1] |= 1 << (exponent - 32);
    } else {
      dst->bits[1] -= pow(2, (exponent - 32));
      exponent += 1;
      slozhenie(dst, exponent);
    }
  } else {
    if ((dst->bits[0] & 1 << exponent) == 0) {
      dst->bits[0] |= 1 << exponent;
    } else {
      dst->bits[0] -= pow(2, exponent);
      exponent += 1;
      slozhenie(dst, exponent);
    }
  }
}

// Обрабатывает если флот содержит меньше 8 цифр
void obrabotka_chisel_menshe_vosmi(s21_decimal *dst, s21_decimal tmp,
                                   s21_decimal tmp1, char *float_string) {
  int count = 0;
  int i = 2;
  int flag = 0;
  char vosmoy_symbol = '0';
  while (float_string[i] != '\0') {
    if (float_string[i] != '0') {
      flag = 1;
    }
    if (flag == 1) {
      count++;
    }
    if (count == 8) {
      vosmoy_symbol = float_string[i];
      break;
    }
    i++;
  }
  tmp = char_to_decimal(float_string);
  tmp1 = tmp;
  char result[BUF] = {'\0'};
  float_string[i] = '\0';
  tmp1 = char_to_decimal(float_string);
  if (vosmoy_symbol >= '5') {
    slozhenie(&tmp1, 0);
  }
  dec_to_string(&tmp1, result);
  *dst = char_to_decimal(result);
}

// Обрабатывает если флот содержит больше 8 цифр
void obrabotka_chisel_bolshe_vosmi(s21_decimal *dst, s21_decimal tmp,
                                   s21_decimal tmp1, char *result,
                                   char *float_string) {
  char *ukaz = float_string;
  int count = 0;
  int position = 1000;
  char position_char = '0';
  char after_point[BUF];
  while (*ukaz != '\0') {
    if (*ukaz == '.') {
      // Узнаем позицию точки
      position = count;
      ukaz++;
      continue;
    }
    ukaz++;
    count++;
    if (count == 7) {
      break;
    }
  }
  if (position < 7) {
    position_char = *ukaz;
    *ukaz = '\0';
  } else {
    char *ukaz = &float_string[7];
    int count_after_point = 0;
    while (*ukaz != '\0') {
      if (*ukaz == '.') {
        break;
      }
      count_after_point++;
      ukaz++;
    }
    memset(after_point, '\0', sizeof(after_point));
    int i = 0;
    for (; i < count_after_point; i++) {
      after_point[i] = '0';
    }
    after_point[i] = '\0';
    position_char = float_string[7];
    if (position_char == '.') {
      position_char = float_string[8];
    }
    float_string[7] = '\0';
  }
  tmp = char_to_decimal(float_string);
  tmp1 = tmp;
  if (position_char >= '5') {
    slozhenie(&tmp1, 0);
  }
  dec_to_string(&tmp1, result);
  if (position >= 7) {
    strcat(result, after_point);
  }
  *dst = char_to_decimal(result);
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int status = 0;
  dst->bits[0] = 0;
  dst->bits[1] = 0;
  dst->bits[2] = 0;
  dst->bits[3] = 0;
  s21_decimal tmp = {0};
  s21_decimal tmp1 = {0};
  if (fabs(src) >= 1e-28 && src != INFINITY && fabs(src) <= MAX_DECIMAL) {
    int minus_flag = 0;
    if (src < 0) {
      minus_flag = 1;
      src = fabs(src);
    }
    char float_string[BUF] = {'\0'};
    char result[BUF] = {'\0'};
    sprintf(float_string, "%.22f", src);
    if (strlen(float_string) > 8 && strchr(float_string, '.') != NULL &&
        float_string[0] != '0') {
      obrabotka_chisel_bolshe_vosmi(dst, tmp, tmp1, result, float_string);
    } else if (float_string[0] == '0' && float_string[1] == '.') {
      obrabotka_chisel_menshe_vosmi(dst, tmp, tmp1, float_string);
    }
    if (minus_flag == 1) {
      dst->bits[3] |= SIGN;
    }
  } else {
    status = 1;
  }
  return status;
}
