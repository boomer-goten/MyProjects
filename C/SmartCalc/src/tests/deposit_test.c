#include "../header.h"

START_TEST(deposit_1) {
  char *sum_dep = "1000000";
  char *srok_dep = "24";
  char *date_dep = "22.02.23";
  char *proc_dep = "13";
  char *nalog_dep = "13";
  char *popol_mes_dep = "0";
  char *sum_popol_dep = "0";
  char *snyatiya_mes_dep = "0";
  char *snyatiya_sum_dep = "0";
  char *spisok_popol_dep = "Нет";
  char *spisok_snyatiya_dep = "Нет";
  char *spisok_period_dep = "раз в месяц";
  int type = 0;
  double result_procent = 0;
  double result_nalog = 0;
  double result_deposit = 0;
  double result_procent_true = 260000.000000;
  double result_nalog_true = 11483.333333;
  double result_deposit_true = 1000000.000000;
  int status =
      deposit(sum_dep, srok_dep, date_dep, proc_dep, nalog_dep, popol_mes_dep,
              sum_popol_dep, snyatiya_mes_dep, snyatiya_sum_dep,
              spisok_popol_dep, spisok_snyatiya_dep, spisok_period_dep, &type,
              &result_procent, &result_nalog, &result_deposit);
  if ((fabs(result_procent_true) - fabs(result_procent) < 1e-7) &&
      (fabs(result_nalog_true) - fabs(result_nalog) < 1e-7) &&
      (fabs(result_deposit_true) - fabs(result_deposit) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, BAD_EXPRESSION);
  }
}
END_TEST

START_TEST(deposit_2) {
  char *sum_dep = "1000000";
  char *srok_dep = "24";
  char *date_dep = "22.02.23";
  char *proc_dep = "13";
  char *nalog_dep = "13";
  char *popol_mes_dep = "0";
  char *sum_popol_dep = "0";
  char *snyatiya_mes_dep = "0";
  char *snyatiya_sum_dep = "0";
  char *spisok_popol_dep = "Нет";
  char *spisok_snyatiya_dep = "Нет";
  char *spisok_period_dep = "раз в месяц";
  int type = 1;
  double result_procent = 0;
  double result_nalog = 0;
  double result_deposit = 0;
  double result_procent_true = 295117.929208;
  double result_nalog_true = 15275.849123;
  double result_deposit_true = 1295117.929208;
  int status =
      deposit(sum_dep, srok_dep, date_dep, proc_dep, nalog_dep, popol_mes_dep,
              sum_popol_dep, snyatiya_mes_dep, snyatiya_sum_dep,
              spisok_popol_dep, spisok_snyatiya_dep, spisok_period_dep, &type,
              &result_procent, &result_nalog, &result_deposit);
  if ((fabs(result_procent_true) - fabs(result_procent) < 1e-6) &&
      (fabs(result_nalog_true) - fabs(result_nalog) < 1e-6) &&
      (fabs(result_deposit_true) - fabs(result_deposit) < 1e-6)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, BAD_EXPRESSION);
  }
}
END_TEST

START_TEST(deposit_3) {
  char *sum_dep = "1000000";
  char *srok_dep = "24";
  char *date_dep = "22.02.23";
  char *proc_dep = "0";
  char *nalog_dep = "0";
  char *popol_mes_dep = "0";
  char *sum_popol_dep = "0";
  char *snyatiya_mes_dep = "0";
  char *snyatiya_sum_dep = "0";
  char *spisok_popol_dep = "Нет";
  char *spisok_snyatiya_dep = "Нет";
  char *spisok_period_dep = "раз в месяц";
  int type = 1;
  double result_procent = 0;
  double result_nalog = 0;
  double result_deposit = 0;
  double result_procent_true = 0;
  double result_nalog_true = 0;
  double result_deposit_true = 1000000.000000;
  int status =
      deposit(sum_dep, srok_dep, date_dep, proc_dep, nalog_dep, popol_mes_dep,
              sum_popol_dep, snyatiya_mes_dep, snyatiya_sum_dep,
              spisok_popol_dep, spisok_snyatiya_dep, spisok_period_dep, &type,
              &result_procent, &result_nalog, &result_deposit);
  if ((fabs(result_procent_true) - fabs(result_procent) < 1e-7) &&
      (fabs(result_nalog_true) - fabs(result_nalog) < 1e-7) &&
      (fabs(result_deposit_true) - fabs(result_deposit) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, BAD_EXPRESSION);
  }
}
END_TEST

