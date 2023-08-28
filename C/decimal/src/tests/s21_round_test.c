#include "../header.h"

//-377235916395321260789.76 Подаем
START_TEST(round_1) {
  s21_decimal d = {0};
  s21_decimal result = {0};
  char result_true[] = "-377235916395321260790";
  char result_func[1024];
  d.bits[0] = 2048;
  d.bits[1] = 2048;
  d.bits[2] = 2045;
  d.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(2, &d);
  s21_round(d, &result);
  dec_to_string(&result, result_func);
  ck_assert_str_eq(result_true, result_func);
}
END_TEST

// 377235916395321260789.76 Подаем
START_TEST(round_2) {
  s21_decimal d = {0};
  s21_decimal result = {0};
  char result_true[] = "377235916395321260790";
  char result_func[1024];
  d.bits[0] = 2048;
  d.bits[1] = 2048;
  d.bits[2] = 2045;
  zapis_stepeni_v_decimal(2, &d);
  s21_round(d, &result);
  dec_to_string(&result, result_func);
  ck_assert_str_eq(result_true, result_func);
}
END_TEST

// 37723591639532126078976 Подаем
START_TEST(round_3) {
  s21_decimal d = {0};
  s21_decimal result = {0};
  char result_true[] = "37723591639532126078976";
  char result_func[1024];
  d.bits[0] = 2048;
  d.bits[1] = 2048;
  d.bits[2] = 2045;
  zapis_stepeni_v_decimal(0, &d);
  s21_round(d, &result);
  dec_to_string(&result, result_func);
  ck_assert_str_eq(result_true, result_func);
}
END_TEST

// -37723591639532126078976 Подаем
START_TEST(round_4) {
  s21_decimal d = {0};
  s21_decimal result = {0};
  char result_true[] = "-37723591639532126078976";
  char result_func[1024];
  d.bits[0] = 2048;
  d.bits[1] = 2048;
  d.bits[2] = 2045;
  d.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(0, &d);
  s21_round(d, &result);
  dec_to_string(&result, result_func);
  ck_assert_str_eq(result_true, result_func);
}
END_TEST

// Подаем 0.1
START_TEST(round_5) {
  s21_decimal d = {0};
  s21_decimal result = {0};
  char result_true[] = "0";
  char result_func[1024];
  d.bits[0] = 1;
  d.bits[1] = 0;
  d.bits[2] = 0;
  zapis_stepeni_v_decimal(1, &d);
  s21_round(d, &result);
  dec_to_string(&result, result_func);
  ck_assert_str_eq(result_true, result_func);
}
END_TEST

//-37723591639532126.078976 Подаем
START_TEST(round_6) {
  s21_decimal d = {0};
  s21_decimal result = {0};
  char result_true[] = "-37723591639532126";
  char result_func[1024];
  d.bits[0] = 2048;
  d.bits[1] = 2048;
  d.bits[2] = 2045;
  d.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(6, &d);
  s21_round(d, &result);
  dec_to_string(&result, result_func);
  ck_assert_str_eq(result_true, result_func);
}
END_TEST

// 37723591639532126.078976 Подаем
START_TEST(round_7) {
  s21_decimal d = {0};
  s21_decimal result = {0};
  char result_true[] = "37723591639532126";
  char result_func[1024];
  d.bits[0] = 2048;
  d.bits[1] = 2048;
  d.bits[2] = 2045;
  zapis_stepeni_v_decimal(6, &d);
  s21_round(d, &result);
  dec_to_string(&result, result_func);
  ck_assert_str_eq(result_true, result_func);
}
END_TEST

START_TEST(round_8) {
  s21_decimal d = {0};
  s21_decimal result = {0};
  char result_true[] = "-18907912675552290406400";
  char result_func[1024];
  d.bits[0] = 2147483647;
  d.bits[0] |= SIGN;
  d.bits[1] = 2147483647;
  d.bits[1] |= SIGN;
  d.bits[2] = 10249;
  d.bits[3] = SIGN;
  zapis_stepeni_v_decimal(1, &d);
  s21_round(d, &result);
  dec_to_string(&result, result_func);
  ck_assert_str_eq(result_true, result_func);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_round;

  s = suite_create("s21_round");

  tc_round = tcase_create("s21_round");
  tcase_add_test(tc_round, round_1);
  tcase_add_test(tc_round, round_2);
  tcase_add_test(tc_round, round_3);
  tcase_add_test(tc_round, round_4);
  tcase_add_test(tc_round, round_5);
  tcase_add_test(tc_round, round_6);
  tcase_add_test(tc_round, round_7);
  tcase_add_test(tc_round, round_8);
  suite_add_tcase(s, tc_round);

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
