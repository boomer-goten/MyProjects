#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIGN 0x80000000
#define MAX_INT_SHIFT 31
#define BUF 1024
#define MAX_DECIMAL 79228162514264337593543950335.0
#define MIN_DECIMAL -79228162514264337593543950335.0

#define MAX_DECIMAL_STR "79228162514264337593543950335"
#define MIN_DECIMAL_STR "-79228162514264337593543950335"

#define SUCCESS 0
#define FAILURE 1
#define LARGE 1
#define SMALL 2
#define BIG 3
#define POSITIVE 0
#define NEGATIVE 1

typedef unsigned int u_int32_t;

typedef struct {
  u_int32_t bits[4];
} s21_decimal;

// Функция для вывода числа decimal в битовом отображении
int bit_output(s21_decimal* a);
// Функция для перевода числа int в decimal
int s21_from_int_to_decimal(int src, s21_decimal* dst);

// Функция для конвертации decimal в строку
int dec_to_string(s21_decimal* a, char* result);
// Функция для копирования значения из одного deecimal в другой
int s21_decimal_copy(s21_decimal src, s21_decimal* dest);
// Функция для умножения decimal на -1
int s21_negate(s21_decimal value, s21_decimal* result);
// Функция сложения
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
// Функция умножения
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
// Функция деления
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
// Функция деления
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);

// Все функции необходимые для обработки флоат

// Фунция для отображение флоата в памяти
float float_bit_output(float* a, float mantissa, int* exponent,
                       s21_decimal* dst, int* counter_step);
// Функция для записи степени в децимал
void zapis_stepeni_v_decimal(unsigned int a, s21_decimal* dst);
int s21_from_float_to_decimal(float src, s21_decimal* dst);
int s21_from_decimal_to_int(s21_decimal src, int* dst);
int s21_from_decimal_to_float(s21_decimal src, float* dst);

// Умножение децимал чисел
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
// Больше
int s21_is_greater(s21_decimal src, s21_decimal dst);
// Меньше
int s21_is_less(s21_decimal src, s21_decimal dst);
// Равно
int s21_is_equal(s21_decimal src, s21_decimal dst);
// Больше или равно
int s21_is_greater_or_equal(s21_decimal src, s21_decimal dst);
// Меньше или равно
int s21_is_less_or_equal(s21_decimal src, s21_decimal dst);
// Не равно
int s21_is_not_equal(s21_decimal src, s21_decimal dst);

// Функция для перевода из строки в decimal
s21_decimal char_to_decimal(const char* stirng);

// Возвращает целые цифры указанного Decimal числа; любые дробные цифры
// отбрасываются, включая конечные нули.
int s21_truncate(s21_decimal value, s21_decimal* result);

// Округляет Decimal до ближайшего целого числа.
int s21_round(s21_decimal value, s21_decimal* result);

// Округляет указанное Decimal число до ближайшего целого числа в сторону
// отрицательной бесконечности.
int s21_floor(s21_decimal value, s21_decimal* result);

/******************************************************
 * Операции с битами:
 *****************************************************/

// Умножает число, цифры которого в виде строки, на 2
int mult_by_2(char* a, char* result);

// Выставляет бит в указанную позицию
void setbit(unsigned int* value, const int position);

// Функция, которая проверяет выставленный бит в конкретной позиции.
// Возвращает 1, если искомый бит выствлен
int checkbit(const int value, const int position);

/*****************************************************
 * Операции для обработки чисел в виде строки
 ****************************************************/

// переворот строки
void revers(char* src, int size);

// Сложение двух строк
int summ_two_string(char* num1, char* num2, char* result);

// Сравнение двух строк и возврат длины большей строки
size_t max_lenght(char* num1, char* num2);

// Перевод ascii символа в целочисленный int
int char_to_int(char a);

// Вставки точки-разделителя в строку
void dot_insert(char* result, int period_length);

// Подсчёт количества символов за точкой
int digits_aft_dot(char* dec);
int digits_aft_dot2(char* dec);

// Удаление лишних нулей в конце дробной части
char* zero_cutter(char* result);

// Банковское округление числа
int bank_round(char* string_of_number, int sign);

// Приведение числа с точкой к целому значению. Убирает точку и записывает в
char* remove_dot(char* dec, char* temp_dec);

void slozhenie(s21_decimal* dst, int exponent);

// Берем число типа s21_decimal по модулю
void remove_sign_sub(u_int32_t* val);

// Функция для вычитания 2-х чисел типа s21_decimal
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);

// Запись нуля в результат
int result_0(s21_decimal* res);

// Математические функции
typedef struct {
  char dec[340];
  int sign;
  int exp;
} str_decimal;

short s21_dec_exp_to_short(s21_decimal* in);
void s21_dec_to_bit_str(s21_decimal* in, char* out);
void num_str_delete_all_right_zeros(char* num_str);
int s21_dec_to_str_dec(s21_decimal in, str_decimal* out);
void bit_str_to_str_dec(char* in, char* out);
int num_str_add(char* value_1, char* value_2, char* result, int num_system);
void num_str_prepare(char* value_1, char* value_2);
void reverse_str(char* str);
void num_str_delete_right_zeros(char* num_str);
int num_str_mul(char* value_1, char* value_2, char* result, int num_system);
int dec_str_universal_add_sub(str_decimal value_1, str_decimal value_2,
                              str_decimal* result);
void dec_str_zero_exp(str_decimal* value_1, str_decimal* value_2);
int num_str_is_greater(char* str1, char* str2);
int num_str_sub_simple(char* value_1, char* value_2, char* result,
                       int num_system);
int dec_str_pack_result(str_decimal* result);
void num_str_bank_round(char* num_str, int position);
int num_str_is_equal(char* str1, char* str2);
void str_decimal_to_zero(str_decimal* str_dec);
int dec_str_mul(str_decimal* value_1, str_decimal* value_2,
                str_decimal* result);
int dec_str_div(str_decimal* value_1, str_decimal* value_2,
                str_decimal* result);
int num_str_div(char* value_1, char* value_2, char* result);
int num_str_is_greater_or_equal(char* str1, char* str2);
void num_str_delete_left_zeros(char* num_str);
int dec_str_mod(str_decimal* value_1, str_decimal* value_2,
                str_decimal* result);
int num_str_mod(char* value_1, char* value_2, char* result);
void from_str_to_binary(char* in, char* out, int in_num_system);
int str_dec_to_s21_dec(str_decimal in, s21_decimal* out);
unsigned div_by_int_ret_ost(char* delimoe, int devisor, int num_system,
                            char* result);

#endif  // SRC_S21_DECIMAL_H_
