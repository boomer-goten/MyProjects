#include "../header.h"

START_TEST(decimal_to_float_1) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  float float_result = 3.14;
  float s21_float_result = 0;
  s21_decimal number = {0};
  number.bits[0] = 314;
  number.bits[1] = 0;
  number.bits[2] = 0;
  zapis_stepeni_v_decimal(2, &number);
  s21_from_decimal_to_float(number, &s21_float_result);
  sprintf(result, "%.28f", float_result);
  sprintf(s21_result, "%.28f", s21_float_result);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(decimal_to_float_2) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  float float_result = -3.14;
  float s21_float_result = 0;
  s21_decimal number = {0};
  number.bits[0] = 314;
  number.bits[1] = 0;
  number.bits[2] = 0;
  number.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(2, &number);
  s21_from_decimal_to_float(number, &s21_float_result);
  sprintf(result, "%.28f", float_result);
  sprintf(s21_result, "%.28f", s21_float_result);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(decimal_to_float_3) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  float float_result = -5792277640.493418938682;
  float s21_float_result = 0;
  s21_decimal number = {0};
  number.bits[0] = 314;
  number.bits[1] = 314;
  number.bits[2] = 314;
  number.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(12, &number);
  s21_from_decimal_to_float(number, &s21_float_result);
  sprintf(result, "%.28f", float_result);
  sprintf(s21_result, "%.28f", s21_float_result);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(decimal_to_float_4) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  float float_result = 5792277640.493418938682;
  float s21_float_result = 0;
  s21_decimal number = {0};
  number.bits[0] = 314;
  number.bits[1] = 314;
  number.bits[2] = 314;
  zapis_stepeni_v_decimal(12, &number);
  s21_from_decimal_to_float(number, &s21_float_result);
  sprintf(result, "%.28f", float_result);
  sprintf(s21_result, "%.28f", s21_float_result);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(decimal_to_float_5) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  float float_result = 1980704062.8566084398385987584;
  float s21_float_result = 0;
  s21_decimal number = {0};
  number.bits[0] = 0;
  number.bits[1] = 0;
  number.bits[2] = 1073741824;
  zapis_stepeni_v_decimal(19, &number);
  s21_from_decimal_to_float(number, &s21_float_result);
  sprintf(result, "%.28f", float_result);
  sprintf(s21_result, "%.28f", s21_float_result);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(decimal_to_float_6) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  float float_result = -1980704062.8566084398385987584;
  float s21_float_result = 0;
  s21_decimal number = {0};
  number.bits[0] = 0;
  number.bits[1] = 0;
  number.bits[2] = 1073741824;
  number.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(19, &number);
  s21_from_decimal_to_float(number, &s21_float_result);
  sprintf(result, "%.28f", float_result);
  sprintf(s21_result, "%.28f", s21_float_result);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(decimal_to_float_7) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  float float_result = -1980704063.3177770417887117312;
  float s21_float_result = 0;
  s21_decimal number = {0};
  number.bits[0] = 1073741824;
  number.bits[1] = 1073741824;
  number.bits[2] = 1073741824;
  number.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(19, &number);
  s21_from_decimal_to_float(number, &s21_float_result);
  sprintf(result, "%.28f", float_result);
  sprintf(s21_result, "%.28f", s21_float_result);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_decimal_to_float;

  s = suite_create("s21_decimal_to_float");

  tc_decimal_to_float = tcase_create("s21_decimal_to_float");
  tcase_add_test(tc_decimal_to_float, decimal_to_float_1);
  tcase_add_test(tc_decimal_to_float, decimal_to_float_2);
  tcase_add_test(tc_decimal_to_float, decimal_to_float_3);
  tcase_add_test(tc_decimal_to_float, decimal_to_float_4);
  tcase_add_test(tc_decimal_to_float, decimal_to_float_5);
  tcase_add_test(tc_decimal_to_float, decimal_to_float_6);
  tcase_add_test(tc_decimal_to_float, decimal_to_float_7);
  suite_add_tcase(s, tc_decimal_to_float);

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
