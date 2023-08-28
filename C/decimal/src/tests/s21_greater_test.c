#include "../header.h"

START_TEST(greater_1) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 2048;
  d.bits[1] = 2048;
  d.bits[2] = 2045;
  d.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(0, &d);
  d1.bits[0] = 2048;
  d1.bits[1] = 2048;
  d1.bits[2] = 2046;
  d1.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(0, &d1);
  ck_assert_int_eq(s21_is_greater(d, d1), 1);
}
END_TEST

START_TEST(greater_2) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 2048;
  d.bits[1] = 2048;
  d.bits[2] = 2046;
  zapis_stepeni_v_decimal(12, &d);
  d1.bits[0] = 2047;
  d1.bits[1] = 2048;
  d1.bits[2] = 2046;
  zapis_stepeni_v_decimal(0, &d1);
  ck_assert_int_eq(s21_is_greater(d, d1), 0);
}
END_TEST

START_TEST(greater_3) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 0;
  d.bits[1] = 0;
  d.bits[2] = 0;
  zapis_stepeni_v_decimal(0, &d);
  d1.bits[0] = 0;
  d1.bits[1] = 0;
  d1.bits[2] = 0;
  d1.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(0, &d1);
  ck_assert_int_eq(s21_is_greater(d, d1), 0);
}
END_TEST

START_TEST(greater_4) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 2346;
  d.bits[1] = 1242;
  d.bits[2] = 124;
  zapis_stepeni_v_decimal(0, &d);
  d1.bits[0] = 3782;
  d1.bits[1] = 1512;
  d1.bits[2] = 123;
  zapis_stepeni_v_decimal(0, &d1);
  ck_assert_int_eq(s21_is_greater(d, d1), 1);
}
END_TEST

START_TEST(greater_5) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 2346;
  d.bits[1] = 1242;
  d.bits[2] = 124;
  d.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(0, &d);
  d1.bits[0] = 3782;
  d1.bits[1] = 1512;
  d1.bits[2] = 123;
  d1.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(0, &d1);
  ck_assert_int_eq(s21_is_greater(d, d1), 0);
}
END_TEST

START_TEST(greater_6) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 2346;
  d.bits[1] = 1242;
  d.bits[2] = 124;
  zapis_stepeni_v_decimal(10, &d);
  d1.bits[0] = 3782;
  d1.bits[1] = 1512;
  d1.bits[2] = 123;
  zapis_stepeni_v_decimal(12, &d1);
  ck_assert_int_eq(s21_is_greater(d, d1), 1);
}
END_TEST

START_TEST(greater_7) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 2346;
  d.bits[1] = 1242;
  d.bits[2] = 124;
  d.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(10, &d);
  d1.bits[0] = 3782;
  d1.bits[1] = 1512;
  d1.bits[2] = 123;
  d1.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(12, &d1);
  ck_assert_int_eq(s21_is_greater(d, d1), 0);
}
END_TEST

START_TEST(greater_8) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 2346;
  d.bits[1] = 1242;
  d.bits[2] = 124;
  zapis_stepeni_v_decimal(12, &d);
  d1.bits[0] = 3782;
  d1.bits[1] = 1512;
  d1.bits[2] = 123;
  zapis_stepeni_v_decimal(10, &d1);
  ck_assert_int_eq(s21_is_greater(d, d1), 0);
}
END_TEST

START_TEST(greater_9) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 3782;
  d.bits[1] = 1512;
  d.bits[2] = 123;
  zapis_stepeni_v_decimal(12, &d);
  d1.bits[0] = 3782;
  d1.bits[1] = 1512;
  d1.bits[2] = 123;
  zapis_stepeni_v_decimal(10, &d1);
  ck_assert_int_eq(s21_is_greater(d, d1), 0);
}
END_TEST

START_TEST(greater_10) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 3782;
  d.bits[1] = 1512;
  d.bits[2] = 123;
  zapis_stepeni_v_decimal(12, &d);
  d1.bits[0] = 3782;
  d1.bits[1] = 1512;
  d1.bits[2] = 123;
  zapis_stepeni_v_decimal(12, &d1);
  ck_assert_int_eq(s21_is_greater(d, d1), 0);
}
END_TEST

START_TEST(greater_11) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 3782;
  d.bits[1] = 1512;
  d.bits[2] = 123;
  d.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(12, &d);
  d1.bits[0] = 3782;
  d1.bits[1] = 1512;
  d1.bits[2] = 123;
  d1.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(12, &d1);
  ck_assert_int_eq(s21_is_greater(d, d1), 0);
}
END_TEST

