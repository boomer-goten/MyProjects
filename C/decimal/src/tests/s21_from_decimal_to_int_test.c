#include "../header.h"

START_TEST(decimal_to_int_1) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int int_result = 3.14;
  int s21_int_result = 0;
  s21_decimal number = {0};
  number.bits[0] = 314;
  number.bits[1] = 0;
  number.bits[2] = 0;
  zapis_stepeni_v_decimal(2, &number);
  s21_from_decimal_to_int(number, &s21_int_result);
  sprintf(result, "%d", int_result);
  sprintf(s21_result, "%d", s21_int_result);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(decimal_to_int_2) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int int_result = -3.14;
  int s21_int_result = 0;
  s21_decimal number = {0};
  number.bits[0] = 314;
  number.bits[1] = 0;
  number.bits[2] = 0;
  number.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(2, &number);
  s21_from_decimal_to_int(number, &s21_int_result);
  sprintf(result, "%d", int_result);
  sprintf(s21_result, "%d", s21_int_result);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(decimal_to_int_3) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int int_result = -57922776.40493418938682;
  int s21_int_result = 0;
  s21_decimal number = {0};
  number.bits[0] = 314;
  number.bits[1] = 314;
  number.bits[2] = 314;
  number.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(14, &number);
  s21_from_decimal_to_int(number, &s21_int_result);
  sprintf(result, "%d", int_result);
  sprintf(s21_result, "%d", s21_int_result);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(decimal_to_int_4) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int int_result = 57922776.40493418938682;
  int s21_int_result = 0;
  s21_decimal number = {0};
  number.bits[0] = 314;
  number.bits[1] = 314;
  number.bits[2] = 314;
  zapis_stepeni_v_decimal(14, &number);
  s21_from_decimal_to_int(number, &s21_int_result);
  sprintf(result, "%d", int_result);
  sprintf(s21_result, "%d", s21_int_result);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(decimal_to_int_5) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int int_result = 1980704062.8566084398385987584;
  int s21_int_result = 0;
  s21_decimal number = {0};
  number.bits[0] = 0;
  number.bits[1] = 0;
  number.bits[2] = 1073741824;
  zapis_stepeni_v_decimal(19, &number);
  s21_from_decimal_to_int(number, &s21_int_result);
  sprintf(result, "%d", int_result);
  sprintf(s21_result, "%d", s21_int_result);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(decimal_to_int_6) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int int_result = -1980704062.8566084398385987584;
  int s21_int_result = 0;
  s21_decimal number = {0};
  number.bits[0] = 0;
  number.bits[1] = 0;
  number.bits[2] = 1073741824;
  number.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(19, &number);
  s21_from_decimal_to_int(number, &s21_int_result);
  sprintf(result, "%d", int_result);
  sprintf(s21_result, "%d", s21_int_result);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(decimal_to_int_7) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int int_result = -1980704063.3177770417887117312;
  int s21_int_result = 0;
  s21_decimal number = {0};
  number.bits[0] = 1073741824;
  number.bits[1] = 1073741824;
  number.bits[2] = 1073741824;
  number.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(19, &number);
  s21_from_decimal_to_int(number, &s21_int_result);
  sprintf(result, "%d", int_result);
  sprintf(s21_result, "%d", s21_int_result);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(decimal_to_int_8) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int int_result = 4294967295;
  int s21_int_result = 0;
  s21_decimal number = {0};
  number.bits[0] = 4294967295;
  number.bits[1] = 0;
  number.bits[2] = 232;
  zapis_stepeni_v_decimal(0, &number);
  s21_from_decimal_to_int(number, &s21_int_result);
  sprintf(result, "%d", int_result);
  sprintf(s21_result, "%d", s21_int_result);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

// Число слишком велико. Ошибка конвертации
START_TEST(decimal_to_int_9) {
  char *a = "7922816.2514264337593543950335";
  int fn_returned = 0;
  int result = 0;
  s21_decimal number = {0};
  number = char_to_decimal(a);
  fn_returned = s21_from_decimal_to_int(number, &result);
  ck_assert_int_eq(result, 7922816);
  ck_assert_int_eq(fn_returned, 0);
}
END_TEST

// Число слишком велико. Ошибка конвертации
START_TEST(decimal_to_int_10) {
  char *a = "79228162514264337593543950335";
  int fn_returned = 0;
  int *result = NULL;
  s21_decimal number = {0};
  number = char_to_decimal(a);
  fn_returned = s21_from_decimal_to_int(number, result);
  ck_assert_int_eq(fn_returned, 1);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_decimal_to_int;

  s = suite_create("s21_decimal_to_int");

  tc_decimal_to_int = tcase_create("s21_decimal_to_int");
  tcase_add_test(tc_decimal_to_int, decimal_to_int_1);
  tcase_add_test(tc_decimal_to_int, decimal_to_int_2);
  tcase_add_test(tc_decimal_to_int, decimal_to_int_3);
  tcase_add_test(tc_decimal_to_int, decimal_to_int_4);
  tcase_add_test(tc_decimal_to_int, decimal_to_int_5);
  tcase_add_test(tc_decimal_to_int, decimal_to_int_6);
  tcase_add_test(tc_decimal_to_int, decimal_to_int_7);
  tcase_add_test(tc_decimal_to_int, decimal_to_int_8);
  tcase_add_test(tc_decimal_to_int, decimal_to_int_9);
  tcase_add_test(tc_decimal_to_int, decimal_to_int_10);
  suite_add_tcase(s, tc_decimal_to_int);

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
