#include "../header.h"

START_TEST(calculator_1) {
  char *expression = "2+2";
  char *x_str = "0";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = 4;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, BAD_EXPRESSION);
  }
}
END_TEST

START_TEST(calculator_2) {
  char *expression = "2+2";
  char *x_str = "";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = 4;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, BAD_EXPRESSION);
  }
}
END_TEST

START_TEST(calculator_3) {
  char *expression = "2+2*x";
  char *x_str = "";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  ck_assert_int_eq(status, X);
}
END_TEST

START_TEST(calculator_4) {
  char *expression = "2+2*x";
  char *x_str = "3";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = 8;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_5) {
  char *expression = "logx";
  char *x_str = "100";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = 2;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_6) {
  char *expression = "5+x";
  char *x_str = "100";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = 105;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_7) {
  char *expression = "5-x";
  char *x_str = "100";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = -95;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_8) {
  char *expression = "2*x";
  char *x_str = "100";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = 200;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_9) {
  char *expression = "x/2";
  char *x_str = "100";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = 50;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_10) {
  char *expression = "2^x";
  char *x_str = "10";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = 1024;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_11) {
  char *expression = "xmod3";
  char *x_str = "10";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = 1;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_12) {
  char *expression = "-x";
  char *x_str = "10";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = -10;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_13) {
  char *expression = "-x";
  char *x_str = "-10";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = 10;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_14) {
  char *expression = "+x";
  char *x_str = "-10";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = -10;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_15) {
  char *expression = "+x";
  char *x_str = "+10";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = 10;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_16) {
  char *expression = "cosx";
  char *x_str = "10";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = -0.839072;
  if ((fabs(result_true) - fabs(result) < 1e-6)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_17) {
  char *expression = "sinx";
  char *x_str = "10";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = -0.544021;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_18) {
  char *expression = "tanx";
  char *x_str = "10";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = 0.648361;
  if ((fabs(result_true) - fabs(result) < 1e-6)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_19) {
  char *expression = "acosx";
  char *x_str = "1";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = 0;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_20) {
  char *expression = "asinx";
  char *x_str = "1";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = 1.570796;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_21) {
  char *expression = "atanx";
  char *x_str = "1";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = 0.785398;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_22) {
  char *expression = "sqrtx";
  char *x_str = "100";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = 10;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_23) {
  char *expression = "lnx";
  char *x_str = "10";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = 2.302585;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_24) {
  char *expression = "logx";
  char *x_str = "100";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = 2;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_25) {
  char *expression = "(2+x)*x";
  char *x_str = "100";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = 10200;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_26) {
  char *expression = "-logx+10*2+lnx+(2*4)-12+lnx+2^4-12+2*x";
  char *x_str = "100";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = 227.210340;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

START_TEST(calculator_27) {
  char *expression = "((2+((2+4)*5)-17)+(log(12)+14*2/(24+17)))";
  char *x_str = "100";
  double result = 0;
  int status = parser_of_expression(expression, x_str, &result);
  double result_true = 16.762108;
  if ((fabs(result_true) - fabs(result) < 1e-7)) {
    ck_assert_int_eq(status, OK);
  } else {
    ck_assert_int_eq(status, X);
  }
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_calculator;

  s = suite_create("calculator");

  tc_calculator = tcase_create("calculator");
  tcase_add_test(tc_calculator, calculator_1);
  tcase_add_test(tc_calculator, calculator_2);
  tcase_add_test(tc_calculator, calculator_3);
  tcase_add_test(tc_calculator, calculator_4);
  tcase_add_test(tc_calculator, calculator_5);
  tcase_add_test(tc_calculator, calculator_6);
  tcase_add_test(tc_calculator, calculator_7);
  tcase_add_test(tc_calculator, calculator_8);
  tcase_add_test(tc_calculator, calculator_9);
  tcase_add_test(tc_calculator, calculator_10);
  tcase_add_test(tc_calculator, calculator_11);
  tcase_add_test(tc_calculator, calculator_12);
  tcase_add_test(tc_calculator, calculator_13);
  tcase_add_test(tc_calculator, calculator_14);
  tcase_add_test(tc_calculator, calculator_15);
  tcase_add_test(tc_calculator, calculator_16);
  tcase_add_test(tc_calculator, calculator_17);
  tcase_add_test(tc_calculator, calculator_18);
  tcase_add_test(tc_calculator, calculator_19);
  tcase_add_test(tc_calculator, calculator_20);
  tcase_add_test(tc_calculator, calculator_21);
  tcase_add_test(tc_calculator, calculator_22);
  tcase_add_test(tc_calculator, calculator_23);
  tcase_add_test(tc_calculator, calculator_24);
  tcase_add_test(tc_calculator, calculator_25);
  tcase_add_test(tc_calculator, calculator_26);
  tcase_add_test(tc_calculator, calculator_27);
  suite_add_tcase(s, tc_calculator);

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
