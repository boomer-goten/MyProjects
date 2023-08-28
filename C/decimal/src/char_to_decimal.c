/* Функция char_to_decimal(char *string).
 * Конвертирует строку, в которую записано число в число с типом decimal.
 * Важно разделитель дробной части должен быть записан в виде "."
 * Если количество разрядов после "." будет больше 28, переполнения не
 * произойдет, просто обрежется лишняя часть без округления.
 * Если подать число, которое при переводе в двоичную систему счисления не
 * поместится в структуру s21_decimal, то произойдет переполнение.
 */

#include "s21_decimal.h"

char *remove_sign(
    char *string,
    unsigned int *value);  // Проверяет наличие знака у числа в строке,
                           // записывает в байт структуру, удаляет из строки
char *find_point(const char *string);  // Поиск начала дробной части
void delete_point(
    char *string, unsigned int *value,
    char *p_point);  // Запись количества разрядов в байт структуры
// числа decimal и удаления точки из строки
void binary_conversion(
    char *string,
    s21_decimal *value);  // Перевод числа из десятичной системы счисления в
                          // двоичную и запись разрядов в структуре decimal

s21_decimal char_to_decimal(const char *str) {
  if (str == NULL) {
    fprintf(stderr, "char_to_decimal: Передан NULL вместо строки\n");
    exit(-1);
  }
  int len = strlen(str);
  char string[len + 1];
  memset(string, '\0', sizeof(char) * (len + 1));
  strncpy(string, str, len);
  char *string_ptr = string;
  s21_decimal result = {0};
  char *p_point = NULL;
  string_ptr = remove_sign(string_ptr, &result.bits[3]);
  if ((p_point = find_point(string_ptr)) != NULL) {
    delete_point(string_ptr, &result.bits[3], p_point);
  }
  binary_conversion(string_ptr, &result);
  return result;
}

char *remove_sign(char *string, unsigned int *value) {
  char *mass = string;
  if (*string == '-') {
    mass += 1;
    *value += 1;
    *value = *value << 31;
  }
  return mass;
}

char *find_point(const char *string) {
  char *p_point = NULL;
  char tmpmass[2] = ".";
  p_point = strstr(string, tmpmass);
  return p_point;
}

void delete_point(char *string, unsigned int *value, char *p_point) {
  size_t col = strlen(string) - (p_point - string) - 1;  // степень 10
  if (col > 28) {  // Ограничение на 28 разрядов, без округления числа
    col = 28;
  }
  *value = *value | (col << 16);
  char fractional_part[col + 1];  // Хранить дробную часть
  memset(fractional_part, '\0', col + 1);
  strncpy(fractional_part, (p_point + 1), col * sizeof(char));
  strncpy(p_point, fractional_part, (col + 1) * sizeof(char));
}

void binary_conversion(char *str, s21_decimal *value) {
  short len = 0;      // Длина str
  u_int32_t tmp = 0;  // Хранит двоичные цифры
  short val = 0;   // Цифра которую будут делить на 2
  short cnt1 = 0;  // Считает кол-во двоичных цифр
  short cnt2 = 0;  // Счетчик кол-ва int
  char *str1_ptr = str;   // Указатель частное
  char *str2_ptr = NULL;  // Указатель для перемещению по цифрам делимого
  u_int32_t bit = 0;      // Хранит один int

  while (cnt2 < 3) {
    len = strlen(str1_ptr) - 1;
    if (len == -1) {
      value->bits[cnt2] = bit;
      break;
    }
    str2_ptr = str1_ptr + len;
    if ((((int)str1_ptr[len]) % 2) == 0) {
      tmp = 0;
    } else {
      tmp = 1;
      str1_ptr[len] = ((str1_ptr[len] - '0') - 1 + '0');
    }

    while (str1_ptr - 1 != str2_ptr) {
      val = *str2_ptr - '0';
      if (str1_ptr != str2_ptr) {
        if ((*(str2_ptr - 1) - '0') % 2 == 1) {
          *(str2_ptr - 1) = (*(str2_ptr - 1) - '0') - 1 + '0';
          val += 10;
        }
      }
      *str2_ptr = val / 2 + '0';
      if (str1_ptr == str2_ptr) {
        if (*str1_ptr - '0' == 0) {
          str1_ptr++;
        }
        break;
      }
      str2_ptr--;
    }

    tmp = tmp << cnt1;
    bit = bit | tmp;
    cnt1++;
    if (cnt1 == 32) {
      cnt1 = 0;
      value->bits[cnt2] = bit;
      cnt2++;
      bit = 0;
    }
  }
}
