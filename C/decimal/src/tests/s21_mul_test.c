#include "../header.h"

START_TEST(mul_1) {
  char s21_result[BUF] = {'\0'};
  char result[BUF] = {'\0'};
  int a = 421, b = 79, exit_code = 0;
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  s21_from_int_to_decimal(a, &number1);
  s21_from_int_to_decimal(b, &number2);
  s21_decimal dec_result = {0};
  exit_code = s21_mul(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  sprintf(result, "%d", a * b);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

//  Число слишком велико или равно бесконечности
START_TEST(mul_2) {
  char s21_result[BUF], result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  // Записываем в мантиссу максимальное число
  for (int i = 0; i < 3; i++) number1.bits[i] = UINT_MAX;
  // Умножаем на 3
  number2.bits[0] = 3;
  s21_decimal dec_result = {0};
  int exit_code = s21_mul(number1, number2, &dec_result);
  ck_assert_int_eq(exit_code, 1);
}
END_TEST

//  Число слишком мало или равно отрицательной бесконечности

START_TEST(mul_4) {
  char s21_result[BUF] = {'\0'};
  char *a = "79228162514264337593543950335";
  char *b = "1";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq("79228162514264337593543950335", s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(mul_5) {
  char *a = "79228162514264337593543950335";
  char *b = "4";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  ck_assert_int_eq(exit_code, 1);
}
END_TEST

START_TEST(mul_8) {
  char s21_result[BUF] = {'\0'};
  char result[BUF] = {'\0'};
  int a = 792286, b = 152, exit_code = 0;
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  s21_from_int_to_decimal(a, &number1);
  s21_from_int_to_decimal(b, &number2);
  s21_decimal dec_result = {0};
  exit_code = s21_mul(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  sprintf(result, "%d", a * b);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(mul_9) {
  char s21_result[BUF] = {'\0'};
  char *a = "7922.8166";
  char *b = "1.152";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  char result[BUF] = "9127.0847232";
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(mul_10) {
  char s21_result[BUF] = {'\0'};
  char *a = "7922.816615";
  char *b = "0.1523";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  char result[BUF] = "1206.6449704645";
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(mul_11) {
  char s21_result[BUF] = {'\0'};
  char *a = "1.5845632502852867518708790067";
  char *b = "0.05";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  char *result = "0.0792281625142643375935439503";
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(mul_12) {
  char s21_result[BUF] = {'\0'};
  char *a = "1.5845632502852867518708790067";
  char *b = "0.5";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  char *result = "0.7922816251426433759354395034";
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(mul_13) {
  char s21_result[BUF] = {'\0'};
  char *a = "1.5845632502852867518708790067";  // 28 after dot
  char *b = "5";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  char result[BUF] = "7.9228162514264337593543950335";
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(mul_14) {
  char s21_result[BUF] = {'\0'};
  char *a = "0.00790067";  // 28 after dot
  char *b = "0.21";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  char result[BUF] = "0.0016591407";
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(mul_15) {
  char s21_result[BUF] = {'\0'};
  char *a = "-0.0000000000000001";  // 28 after dot
  char *b = "0.000000000001";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  char result[BUF] = "-0.0000000000000000000000000001";
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(mul_16) {
  // RESULT 79228162514264337593543950336  Больше максимального decimal
  char *a = "39614081257132168796771975168";
  char *b = "2";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  ck_assert_int_eq(exit_code, 1);
}
END_TEST

START_TEST(mul_17) {
  // RESULT 79228162514264337593543950335 Максимальное значение decimal
  char s21_result[BUF] = {'\0'};
  char *a = "15845632502852867518708790067";
  char *b = "5";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  char result[BUF] = "79228162514264337593543950335";
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(mul_18) {
  // RESULT 79228162511264337593543950335 Почти максимальное значение decimal
  char s21_result[BUF] = {'\0'};
  char *a = "15845.632502252867518708790067";
  char *b = "5";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  char result[BUF] = "79228.162511264337593543950335";
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(mul_19) {
  // RESULT 79228162514264337593543950335 Превышает максимальное значение
  // decimal
  char *a = "15845632503652867518708790067";
  char *b = "5";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  ck_assert_int_eq(exit_code, 1);
}
END_TEST

START_TEST(mul_21) {
  // RESULT 79228162511264337593543950335 Почти максимальное значение decimal
  char s21_result[BUF] = {'\0'};
  char *a = "9.61408125562255472";
  char *b = "2.00000000012";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  char result[BUF] = "19.228162512398799190674706566";
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(mul_23) {
  // RESULT 79228162514264337593543950335 Превышает максимальное значение
  // decimal
  char *a = "65845632503652867518708.790067";
  char *b = "12351323114.132456";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  ck_assert_int_eq(exit_code, 1);
}
END_TEST

// Умножение двух отрицательных чисел
START_TEST(mul_24) {
  char s21_result[BUF] = {'\0'};
  char *a = "-158456325036.52867518708790067";
  char *b = "-5123332441.113332";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  char result[BUF] = "811824430559246043841.7990536";
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

// Умножение положительного 0 на положительный 0
START_TEST(mul_25) {
  char s21_result[BUF] = {'\0'};
  char *a = "0";
  char *b = "0";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  char result[BUF] = "0";
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

// Умножение положительного 0 на отрицательный 0
START_TEST(mul_26) {
  char s21_result[BUF] = {'\0'};
  char *a = "0";
  char *b = "-0";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  char result[BUF] = "-0";
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

// Умножение отрицательного 0 на положительный 0
START_TEST(mul_27) {
  char s21_result[BUF] = {'\0'};
  char *a = "-0";
  char *b = "0";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  char result[BUF] = "-0";
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

// Умножение отрицательного 0 на отрицательный 0
START_TEST(mul_28) {
  char s21_result[BUF] = {'\0'};
  char *a = "-0";
  char *b = "-0";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  char result[BUF] = "0";
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

// Умножение положительного числа на положительный 0
START_TEST(mul_29) {
  char s21_result[BUF] = {'\0'};
  char *a = "144528.2858581";
  char *b = "0";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  char result[BUF] = "0";
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

// Умножение положительного числа на отрицательный 0
START_TEST(mul_30) {
  char s21_result[BUF] = {'\0'};
  char *a = "3993858717.19857";
  char *b = "-0";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  char result[BUF] = "-0";
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

// Умножение отрицательного числа на положительный 0
START_TEST(mul_31) {
  char s21_result[BUF] = {'\0'};
  char *a = "-0.39939587265";
  char *b = "0";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  char result[BUF] = "-0";
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

// Умножение отрицательного числа на отрицательный 0
START_TEST(mul_32) {
  char s21_result[BUF] = {'\0'};
  char *a = "-3999383757.1982754";
  char *b = "-0";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mul(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  char result[BUF] = "0";
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_mul;

  s = suite_create("s21_mul");

  tc_mul = tcase_create("s21_mul");
  tcase_add_test(tc_mul, mul_1);
  tcase_add_test(tc_mul, mul_2);
  tcase_add_test(tc_mul, mul_4);
  tcase_add_test(tc_mul, mul_5);
  tcase_add_test(tc_mul, mul_8);
  tcase_add_test(tc_mul, mul_9);
  tcase_add_test(tc_mul, mul_10);
  tcase_add_test(tc_mul, mul_11);
  tcase_add_test(tc_mul, mul_12);
  tcase_add_test(tc_mul, mul_13);
  tcase_add_test(tc_mul, mul_14);
  tcase_add_test(tc_mul, mul_15);
  tcase_add_test(tc_mul, mul_16);
  tcase_add_test(tc_mul, mul_17);
  tcase_add_test(tc_mul, mul_18);
  tcase_add_test(tc_mul, mul_19);
  tcase_add_test(tc_mul, mul_21);
  tcase_add_test(tc_mul, mul_23);
  tcase_add_test(tc_mul, mul_24);
  tcase_add_test(tc_mul, mul_25);
  tcase_add_test(tc_mul, mul_26);
  tcase_add_test(tc_mul, mul_27);
  tcase_add_test(tc_mul, mul_28);
  tcase_add_test(tc_mul, mul_29);
  tcase_add_test(tc_mul, mul_30);
  tcase_add_test(tc_mul, mul_31);
  tcase_add_test(tc_mul, mul_32);
  suite_add_tcase(s, tc_mul);

  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;
  s = sprintf_test();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