START_TEST(deposit_4) {
  char *sum_dep = "1000000";
  char *srok_dep = "24";
  char *date_dep = "22.02.23";
  char *proc_dep = "12";
  char *nalog_dep = "13";
  char *popol_mes_dep = "0";
  char *sum_popol_dep = "0";
  char *snyatiya_mes_dep = "0";
  char *snyatiya_sum_dep = "0";
  char *spisok_popol_dep = "Нет";
  char *spisok_snyatiya_dep = "Нет";
  char *spisok_period_dep = "раз в год";
  int type = 1;
  double result_procent = 0;
  double result_nalog = 0;
  double result_deposit = 0;
  double result_procent_true = 254400.000000;
  double result_nalog_true = 13572.000000;
  double result_deposit_true = 1254400.000000;
  int status =
      deposit(sum_dep, srok_dep, date_dep, proc_dep, nalog_dep, popol_mes_dep,
              sum_popol_dep, snyatiya_mes_dep, snyatiya_sum_dep,
              spisok_popol_dep, spisok_snyatiya_dep, spisok_period_dep, &type,
              &result_procent, &result_nalog, &result_deposit);
  if ((fabs(result_procent_true) - fabs(result_procent) < 1e-7) &&
      (fabs(result_nalog_true) - fabs(result_nalog) < 1e-7) &&
      (fabs(result_deposit_true) - fabs(result_deposit) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, BAD_EXPRESSION);
  }
}
END_TEST

START_TEST(deposit_5) {
  char *sum_dep = "1000000";
  char *srok_dep = "24";
  char *date_dep = "22.02.23";
  char *proc_dep = "0";
  char *nalog_dep = "0";
  char *popol_mes_dep = "23.05.24";
  char *sum_popol_dep = "10000";
  char *snyatiya_mes_dep = "0";
  char *snyatiya_sum_dep = "0";
  char *spisok_popol_dep = "Раз в месяц";
  char *spisok_snyatiya_dep = "Нет";
  char *spisok_period_dep = "раз в год";
  int type = 1;
  double result_procent = 0;
  double result_nalog = 0;
  double result_deposit = 0;
  double result_procent_true = 0.000000;
  double result_nalog_true = 0.000000;
  double result_deposit_true = 109000.000000;
  int status =
      deposit(sum_dep, srok_dep, date_dep, proc_dep, nalog_dep, popol_mes_dep,
              sum_popol_dep, snyatiya_mes_dep, snyatiya_sum_dep,
              spisok_popol_dep, spisok_snyatiya_dep, spisok_period_dep, &type,
              &result_procent, &result_nalog, &result_deposit);
  if ((fabs(result_procent_true) - fabs(result_procent) < 1e-7) &&
      (fabs(result_nalog_true) - fabs(result_nalog) < 1e-7) &&
      (fabs(result_deposit_true) - fabs(result_deposit) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, BAD_EXPRESSION);
  }
}
END_TEST

