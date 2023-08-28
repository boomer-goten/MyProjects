#include "s21_calc.h"

int credit(char* summ, char* srok, char* proc_stavka, int* type,
           char* result_platezh, double* result_proc, double* result_sum) {
  int status = OK;
  status += char_is_empty(summ);
  status += char_is_empty(srok);
  status += char_is_empty(proc_stavka);
  if (status == OK) {
    double summ_dbl = 0;
    int srok_int = 0;
    double proc_stavka_dbl = 0;
    status += double_is_true(summ, &summ_dbl);
    status += int_is_true(srok, &srok_int);
    if (srok_int == 0) {
      status++;
    }
    status += double_is_true(proc_stavka, &proc_stavka_dbl);
    if (status == OK) {
      double proc_tmp = proc_stavka_dbl / (12 * 100);
      if (*type == 0) {
        double result_platezh_tmp = 0;
        if (fabs(proc_stavka_dbl - 0.0) > 1e-7) {
          result_platezh_tmp =
              summ_dbl *
              (proc_tmp + proc_tmp / (pow(1 + proc_tmp, (double)srok_int) - 1));
        } else {
          result_platezh_tmp = summ_dbl / srok_int;
        }
        sprintf(result_platezh, "%lf", result_platezh_tmp);
        *result_sum = result_platezh_tmp * srok_int;
        *result_proc = *result_sum - summ_dbl;
      } else if (*type == 1) {
        double b = summ_dbl / srok_int;
        *result_proc = 0;
        for (int i = 0; i < srok_int; i++) {
          *result_proc += proc_tmp * (summ_dbl - i * b);
        }
        double first_platezh = b + (summ_dbl * proc_tmp);
        double second_platezh = b * (1 + proc_tmp);
        *result_sum = *result_proc + summ_dbl;
        char platezh_str[125] = "\0";
        char platezh_last[60] = "\0";
        sprintf(platezh_str, "%lf", first_platezh);
        sprintf(platezh_last, "%lf", second_platezh);
        strcat(platezh_str, "...");
        strcat(platezh_str, platezh_last);
        int size_plat = strlen(platezh_str);
        int j = 0;
        for (j = 0; j < size_plat; j++) {
          result_platezh[j] = platezh_str[j];
        }
        result_platezh[j] = '\0';
      } else {
        status = BAD_EXPRESSION;
      }
    }
  }
  if (status != OK) {
    status = BAD_EXPRESSION;
  }
  return status;
}