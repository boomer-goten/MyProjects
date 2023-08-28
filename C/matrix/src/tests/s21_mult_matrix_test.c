#include "../header.h"

START_TEST(mult_1) {
  matrix_t A, B, result;
  int Arows = 3, Acolumns = 5;
  int Brows = 5, Bcolumns = 6;
  s21_create_matrix(Arows, Acolumns, &A); s21_create_matrix(Brows, Bcolumns, &B);
  for (int i = 0; i < Arows; i++) {
    for (int j = 0; j < Acolumns; j++) {
      A.matrix[i][j] = (double)(rand())/RAND_MAX;
    }
  }
  for (int i = 0; i < Brows; i++) {
    for (int j = 0; j < Bcolumns; j++) {
      B.matrix[i][j] = (double)(rand())/RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_2) {
  matrix_t A, B, result;
  int Arows = 30, Acolumns = 144;
  int Brows = 144, Bcolumns = 27;
  s21_create_matrix(Arows, Acolumns, &A); s21_create_matrix(Brows, Bcolumns, &B);
  for (int i = 0; i < Arows; i++) {
    for (int j = 0; j < Acolumns; j++) {
      A.matrix[i][j] = (double)(rand())/RAND_MAX;
    }
  }
  for (int i = 0; i < Brows; i++) {
    for (int j = 0; j < Bcolumns; j++) {
      B.matrix[i][j] = (double)(rand())/RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_3) {
  matrix_t A, B, result;
  int Arows = 4, Acolumns = 10;
  int Brows = 13, Bcolumns = 27;
  s21_create_matrix(Arows, Acolumns, &A);
  s21_create_matrix(Brows, Bcolumns, &B);
  for (int i = 0; i < Arows; i++) {
    for (int j = 0; j < Acolumns; j++) {
      A.matrix[i][j] = (double)(rand())/RAND_MAX;
    }
  }
  for (int i = 0; i < Brows; i++) {
    for (int j = 0; j < Bcolumns; j++) {
      B.matrix[i][j] = (double)(rand())/RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_4) {
  matrix_t A, B, result;
  int Arows = 3, Acolumns = 10;
  int Brows = 14, Bcolumns = 2;
  s21_create_matrix(Arows, Acolumns, &A); s21_create_matrix(Brows, Bcolumns, &B);
  for (int i = 0; i < Arows; i++) {
    for (int j = 0; j < Acolumns; j++) {
      A.matrix[i][j] = (double)(rand())/RAND_MAX;
    }
  }
  for (int i = 0; i < Brows; i++) {
    for (int j = 0; j < Bcolumns; j++) {
      B.matrix[i][j] = (double)(rand())/RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_5) {
  matrix_t A, B, result;
  A.matrix = NULL;
  B.matrix = NULL;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 1);
}
END_TEST


Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_mult_matrix;

  s = suite_create("mult_matrix");

  tc_mult_matrix = tcase_create("mult_matrix");
  tcase_add_test(tc_mult_matrix, mult_1);
  tcase_add_test(tc_mult_matrix, mult_2);
  tcase_add_test(tc_mult_matrix, mult_3);
  tcase_add_test(tc_mult_matrix, mult_4);
  tcase_add_test(tc_mult_matrix, mult_5);
  suite_add_tcase(s, tc_mult_matrix);

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