START_TEST(deposit_6) {
  char *sum_dep = "1000000";
  char *srok_dep = "24";
  char *date_dep = "22.02.23";
  char *proc_dep = "0";
  char *nalog_dep = "0";
  char *popol_mes_dep = "23.05.24";
  char *sum_popol_dep = "10000";
  char *snyatiya_mes_dep = "0";
  char *snyatiya_sum_dep = "0";
  char *spisok_popol_dep = "Раз в месяц";
  char *spisok_snyatiya_dep = "Нет";
  char *spisok_period_dep = "раз в год";
  int type = 0;
  double result_procent = 0;
  double result_nalog = 0;
  double result_deposit = 0;
  double result_procent_true = 0.000000;
  double result_nalog_true = 0.000000;
  double result_deposit_true = 1090000.000000;
  int status =
      deposit(sum_dep, srok_dep, date_dep, proc_dep, nalog_dep, popol_mes_dep,
              sum_popol_dep, snyatiya_mes_dep, snyatiya_sum_dep,
              spisok_popol_dep, spisok_snyatiya_dep, spisok_period_dep, &type,
              &result_procent, &result_nalog, &result_deposit);
  if ((fabs(result_procent_true) - fabs(result_procent) < 1e-7) &&
      (fabs(result_nalog_true) - fabs(result_nalog) < 1e-7) &&
      (fabs(result_deposit_true) - fabs(result_deposit) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, BAD_EXPRESSION);
  }
}
END_TEST

START_TEST(deposit_7) {
  char *sum_dep = "1000000";
  char *srok_dep = "24";
  char *date_dep = "22.02.23";
  char *proc_dep = "12";
  char *nalog_dep = "13";
  char *popol_mes_dep = "0";
  char *sum_popol_dep = "0";
  char *snyatiya_mes_dep = "23.05.24";
  char *snyatiya_sum_dep = "10000";
  char *spisok_popol_dep = "Нет";
  char *spisok_snyatiya_dep = "Раз в месяц";
  char *spisok_period_dep = "раз в год";
  int type = 0;
  double result_procent = 0;
  double result_nalog = 0;
  double result_deposit = 0;
  double result_procent_true = 230400.000000;
  double result_nalog_true = 10452.000000;
  double result_deposit_true = 910000.000000;
  int status =
      deposit(sum_dep, srok_dep, date_dep, proc_dep, nalog_dep, popol_mes_dep,
              sum_popol_dep, snyatiya_mes_dep, snyatiya_sum_dep,
              spisok_popol_dep, spisok_snyatiya_dep, spisok_period_dep, &type,
              &result_procent, &result_nalog, &result_deposit);
  if ((fabs(result_procent_true) - fabs(result_procent) < 1e-7) &&
      (fabs(result_nalog_true) - fabs(result_nalog) < 1e-7) &&
      (fabs(result_deposit_true) - fabs(result_deposit) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, BAD_EXPRESSION);
  }
}
END_TEST

START_TEST(deposit_8) {
  char *sum_dep = "1000000";
  char *srok_dep = "24";
  char *date_dep = "22.02.23";
  char *proc_dep = "12";
  char *nalog_dep = "13";
  char *popol_mes_dep = "0";
  char *sum_popol_dep = "0";
  char *snyatiya_mes_dep = "23.05.24";
  char *snyatiya_sum_dep = "10000";
  char *spisok_popol_dep = "Нет";
  char *spisok_snyatiya_dep = "Раз в месяц";
  char *spisok_period_dep = "раз в год";
  int type = 1;
  double result_procent = 0;
  double result_nalog = 0;
  double result_deposit = 0;
  double result_procent_true = 244800.000000;
  double result_nalog_true = 12324.000000;
  double result_deposit_true = 1154800.000000;
  int status =
      deposit(sum_dep, srok_dep, date_dep, proc_dep, nalog_dep, popol_mes_dep,
              sum_popol_dep, snyatiya_mes_dep, snyatiya_sum_dep,
              spisok_popol_dep, spisok_snyatiya_dep, spisok_period_dep, &type,
              &result_procent, &result_nalog, &result_deposit);
  if ((fabs(result_procent_true) - fabs(result_procent) < 1e-7) &&
      (fabs(result_nalog_true) - fabs(result_nalog) < 1e-7) &&
      (fabs(result_deposit_true) - fabs(result_deposit) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, BAD_EXPRESSION);
  }
}
END_TEST