START_TEST(greater_12) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 0;
  d.bits[1] = 0;
  d.bits[2] = 0;
  zapis_stepeni_v_decimal(0, &d);
  d1.bits[0] = 0;
  d1.bits[1] = 0;
  d1.bits[2] = 0;
  zapis_stepeni_v_decimal(0, &d1);
  ck_assert_int_eq(s21_is_greater(d, d1), 0);
}
END_TEST

START_TEST(greater_13) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 2000;
  d.bits[1] = 0;
  d.bits[2] = 0;
  zapis_stepeni_v_decimal(2, &d);
  d1.bits[0] = 20;
  d1.bits[1] = 0;
  d1.bits[2] = 0;
  zapis_stepeni_v_decimal(0, &d1);
  ck_assert_int_eq(s21_is_greater(d, d1), 0);
}
END_TEST

START_TEST(greater_14) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 2001;
  d.bits[1] = 0;
  d.bits[2] = 0;
  zapis_stepeni_v_decimal(2, &d);
  d1.bits[0] = 20;
  d1.bits[1] = 0;
  d1.bits[2] = 0;
  zapis_stepeni_v_decimal(0, &d1);
  ck_assert_int_eq(s21_is_greater(d, d1), 1);
}
END_TEST

START_TEST(greater_15) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 2001;
  d.bits[1] = 0;
  d.bits[2] = 0;
  zapis_stepeni_v_decimal(0, &d);
  d1.bits[0] = 2001;
  d1.bits[1] = 0;
  d1.bits[2] = 0;
  d1.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(0, &d1);
  ck_assert_int_eq(s21_is_greater(d, d1), 1);
}
END_TEST

START_TEST(greater_16) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 2000;
  d.bits[1] = 0;
  d.bits[2] = 0;
  zapis_stepeni_v_decimal(2, &d);
  d1.bits[0] = 2001;
  d1.bits[1] = 0;
  d1.bits[2] = 0;
  d1.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(2, &d1);
  ck_assert_int_eq(s21_is_greater(d, d1), 1);
}
END_TEST

START_TEST(greater_17) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 20;
  d.bits[1] = 0;
  d.bits[2] = 0;
  d.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(0, &d);
  d1.bits[0] = 2000;
  d1.bits[1] = 0;
  d1.bits[2] = 0;
  d1.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(2, &d1);
  ck_assert_int_eq(s21_is_greater(d, d1), 0);
}
END_TEST

START_TEST(greater_18) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 2000;
  d.bits[1] = 0;
  d.bits[2] = 0;
  zapis_stepeni_v_decimal(2, &d);
  d1.bits[0] = 2001;
  d1.bits[1] = 0;
  d1.bits[2] = 0;
  zapis_stepeni_v_decimal(2, &d1);
  ck_assert_int_eq(s21_is_greater(d, d1), 0);
}
END_TEST

START_TEST(greater_19) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 20;
  d.bits[1] = 0;
  d.bits[2] = 0;
  d.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(0, &d);
  d1.bits[0] = 2001;
  d1.bits[1] = 0;
  d1.bits[2] = 0;
  d1.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(2, &d1);
  ck_assert_int_eq(s21_is_greater(d, d1), 1);
}
END_TEST

START_TEST(greater_20) {
  char *a = "79228162514264337593543950335";
  char *b = "79228162514264337593543950335";
  s21_decimal src = {0};
  s21_decimal dst = {0};
  src = char_to_decimal(a);
  dst = char_to_decimal(b);
  ck_assert_int_eq(s21_is_greater(src, dst), 0);
}
END_TEST

START_TEST(greater_21) {
  char *a = "79228162514264337593543950334";
  char *b = "79228162514264337593543950.334";
  s21_decimal src = {0};
  s21_decimal dst = {0};
  src = char_to_decimal(a);
  dst = char_to_decimal(b);
  ck_assert_int_eq(s21_is_greater(src, dst), 1);
}
END_TEST

START_TEST(greater_22) {
  char *a = "0";
  char *b = "-0";
  s21_decimal src = {0};
  s21_decimal dst = {0};
  src = char_to_decimal(a);
  dst = char_to_decimal(b);
  ck_assert_int_eq(s21_is_greater(src, dst), 0);
}
END_TEST

START_TEST(greater_23) {
  char *a = "79228162514264337593543950334";
  char *b = "-79228162514264337593543950.334";
  s21_decimal src = {0};
  s21_decimal dst = {0};
  src = char_to_decimal(a);
  dst = char_to_decimal(b);
  ck_assert_int_eq(s21_is_greater(src, dst), 1);
}
END_TEST

