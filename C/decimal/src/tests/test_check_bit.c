#include "../header.h"

START_TEST(checkbit_1) {
  u_int32_t val = {157};
  ck_assert_int_eq(checkbit(val, 4), 1);
}
END_TEST

START_TEST(checkbit_2) {
  u_int32_t val = {157};
  ck_assert_int_eq(checkbit(val, 0), 1);
}
END_TEST

START_TEST(checkbit_3) {
  u_int32_t val = {157};
  ck_assert_int_eq(checkbit(val, 31), 0);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_is_checkbit;

  s = suite_create("checkbit");

  tc_is_checkbit = tcase_create("checkbit");
  tcase_add_test(tc_is_checkbit, checkbit_1);
  tcase_add_test(tc_is_checkbit, checkbit_2);
  tcase_add_test(tc_is_checkbit, checkbit_3);
  suite_add_tcase(s, tc_is_checkbit);

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