START_TEST(deposit_9) {
  char *sum_dep = "1000000";
  char *srok_dep = "24";
  char *date_dep = "22.02.23";
  char *proc_dep = "12";
  char *nalog_dep = "13";
  char *popol_mes_dep = "16.01.24";
  char *sum_popol_dep = "20000";
  char *snyatiya_mes_dep = "23.05.24";
  char *snyatiya_sum_dep = "10000";
  char *spisok_popol_dep = "Раз в месяц";
  char *spisok_snyatiya_dep = "Раз в месяц";
  char *spisok_period_dep = "раз в год";
  int type = 1;
  double result_procent = 0;
  double result_nalog = 0;
  double result_deposit = 0;
  double result_procent_true = 278688.000000;
  double result_nalog_true = 16729.440000;
  double result_deposit_true = 1448688.000000;
  int status =
      deposit(sum_dep, srok_dep, date_dep, proc_dep, nalog_dep, popol_mes_dep,
              sum_popol_dep, snyatiya_mes_dep, snyatiya_sum_dep,
              spisok_popol_dep, spisok_snyatiya_dep, spisok_period_dep, &type,
              &result_procent, &result_nalog, &result_deposit);
  if ((fabs(result_procent_true) - fabs(result_procent) < 1e-7) &&
      (fabs(result_nalog_true) - fabs(result_nalog) < 1e-7) &&
      (fabs(result_deposit_true) - fabs(result_deposit) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, BAD_EXPRESSION);
  }
}
END_TEST

START_TEST(deposit_10) {
  char *sum_dep = "0";
  char *srok_dep = "0";
  char *date_dep = "0";
  char *proc_dep = "0";
  char *nalog_dep = "0";
  char *popol_mes_dep = "0";
  char *sum_popol_dep = "0";
  char *snyatiya_mes_dep = "0";
  char *snyatiya_sum_dep = "0";
  char *spisok_popol_dep = "Нет";
  char *spisok_snyatiya_dep = "Нет";
  char *spisok_period_dep = "в конце срока";
  int type = 1;
  double result_procent = 0;
  double result_nalog = 0;
  double result_deposit = 0;
  int status =
      deposit(sum_dep, srok_dep, date_dep, proc_dep, nalog_dep, popol_mes_dep,
              sum_popol_dep, snyatiya_mes_dep, snyatiya_sum_dep,
              spisok_popol_dep, spisok_snyatiya_dep, spisok_period_dep, &type,
              &result_procent, &result_nalog, &result_deposit);
  ck_assert_int_eq(status, BAD_EXPRESSION);
}
END_TEST

START_TEST(deposit_11) {
  char *sum_dep = "";
  char *srok_dep = "";
  char *date_dep = "";
  char *proc_dep = "";
  char *nalog_dep = "";
  char *popol_mes_dep = "";
  char *sum_popol_dep = "";
  char *snyatiya_mes_dep = "";
  char *snyatiya_sum_dep = "";
  char *spisok_popol_dep = "Нет";
  char *spisok_snyatiya_dep = "Нет";
  char *spisok_period_dep = "в конце срока";
  int type = 1;
  double result_procent = 0;
  double result_nalog = 0;
  double result_deposit = 0;
  int status =
      deposit(sum_dep, srok_dep, date_dep, proc_dep, nalog_dep, popol_mes_dep,
              sum_popol_dep, snyatiya_mes_dep, snyatiya_sum_dep,
              spisok_popol_dep, spisok_snyatiya_dep, spisok_period_dep, &type,
              &result_procent, &result_nalog, &result_deposit);
  ck_assert_int_eq(status, BAD_EXPRESSION);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_deposit;

  s = suite_create("deposit");

  tc_deposit = tcase_create("deposit");
  tcase_add_test(tc_deposit, deposit_1);
  tcase_add_test(tc_deposit, deposit_2);
  tcase_add_test(tc_deposit, deposit_3);
  tcase_add_test(tc_deposit, deposit_4);
  tcase_add_test(tc_deposit, deposit_5);
  tcase_add_test(tc_deposit, deposit_6);
  tcase_add_test(tc_deposit, deposit_7);
  tcase_add_test(tc_deposit, deposit_8);
  tcase_add_test(tc_deposit, deposit_9);
  tcase_add_test(tc_deposit, deposit_10);
  tcase_add_test(tc_deposit, deposit_11);
  suite_add_tcase(s, tc_deposit);

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
