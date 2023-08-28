#include "../header.h"

START_TEST(int_to_decimal_1) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int a = INT_MAX;
  s21_decimal number = {0};
  s21_from_int_to_decimal(a, &number);
  dec_to_string(&number, s21_result);
  sprintf(result, "%d", a);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(int_to_decimal_2) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int a = INT_MIN;
  s21_decimal number = {0};
  s21_from_int_to_decimal(a, &number);
  dec_to_string(&number, s21_result);
  sprintf(result, "%d", a);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(int_to_decimal_3) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int a = 1059308;
  s21_decimal number = {0};
  s21_from_int_to_decimal(a, &number);
  dec_to_string(&number, s21_result);
  sprintf(result, "%d", a);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(int_to_decimal_4) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int a = -10530508;
  s21_decimal number = {0};
  s21_from_int_to_decimal(a, &number);
  dec_to_string(&number, s21_result);
  sprintf(result, "%d", a);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(int_to_decimal_5) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int a = 0;
  s21_decimal number = {0};
  s21_from_int_to_decimal(a, &number);
  dec_to_string(&number, s21_result);
  sprintf(result, "%d", a);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(int_to_decimal_6) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int a = -0;
  s21_decimal number = {0};
  s21_from_int_to_decimal(a, &number);
  dec_to_string(&number, s21_result);
  sprintf(result, "%d", a);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(int_to_decimal_7) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int a = 299928579;
  s21_decimal number = {0};
  s21_from_int_to_decimal(a, &number);
  dec_to_string(&number, s21_result);
  sprintf(result, "%d", a);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(int_to_decimal_8) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int a = 1;
  s21_decimal number = {0};
  s21_from_int_to_decimal(a, &number);
  dec_to_string(&number, s21_result);
  sprintf(result, "%d", a);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(int_to_decimal_9) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int a = -1;
  s21_decimal number = {0};
  s21_from_int_to_decimal(a, &number);
  dec_to_string(&number, s21_result);
  sprintf(result, "%d", a);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(int_to_decimal_10) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int a = 1200;
  s21_decimal number = {0};
  s21_from_int_to_decimal(a, &number);
  dec_to_string(&number, s21_result);
  sprintf(result, "%d", a);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(int_to_decimal_11) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int a = -1200;
  s21_decimal number = {0};
  s21_from_int_to_decimal(a, &number);
  dec_to_string(&number, s21_result);
  sprintf(result, "%d", a);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(int_to_decimal_12) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int a = 1200002982;
  s21_decimal number = {0};
  s21_from_int_to_decimal(a, &number);
  dec_to_string(&number, s21_result);
  sprintf(result, "%d", a);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(int_to_decimal_13) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int a = -1200002982;
  s21_decimal number = {0};
  s21_from_int_to_decimal(a, &number);
  dec_to_string(&number, s21_result);
  sprintf(result, "%d", a);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(int_to_decimal_14) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int a = -2002987;
  s21_decimal number = {0};
  s21_from_int_to_decimal(a, &number);
  dec_to_string(&number, s21_result);
  sprintf(result, "%d", a);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(int_to_decimal_15) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int a = 2002987;
  s21_decimal number = {0};
  s21_from_int_to_decimal(a, &number);
  dec_to_string(&number, s21_result);
  sprintf(result, "%d", a);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(int_to_decimal_16) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int a = 1211171;
  s21_decimal number = {0};
  s21_from_int_to_decimal(a, &number);
  dec_to_string(&number, s21_result);
  sprintf(result, "%d", a);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(int_to_decimal_17) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int a = -1211171;
  s21_decimal number = {0};
  s21_from_int_to_decimal(a, &number);
  dec_to_string(&number, s21_result);
  sprintf(result, "%d", a);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(int_to_decimal_18) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int a = 8571902;
  s21_decimal number = {0};
  s21_from_int_to_decimal(a, &number);
  dec_to_string(&number, s21_result);
  sprintf(result, "%d", a);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(int_to_decimal_19) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int a = -8571902;
  s21_decimal number = {0};
  s21_from_int_to_decimal(a, &number);
  dec_to_string(&number, s21_result);
  sprintf(result, "%d", a);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(int_to_decimal_20) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int a = 62771781;
  s21_decimal number = {0};
  s21_from_int_to_decimal(a, &number);
  dec_to_string(&number, s21_result);
  sprintf(result, "%d", a);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(int_to_decimal_21) {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int a = -62771781;
  s21_decimal number = {0};
  s21_from_int_to_decimal(a, &number);
  dec_to_string(&number, s21_result);
  sprintf(result, "%d", a);
  ck_assert_str_eq(result, s21_result);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_int_to_decimal;

  s = suite_create("s21_int_to_decimal");

  tc_int_to_decimal = tcase_create("s21_int_to_decimal");
  tcase_add_test(tc_int_to_decimal, int_to_decimal_1);
  tcase_add_test(tc_int_to_decimal, int_to_decimal_2);
  tcase_add_test(tc_int_to_decimal, int_to_decimal_3);
  tcase_add_test(tc_int_to_decimal, int_to_decimal_4);
  tcase_add_test(tc_int_to_decimal, int_to_decimal_5);
  tcase_add_test(tc_int_to_decimal, int_to_decimal_6);
  tcase_add_test(tc_int_to_decimal, int_to_decimal_7);
  tcase_add_test(tc_int_to_decimal, int_to_decimal_8);
  tcase_add_test(tc_int_to_decimal, int_to_decimal_9);
  tcase_add_test(tc_int_to_decimal, int_to_decimal_10);
  tcase_add_test(tc_int_to_decimal, int_to_decimal_11);
  tcase_add_test(tc_int_to_decimal, int_to_decimal_12);
  tcase_add_test(tc_int_to_decimal, int_to_decimal_13);
  tcase_add_test(tc_int_to_decimal, int_to_decimal_14);
  tcase_add_test(tc_int_to_decimal, int_to_decimal_15);
  tcase_add_test(tc_int_to_decimal, int_to_decimal_16);
  tcase_add_test(tc_int_to_decimal, int_to_decimal_17);
  tcase_add_test(tc_int_to_decimal, int_to_decimal_18);
  tcase_add_test(tc_int_to_decimal, int_to_decimal_19);
  tcase_add_test(tc_int_to_decimal, int_to_decimal_20);
  tcase_add_test(tc_int_to_decimal, int_to_decimal_21);
  suite_add_tcase(s, tc_int_to_decimal);

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
