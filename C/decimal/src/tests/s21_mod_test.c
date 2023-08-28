#include "../header.h"

// MAX_DECIMAL 79228162514264337593543950335

START_TEST(mod_1) {
  char s21_result[BUF] = {'\0'};
  char *a = "79228162514264337593543950334";
  char *b = "1";
  char *result = "0";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mod(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(mod_2) {
  char *a = "79228162514264337593543950334";
  char *b = "0";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mod(number1, number2, &dec_result);
  ck_assert_int_eq(exit_code, 3);
}
END_TEST

START_TEST(mod_3) {
  char s21_result[BUF] = {'\0'};
  char *a = "79228162514264337593543950334";
  char *b = "79228162514264337593543950334";
  char *result = "0";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mod(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(mod_4) {
  char s21_result[BUF] = {'\0'};
  char *a = "7922816251426";
  char *b = "0.001";
  char *result = "0";
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  number1 = char_to_decimal(a);
  number2 = char_to_decimal(b);
  s21_decimal dec_result = {0};
  int exit_code = 0;
  exit_code = s21_mod(number1, number2, &dec_result);
  dec_to_string(&dec_result, s21_result);
  ck_assert_str_eq(result, s21_result);
  ck_assert_int_eq(exit_code, 0);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_mod;

  s = suite_create("s21_mod");

  tc_mod = tcase_create("s21_mod");
  tcase_add_test(tc_mod, mod_1);
  tcase_add_test(tc_mod, mod_2);
  tcase_add_test(tc_mod, mod_3);
  tcase_add_test(tc_mod, mod_4);
  suite_add_tcase(s, tc_mod);

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
