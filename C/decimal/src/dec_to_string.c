#include "./s21_decimal.h"

#define PERIOD_START 16
#define PERIOD_END 23

int exp_string(char *result, int degree);
int period_calc(int a);

int dec_to_string(s21_decimal *a, char *main_result) {
  size_t len = sizeof(int) * CHAR_BIT;
  int period = 0;
  char result[BUF], mid_result[BUF];
  memset(result, '\0', BUF);
  memset(mid_result, '\0', BUF);
  memset(main_result, '\0', BUF);
  period = period_calc(a->bits[3]);
  result[0] = '0';
  mid_result[0] = '0';
  int degree = -1;
  for (int i = 0; i < 3; i++) {
    for (size_t j = 0; j < len; j++) {
      memset(mid_result, '\0', BUF);
      degree++;
      if (checkbit(a->bits[i], j) == 1) {
        exp_string(mid_result, degree);
        summ_two_string(result, mid_result, result);
      }
    }
  }

  // Добавить в конец массива недостающие нули
  while ((int)strlen(result) < period) {
    result[strlen(result)] = '0';
  }

  // Добавить точку в число
  if (period > 0) {
    dot_insert(result, period);
  }
  // Добавить знак
  if (checkbit(a->bits[3], MAX_INT_SHIFT) == 1) {
    result[strlen(result)] = '-';
  }
  // Развернуть массив
  revers(result, strlen(result));
  strcpy(main_result, result);
  return EXIT_SUCCESS;
}

// Возведение строки в степень degree
int exp_string(char *result, int degree) {
  result[0] = '2';
  if (degree == 0)
    result[0] = '1';
  else if (degree == 1) {
    result[0] = '2';
  } else
    for (int i = 0; i < (degree - 1); i++) {
      mult_by_2(result, result);
    }
  return EXIT_SUCCESS;
}

// Подсчёт количества знаков в числе
int period_calc(int a) {
  int result = 0;
  for (int i = PERIOD_START, j = 0; i <= PERIOD_END; i++, j++) {
    if (checkbit(a, i) == 1) {
      result = pow(2, j) + result;
    }
  }
  return result;
}
