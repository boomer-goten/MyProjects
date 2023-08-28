#include "./s21_decimal.h"

// Переворот массива. На вход подаётся строка и его размер
// Можно вызывать в виде reverse(string, (int)strlen(string))

void revers(char *src, int size) {
  int count = size;
  for (int i = 0; i < size / 2; i++) {
    char buff = src[i];
    src[i] = src[--count];
    src[count] = buff;
  }
}

// Сложение двух строк. В функцию передаётся 3 массива

int summ_two_string(char *num1, char *num2, char *result) {
  int res = 0;
  size_t i = 0;
  int carry = 0;
  for (; i < max_lenght(num1, num2); i++) {
    if ((res = char_to_int(num1[i]) + char_to_int(num2[i]) + carry) > 9) {
      carry = (res - res % 10) / 10;
    }
    result[i] = res % 10 + 48;
    if (res < 10) carry = 0;
  }
  if (carry > 0) result[i] = carry + 48;
  return EXIT_SUCCESS;
}

// Сравнение двух строк и возврат наибольшей длины

size_t max_lenght(char *num1, char *num2) {
  return (strlen(num1) >= strlen(num2)) ? strlen(num1) : strlen(num2);
}

// Перевод ascii символа в целочисленный int для совершения математических
// операций

int char_to_int(char a) { return (a <= '9' && a >= '0') ? a - '0' : 0; }

/*
    Вставка в строку точки, разделяющей целое и десятичную часть.
    СТРОКА ОБЯЗАТЕЛЬНО ДОЛЖНА БЫТЬ ПЕРЕДАНА ЗАДОМ НАПЕРЁД
    Функция перезаписывает новую строку в результат.
    В качестве аргумента передаётся строка и количество символов,
    которое должно быть за точкой.
    Period_length должен быть на единицу больше, чем фактическое
    количество знаков за запятой.
*/

void dot_insert(char *result, int period_length) {
  char temp[BUF] = {'\0'};
  int i = 0;
  if (period_length > 0) {
    for (; i < period_length; i++) {
      temp[i] = result[i];
    }
    temp[i] = '.';
    for (; i < (int)strlen(result); i++) {
      temp[i + 1] = result[i];
    }
    if (temp[i] == '.') temp[i + 1] = '0';
    memset(result, '\0', BUF);
    strcpy(result, temp);
  }
}

int s21_decimal_copy(s21_decimal src, s21_decimal *dest) {
  for (int i = 0; i < 4; i++) {
    dest->bits[i] = src.bits[i];
  }
  return EXIT_SUCCESS;
}
