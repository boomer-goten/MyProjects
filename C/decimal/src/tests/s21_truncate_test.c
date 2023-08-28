#include "../header.h"

//-377235916395321260789.76 Подаем
START_TEST(truncate_1) {
  s21_decimal d = {0};
  s21_decimal result = {0};
  char result_true[] = "-377235916395321260789";
  char result_func[1024];
  d.bits[0] = 2048;
  d.bits[1] = 2048;
  d.bits[2] = 2045;
  d.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(2, &d);
  s21_truncate(d, &result);
  dec_to_string(&result, result_func);
  ck_assert_str_eq(result_true, result_func);
}
END_TEST

// 377235916395321260789.76 Подаем
START_TEST(truncate_2) {
  s21_decimal d = {0};
  s21_decimal result = {0};
  char result_true[] = "377235916395321260789";
  char result_func[1024];
  d.bits[0] = 2048;
  d.bits[1] = 2048;
  d.bits[2] = 2045;
  zapis_stepeni_v_decimal(2, &d);
  s21_truncate(d, &result);
  dec_to_string(&result, result_func);
  ck_assert_str_eq(result_true, result_func);
}
END_TEST

// 37723591639532126078976 Подаем
START_TEST(truncate_3) {
  s21_decimal d = {0};
  s21_decimal result = {0};
  char result_true[] = "37723591639532126078976";
  char result_func[1024];
  d.bits[0] = 2048;
  d.bits[1] = 2048;
  d.bits[2] = 2045;
  zapis_stepeni_v_decimal(0, &d);
  s21_truncate(d, &result);
  dec_to_string(&result, result_func);
  ck_assert_str_eq(result_true, result_func);
}
END_TEST

// -37723591639532126078976 Подаем
START_TEST(truncate_4) {
  s21_decimal d = {0};
  s21_decimal result = {0};
  char result_true[] = "-37723591639532126078976";
  char result_func[1024];
  d.bits[0] = 2048;
  d.bits[1] = 2048;
  d.bits[2] = 2045;
  d.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(0, &d);
  s21_truncate(d, &result);
  dec_to_string(&result, result_func);
  ck_assert_str_eq(result_true, result_func);
}
END_TEST

// Подаем 0.1
START_TEST(truncate_5) {
  s21_decimal d = {0};
  s21_decimal result = {0};
  char result_true[] = "0";
  char result_func[1024];
  d.bits[0] = 1;
  d.bits[1] = 0;
  d.bits[2] = 0;
  zapis_stepeni_v_decimal(1, &d);
  s21_truncate(d, &result);
  dec_to_string(&result, result_func);
  ck_assert_str_eq(result_true, result_func);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_truncate;

  s = suite_create("s21_truncate");

  tc_truncate = tcase_create("s21_truncate");
  tcase_add_test(tc_truncate, truncate_1);
  tcase_add_test(tc_truncate, truncate_2);
  tcase_add_test(tc_truncate, truncate_3);
  tcase_add_test(tc_truncate, truncate_4);
  tcase_add_test(tc_truncate, truncate_5);
  suite_add_tcase(s, tc_truncate);

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
