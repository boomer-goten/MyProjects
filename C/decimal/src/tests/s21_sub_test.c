#include "../header.h"

// MIN_DECIMAL -79228162514264337593543950335

START_TEST(sub_1) {
  char s21_result[BUF] = {'\0'};
  char *a = "-79228162514264337593543950334";
  char *b = "1";
  char *result = "-79228162514264337593543950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_sub(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(sub_2) {
  // Результат до округления -792283069363.94376723391129246395
  char s21_result[BUF] = {'\0'};
  char *a = "-792281625142.64337593543950334";
  char *b = "1444221.30039129847178912395";
  char *result = "-792283069363.9437672339112925";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_sub(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(sub_3) {
  char s21_result[BUF] = {'\0'};
  char *a = "-79228162514264337593543950334";
  char *b = "1";
  char *result = "-79228162514264337593543950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_sub(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(sub_4) {
  char s21_result[BUF] = {'\0'};
  char *a = "-0";
  char *b = "0";
  char *result = "-0";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_sub(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(sub_5) {
  char s21_result[BUF] = {'\0'};
  char *a = "0.00";
  char *b = "0.00";
  char *result = "-0";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_sub(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(sub_6) {
  char s21_result[BUF] = {'\0'};
  char *a = "-0.00";
  char *b = "-11.5";
  char *result = "11.50";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_sub(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(sub_7) {
  char s21_result[BUF] = {'\0'};
  char *a = "-0.00";
  char *b = "11.545613";
  char *result = "-11.545613";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_sub(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

// // проверка на переполнение в положительной части
START_TEST(sub_9) {
  // printf("test\n");
  char s21_result[BUF] = {'\0'};
  char *a = "79228162514264337593543950335";
  char *b = "-11.5";
  // char *result = "79228162514264337593543950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_sub(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  // ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 1);
}
END_TEST

// Добавил кейс в тест для банковскоо округления. Проходит. Здесь тест не
// проходит проверка на вычитание с применением банковского округляния
START_TEST(sub_10) {
  char s21_result[BUF] = {'\0'};
  char *a = "79228162514264337593543950335";
  char *b = "0.666666";
  char *result = "79228162514264337593543950334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_sub(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

// проверка на вычитание с применением банковского округляния
START_TEST(sub_11) {
  char s21_result[BUF] = {'\0'};
  char *a = "79228162514264337593543950335";
  char *b = "0.444444444444444444";
  char *result = "79228162514264337593543950334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_sub(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

// проверка на вычитание с применением банковского округляния
START_TEST(sub_12) {
  char s21_result[BUF] = {'\0'};
  char *a = "-79228162514264337593543950335";
  char *b = "-0.6666666";
  char *result = "-79228162514264337593543950334";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_sub(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

// проверка на вычитание с применением банковского округляния
START_TEST(sub_13) {
  char s21_result[BUF] = {'\0'};
  char *a = "-79228162514264337593543950335";
  char *b = "-0.222222222222222222222";
  char *result = "-79228162514264337593543950335";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_sub(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(sub_14) {
  char s21_result[BUF] = {'\0'};
  char *a = "3961408125713216879.9999993837";
  char *b = "3960000000009.6771975167";
  char *result = "3961404165713216870.3228018670";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_sub(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(sub_15) {
  char s21_result[BUF] = {'\0'};
  char *a = "396125713216879.9999993837";
  char *b = "9.6771975167";
  char *result = "396125713216870.3228018670";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_sub(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(sub_16) {
  char s21_result[BUF] = {'\0'};
  char *a = "0.9999993837";
  char *b = "0.0000000000007";
  char *result = "0.9999993836993";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_sub(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(sub_17) {
  char s21_result[BUF] = {'\0'};
  char *a = "0.9999938370000000000000000002";
  char *b = "0.0000000000000000000000000007";
  char *result = "0.9999938369999999999999999995";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_sub(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(sub_18) {
  char s21_result[BUF] = {'\0'};
  char *a = "0.99370000000000000000002";
  char *b = "0.00000000000000000000007";
  char *result = "0.99369999999999999999995";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_sub(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(sub_19) {
  char s21_result[BUF] = {'\0'};
  char *a = "0.3092029384717792139871242";
  char *b = "0.12233445511223344552255";
  char *result = "0.1868684833595457684645742";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_sub(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(sub_20) {
  char s21_result[BUF] = {'\0'};
  char *a = "0.3092029384717792139871242";
  char *b = "1.12233445511223344552255";
  char *result = "-0.8131315166404542315354258";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_sub(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(sub_21) {
  char s21_result[BUF] = {'\0'};
  char *a = "0.3092029384717792139871242";
  char *b = "-1.12233445511223344552255";
  char *result = "1.4315373935840126595096742";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_sub(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(sub_22) {
  char s21_result[BUF] = {'\0'};
  char *a = "0.3092029384717792139871242";
  char *b = "-0.3092029384717792139871242";
  char *result = "0.6184058769435584279742484";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_sub(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(sub_23) {
  char s21_result[BUF] = {'\0'};
  char *a = "-0.3092029384717792139871242";
  char *b = "-0.3092029384717792139871242";
  char *result = "0";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_sub(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_sub;

  s = suite_create("s21_sub");
  tc_sub = tcase_create("s21_sub");
  tcase_add_test(tc_sub, sub_1);
  tcase_add_test(tc_sub, sub_2);
  tcase_add_test(tc_sub, sub_3);
  tcase_add_test(tc_sub, sub_4);
  tcase_add_test(tc_sub, sub_5);
  tcase_add_test(tc_sub, sub_6);
  tcase_add_test(tc_sub, sub_7);
  tcase_add_test(tc_sub, sub_9);
  tcase_add_test(tc_sub, sub_10);
  tcase_add_test(tc_sub, sub_11);
  tcase_add_test(tc_sub, sub_12);
  tcase_add_test(tc_sub, sub_13);
  tcase_add_test(tc_sub, sub_14);
  tcase_add_test(tc_sub, sub_15);
  tcase_add_test(tc_sub, sub_16);
  tcase_add_test(tc_sub, sub_17);
  tcase_add_test(tc_sub, sub_18);
  tcase_add_test(tc_sub, sub_19);
  tcase_add_test(tc_sub, sub_20);
  tcase_add_test(tc_sub, sub_21);
  tcase_add_test(tc_sub, sub_22);
  tcase_add_test(tc_sub, sub_23);

  suite_add_tcase(s, tc_sub);

  return s;
}

int main() {
  int number_failed = 0;
  Suite *s;
  SRunner *sr;
  s = sprintf_test();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
