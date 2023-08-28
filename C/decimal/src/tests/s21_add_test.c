#include "../header.h"

// MAX_DECIMAL 79228162514264337593543950335

START_TEST(add_1) {
  char s21_result[BUF] = {'\0'};
  char *a = "79228162514264337593543950334";
  char *b = "1";
  char *result = "79228162514264337593543950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_2) {
  // RESULT до округления 792283069363.94376723391129246395
  char s21_result[BUF] = {'\0'};
  char *a = "792281625142.64337593543950334";
  char *b = "1444221.30039129847178912395";
  char *result = "792283069363.9437672339112925";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_3) {
  // RESULT до округления 1444221188253.9885168211151650354395033422
  char s21_result[BUF] = {'\0'};
  char *a = "0.6881255226433759354395033422";
  char *b = "1444221188253.3003912984717891";
  char *result = "1444221188253.9885168211151650";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_4) {
  // RESULT до округления
  char s21_result[BUF] = {'\0'};
  char *a = "0";
  char *b = "1444221188253.3003912984717891";
  char *result = "1444221188253.3003912984717891";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_5) {
  // RESULT до округления 1444221188253.413349625819590334837
  char s21_result[BUF] = {'\0'};
  char *a = "0.112958327347801234837";
  char *b = "1444221188253.3003912984717891";
  char *result = "1444221188253.4133496258195903";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_6) {
  // RESULT до округления 0.0000000000000000000000000002
  char s21_result[BUF] = {'\0'};
  char *a = "0.0000000000000000000000000001";
  char *b = "0.0000000000000000000000000001";
  char *result = "0.0000000000000000000000000002";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_7) {
  // RESULT до округления 14.0000000000031000000000000002
  char s21_result[BUF] = {'\0'};
  char *a = "7.0000000000015500000000000001";
  char *b = "7.0000000000024500000000000001";
  char *result = "14.000000000004000000000000000";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_8) {
  // RESULT до округления 14.0000000000040109346968440055
  char s21_result[BUF] = {'\0'};
  char *a = "7.0000000000015514529582582858";
  char *b = "7.0000000000024594817385857197";
  char *result = "14.000000000004010934696844006";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_9) {
  // RESULT до округления 79228162514264337593543950334
  char s21_result[BUF] = {'\0'};
  char *a = "39614081257132168796771975167";
  char *b = "39614081257132168796771975167";
  char *result = "79228162514264337593543950334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_10) {
  // RESULT до округления 7922816251426433759.6771969004
  char s21_result[BUF] = {'\0'};
  char *a = "3961408125713216879.6771975167";
  char *b = "3961408125713216879.9999993837";
  char *result = "7922816251426433759.677196900";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

// Сложение отрицательных чисел

START_TEST(add_11) {
  char s21_result[BUF] = {'\0'};
  char *a = "-79228162514264337593543950334";
  char *b = "-1";
  char *result = "-79228162514264337593543950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_12) {
  // RESULT до округления -1444221188253.9885168211151650354395033422
  char s21_result[BUF] = {'\0'};
  char *a = "-0.6881255226433759354395033422";
  char *b = "-1444221188253.3003912984717891";
  char *result = "-1444221188253.9885168211151650";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_13) {
  // RESULT до округления
  char s21_result[BUF] = {'\0'};
  char *a = "-0";
  char *b = "-1444221188253.3003912984717891";
  char *result = "-1444221188253.3003912984717891";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_14) {
  // RESULT до округления -1444221188253.413349625819590334837
  char s21_result[BUF] = {'\0'};
  char *a = "-0.112958327347801234837";
  char *b = "-1444221188253.3003912984717891";
  char *result = "-1444221188253.4133496258195903";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_15) {
  // RESULT до округления -0.0000000000000000000000000002
  char s21_result[BUF] = {'\0'};
  char *a = "-0.0000000000000000000000000001";
  char *b = "-0.0000000000000000000000000001";
  char *result = "-0.0000000000000000000000000002";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_16) {
  // RESULT до округления -14.0000000000031000000000000002
  char s21_result[BUF] = {'\0'};
  char *a = "-7.0000000000015500000000000001";
  char *b = "-7.0000000000024500000000000001";
  char *result = "-14.000000000004000000000000000";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_17) {
  // RESULT до округления -14.0000000000040109346968440055
  char s21_result[BUF] = {'\0'};
  char *a = "-7.0000000000015514529582582858";
  char *b = "-7.0000000000024594817385857197";
  char *result = "-14.000000000004010934696844006";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_18) {
  // RESULT до округления -79228162514264337593543950334
  char s21_result[BUF] = {'\0'};
  char *a = "-39614081257132168796771975167";
  char *b = "-39614081257132168796771975167";
  char *result = "-79228162514264337593543950334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_19) {
  // RESULT до округления 7922816251426433759.6771969004
  char s21_result[BUF] = {'\0'};
  char *a = "-3961408125713216879.6771975167";
  char *b = "-3961408125713216879.9999993837";
  char *result = "-7922816251426433759.677196900";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_20) {
  // RESULT до округления 7922816251426433759.6771969004
  char s21_result[BUF] = {'\0'};
  char *a = "-3960000000009.6771975167";
  char *b = "-3961408125713216879.9999993837";
  char *result = "-3961412085713216889.6771969004";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

// Тесты на очень большое число

START_TEST(add_21) {
  // RESULT  79228162514264337593543950336
  char *a = "79228162514264337593543950335";
  char *b = "1";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  ck_assert_int_eq(exit_code, 1);
}
END_TEST

START_TEST(add_22) {
  // RESULT  79228162514264337593543950331
  char *a = "79228162514264337593540000335";
  char *b = "3543950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  ck_assert_int_eq(exit_code, 1);
}
END_TEST

// Тесты на сложение отрицательного и положительного числа

// Тест провален. Добавил к тестам на вычитание
START_TEST(add_23) {
  // 3961404165713216870.322801867
  char s21_result[BUF] = {'\0'};
  char *a = "-3960000000009.6771975167";
  char *b = "3961408125713216879.9999993837";
  char *result = "3961404165713216870.3228018670";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_24) {
  // RESULT до округления -3961404165713216870.322801867
  char s21_result[BUF] = {'\0'};
  char *a = "3960000000009.6771975167";
  char *b = "-3961408125713216879.9999993837";
  char *result = "-3961404165713216870.3228018670";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_25) {
  // RESULT до округления -3961404165713216870.322801867
  char s21_result[BUF] = {'\0'};
  char *a = "9.6771975167";
  char *b = "-396125713216879.9999993837";
  char *result = "-396125713216870.3228018670";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

// Тест провален. Добавил к тестам для вычитания
START_TEST(add_26) {
  // RESULT до округления 0.9999993836993
  char s21_result[BUF] = {'\0'};
  char *a = "-0.0000000000007";
  char *b = "0.9999993837";
  char *result = "0.9999993836993";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

// Тест провален. Добавил к тестам на вычитание
START_TEST(add_27) {
  // RESULT до округления 0.9999938369999999999999999995
  char s21_result[BUF] = {'\0'};
  char *a = "-0.0000000000000000000000000007";
  char *b = "0.9999938370000000000000000002";
  char *result = "0.9999938369999999999999999995";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

// Тест провален. Добавил к тестам на вычитание
START_TEST(add_28) {
  // RESULT до округления -0.99369999999999999999995
  char s21_result[BUF] = {'\0'};
  char *a = "0.00000000000000000000007";
  char *b = "-0.99370000000000000000002";
  char *result = "-0.99369999999999999999995";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_29) {
  // RESULT до округления -0.3092029384717792139871242
  char s21_result[BUF] = {'\0'};
  char *a = "0.12233445511223344552255";
  char *b = "-0.3092029384717792139871242";
  char *result = "-0.1868684833595457684645742";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

// Дополнительные тесты для лучшего покрытия
START_TEST(add_30) {
  // RESULT до округления -0.3092029384717792139871242
  char s21_result[BUF] = {'\0'};
  char *a = "1.12233445511223344552255";
  char *b = "-0.3092029384717792139871242";
  char *result = "0.8131315166404542315354258";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_31) {
  char s21_result[BUF] = {'\0'};
  char *a = "-1.12233445511223344552255";
  char *b = "1.12233445511223344552255";
  char *result = "0";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_32) {
  char s21_result[BUF] = {'\0'};
  char *a = "1.12233445511223344552255";
  char *b = "-1.12233445511223344552255";
  char *result = "-0";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_33) {
  // RESULT до округления -0.3092029384717792139871242
  char s21_result[BUF] = {'\0'};
  char *a = "-1.12233445511223344552255";
  char *b = "0.3092029384717792139871242";
  char *result = "-0.8131315166404542315354258";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_add(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_add;

  s = suite_create("s21_add");

  tc_add = tcase_create("s21_add");
  tcase_add_test(tc_add, add_1);
  tcase_add_test(tc_add, add_2);
  tcase_add_test(tc_add, add_3);
  tcase_add_test(tc_add, add_4);
  tcase_add_test(tc_add, add_5);
  tcase_add_test(tc_add, add_6);
  tcase_add_test(tc_add, add_7);
  tcase_add_test(tc_add, add_8);
  tcase_add_test(tc_add, add_9);
  tcase_add_test(tc_add, add_10);
  tcase_add_test(tc_add, add_11);
  tcase_add_test(tc_add, add_12);
  tcase_add_test(tc_add, add_13);
  tcase_add_test(tc_add, add_14);
  tcase_add_test(tc_add, add_15);
  tcase_add_test(tc_add, add_16);
  tcase_add_test(tc_add, add_17);
  tcase_add_test(tc_add, add_18);
  tcase_add_test(tc_add, add_19);
  tcase_add_test(tc_add, add_20);
  tcase_add_test(tc_add, add_21);
  tcase_add_test(tc_add, add_22);
  tcase_add_test(tc_add, add_23);
  // sub_case
  tcase_add_test(tc_add, add_24);
  tcase_add_test(tc_add, add_25);
  tcase_add_test(tc_add, add_26);
  tcase_add_test(tc_add, add_27);
  tcase_add_test(tc_add, add_28);
  tcase_add_test(tc_add, add_29);
  // Coverage test
  tcase_add_test(tc_add, add_30);
  tcase_add_test(tc_add, add_31);
  tcase_add_test(tc_add, add_32);
  tcase_add_test(tc_add, add_33);
  suite_add_tcase(s, tc_add);

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