START_TEST(greater_24) {
  char *a = "-79228162514264337593543950334";
  char *b = "79228162514264337593543950.334";
  s21_decimal src = {0};
  s21_decimal dst = {0};
  src = char_to_decimal(a);
  dst = char_to_decimal(b);
  ck_assert_int_eq(s21_is_greater(src, dst), 0);
}
END_TEST

START_TEST(greater_25) {
  char *a = "792";
  char *b = "792";
  s21_decimal src = {0};
  s21_decimal dst = {0};
  src = char_to_decimal(a);
  dst = char_to_decimal(b);
  ck_assert_int_eq(s21_is_greater(src, dst), 0);
}
END_TEST

START_TEST(greater_26) {
  char *a = "792";
  char *b = "-792";
  s21_decimal src = {0};
  s21_decimal dst = {0};
  src = char_to_decimal(a);
  dst = char_to_decimal(b);
  ck_assert_int_eq(s21_is_greater(src, dst), 1);
}
END_TEST

START_TEST(greater_27) {
  char *a = "-792";
  char *b = "792";
  s21_decimal src = {0};
  s21_decimal dst = {0};
  src = char_to_decimal(a);
  dst = char_to_decimal(b);
  ck_assert_int_eq(s21_is_greater(src, dst), 0);
}
END_TEST

START_TEST(greater_28) {
  char *a = "-791";
  char *b = "-792";
  s21_decimal src = {0};
  s21_decimal dst = {0};
  src = char_to_decimal(a);
  dst = char_to_decimal(b);
  ck_assert_int_eq(s21_is_greater(src, dst), 1);
}
END_TEST

START_TEST(greater_29) {
  char *a = "-792";
  char *b = "-792.01";
  s21_decimal src = {0};
  s21_decimal dst = {0};
  src = char_to_decimal(a);
  dst = char_to_decimal(b);
  ck_assert_int_eq(s21_is_greater(src, dst), 1);
}
END_TEST

START_TEST(greater_30) {
  char *a = "-792.0100";
  char *b = "-7921.010";
  s21_decimal src = {0};
  s21_decimal dst = {0};
  src = char_to_decimal(a);
  dst = char_to_decimal(b);
  ck_assert_int_eq(s21_is_greater(src, dst), 1);
}
END_TEST

START_TEST(greater_31) {
  char *a = "792.9100";
  char *b = "7921.010";
  s21_decimal src = {0};
  s21_decimal dst = {0};
  src = char_to_decimal(a);
  dst = char_to_decimal(b);
  ck_assert_int_eq(s21_is_greater(src, dst), 0);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_is_greater;

  s = suite_create("s21_is_greater");

  tc_is_greater = tcase_create("s21_is_greater");
  tcase_add_test(tc_is_greater, greater_1);
  tcase_add_test(tc_is_greater, greater_2);
  tcase_add_test(tc_is_greater, greater_3);
  tcase_add_test(tc_is_greater, greater_4);
  tcase_add_test(tc_is_greater, greater_5);
  tcase_add_test(tc_is_greater, greater_6);
  tcase_add_test(tc_is_greater, greater_7);
  tcase_add_test(tc_is_greater, greater_8);
  tcase_add_test(tc_is_greater, greater_9);
  tcase_add_test(tc_is_greater, greater_10);
  tcase_add_test(tc_is_greater, greater_11);
  tcase_add_test(tc_is_greater, greater_12);
  tcase_add_test(tc_is_greater, greater_13);
  tcase_add_test(tc_is_greater, greater_14);
  tcase_add_test(tc_is_greater, greater_15);
  tcase_add_test(tc_is_greater, greater_16);
  tcase_add_test(tc_is_greater, greater_17);
  tcase_add_test(tc_is_greater, greater_18);
  tcase_add_test(tc_is_greater, greater_19);

  tcase_add_test(tc_is_greater, greater_20);
  tcase_add_test(tc_is_greater, greater_21);
  tcase_add_test(tc_is_greater, greater_22);
  tcase_add_test(tc_is_greater, greater_23);
  tcase_add_test(tc_is_greater, greater_24);
  tcase_add_test(tc_is_greater, greater_25);
  tcase_add_test(tc_is_greater, greater_26);
  tcase_add_test(tc_is_greater, greater_27);
  tcase_add_test(tc_is_greater, greater_28);
  tcase_add_test(tc_is_greater, greater_29);
  tcase_add_test(tc_is_greater, greater_30);
  tcase_add_test(tc_is_greater, greater_31);
  suite_add_tcase(s, tc_is_greater);

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
