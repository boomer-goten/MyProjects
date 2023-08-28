#include "../header.h"

START_TEST(credit_1) {
  char *summ = "";
  char *srok = "";
  char *proc_stavka = "";
  int type = 0;
  char *result_platezh = "";
  double result_sum = 0;
  double result_proc = 0;
  ck_assert_int_eq(credit(summ, srok, proc_stavka, &type, result_platezh,
                          &result_proc, &result_sum),
                   BAD_EXPRESSION);
}
END_TEST

START_TEST(credit_2) {
  char *summ = "";
  char *srok = "";
  char *proc_stavka = "";
  int type = 1;
  char *result_platezh = "";
  double result_sum = 0;
  double result_proc = 0;
  ck_assert_int_eq(credit(summ, srok, proc_stavka, &type, result_platezh,
                          &result_proc, &result_sum),
                   BAD_EXPRESSION);
}
END_TEST

START_TEST(credit_3) {
  char *summ = "0";
  char *srok = "0";
  char *proc_stavka = "0";
  int type = 1;
  char result_platezh[100] = "\0";
  memset(result_platezh, '\0', 100);
  double result_sum = 0;
  double result_proc = 0;
  ck_assert_int_eq(credit(summ, srok, proc_stavka, &type, result_platezh,
                          &result_proc, &result_sum),
                   BAD_EXPRESSION);
}
END_TEST

START_TEST(credit_4) {
  char *summ = "0";
  char *srok = "0";
  char *proc_stavka = "0";
  int type = 0;
  char result_platezh[100] = "\0";
  memset(result_platezh, '\0', 100);
  double result_sum = 0;
  double result_proc = 0;
  ck_assert_int_eq(credit(summ, srok, proc_stavka, &type, result_platezh,
                          &result_proc, &result_sum),
                   BAD_EXPRESSION);
}
END_TEST

START_TEST(credit_5) {
  char *summ = "5";
  char *srok = "124";
  char *proc_stavka = "0";
  int type = 0;
  char result_platezh[100] = "\0";
  memset(result_platezh, '\0', 100);
  double result_sum = 0;
  double result_proc = 0;
  ck_assert_int_eq(credit(summ, srok, proc_stavka, &type, result_platezh,
                          &result_proc, &result_sum),
                   OK);
}
END_TEST

START_TEST(credit_6) {
  char *summ = "1000000";
  char *srok = "12";
  char *proc_stavka = "12";
  int type = 0;
  char result_platezh[100] = "\0";
  memset(result_platezh, '\0', 100);
  double result_sum = 0;
  double result_proc = 0;
  int status = credit(summ, srok, proc_stavka, &type, result_platezh,
                      &result_proc, &result_sum);
  double result_sum_true = 1066185.464140;
  double result_proc_true = 66185.464140;
  char *result_platezh_true = "88848.788678";
  //   printf("result_sum=%lf", result_sum);
  //   printf("result_proc=%lf", result_proc);
  //   printf("result_platezh=%s", result_platezh);
  if ((fabs(result_sum_true) - fabs(result_sum) < 1e-7) &&
      (fabs(result_proc_true) - fabs(result_proc) < 1e-7) &&
      strcmp(result_platezh, result_platezh_true) == 0) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, BAD_EXPRESSION);
  }
}
END_TEST

START_TEST(credit_7) {
  char *summ = "1000000";
  char *srok = "12";
  char *proc_stavka = "12";
  int type = 1;
  char result_platezh[100] = "\0";
  memset(result_platezh, '\0', 100);
  double result_sum = 0;
  double result_proc = 0;
  int status = credit(summ, srok, proc_stavka, &type, result_platezh,
                      &result_proc, &result_sum);
  double result_sum_true = 1065000.000000;
  double result_proc_true = 65000.000000;
  char *result_platezh_true = "93333.333333...84166.666667";
  if ((fabs(result_sum_true) - fabs(result_sum) < 1e-7) &&
      (fabs(result_proc_true) - fabs(result_proc) < 1e-7) &&
      strcmp(result_platezh, result_platezh_true) == 0) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, BAD_EXPRESSION);
  }
}
END_TEST

START_TEST(credit_8) {
  char *summ = "5";
  char *srok = "124";
  char *proc_stavka = "0";
  int type = 1;
  char result_platezh[100] = "\0";
  memset(result_platezh, '\0', 100);
  double result_sum = 0;
  double result_proc = 0;
  int status = credit(summ, srok, proc_stavka, &type, result_platezh,
                      &result_proc, &result_sum);
  double result_sum_true = 5.000000;
  double result_proc_true = 0.000000;
  char *result_platezh_true = "0.040323...0.040323";
  if ((fabs(result_sum_true) - fabs(result_sum) < 1e-7) &&
      (fabs(result_proc_true) - fabs(result_proc) < 1e-7) &&
      strcmp(result_platezh, result_platezh_true) == 0) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, BAD_EXPRESSION);
  }
}
END_TEST

START_TEST(credit_9) {
  char *summ = "-5";
  char *srok = "124";
  char *proc_stavka = "0";
  int type = 0;
  char result_platezh[100] = "\0";
  memset(result_platezh, '\0', 100);
  double result_sum = 0;
  double result_proc = 0;
  ck_assert_int_eq(credit(summ, srok, proc_stavka, &type, result_platezh,
                          &result_proc, &result_sum),
                   BAD_EXPRESSION);
}
END_TEST

START_TEST(credit_10) {
  char *summ = "5";
  char *srok = "-124";
  char *proc_stavka = "0";
  int type = 0;
  char result_platezh[100] = "\0";
  memset(result_platezh, '\0', 100);
  double result_sum = 0;
  double result_proc = 0;
  ck_assert_int_eq(credit(summ, srok, proc_stavka, &type, result_platezh,
                          &result_proc, &result_sum),
                   BAD_EXPRESSION);
}
END_TEST

START_TEST(credit_11) {
  char *summ = "5";
  char *srok = "124";
  char *proc_stavka = "-5";
  int type = 0;
  char result_platezh[100] = "\0";
  memset(result_platezh, '\0', 100);
  double result_sum = 0;
  double result_proc = 0;
  ck_assert_int_eq(credit(summ, srok, proc_stavka, &type, result_platezh,
                          &result_proc, &result_sum),
                   BAD_EXPRESSION);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_credit;

  s = suite_create("credit");

  tc_credit = tcase_create("credit");
  tcase_add_test(tc_credit, credit_1);
  tcase_add_test(tc_credit, credit_2);
  tcase_add_test(tc_credit, credit_3);
  tcase_add_test(tc_credit, credit_4);
  tcase_add_test(tc_credit, credit_5);
  tcase_add_test(tc_credit, credit_6);
  tcase_add_test(tc_credit, credit_7);
  tcase_add_test(tc_credit, credit_8);
  tcase_add_test(tc_credit, credit_9);
  tcase_add_test(tc_credit, credit_10);
  tcase_add_test(tc_credit, credit_11);
  suite_add_tcase(s, tc_credit);

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
