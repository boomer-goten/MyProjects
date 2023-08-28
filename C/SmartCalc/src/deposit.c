#include "s21_calc.h"

void func_slozh(double* sum_dep_dbl_tmp, double* sum_dep_dbl,
                double* sum_dep_dbl_tmp_two, double* sum_popol_dep_dbl) {
  *sum_dep_dbl_tmp += *sum_popol_dep_dbl;
  *sum_dep_dbl += *sum_popol_dep_dbl;
  *sum_dep_dbl_tmp_two += *sum_popol_dep_dbl;
}

void func_vichit(double* sum_dep_dbl_tmp, double* sum_dep_dbl,
                 double* sum_dep_dbl_tmp_two, double* sum_popol_dep_dbl) {
  *sum_dep_dbl_tmp -= *sum_popol_dep_dbl;
  *sum_dep_dbl -= *sum_popol_dep_dbl;
  *sum_dep_dbl_tmp_two -= *sum_popol_dep_dbl;
}

int deposit(char* sum_dep, char* srok_dep, char* date_dep, char* proc_dep,
            char* nalog_dep, char* popol_mes_dep, char* sum_popol_dep,
            char* snyatiya_mes_dep, char* snyatiya_sum_dep,
            char* spisok_popol_dep, char* spisok_snyatiya_dep,
            char* spisok_period_dep, int* type, double* result_procent,
            double* result_nalog, double* result_deposit) {
  int status = OK;
  status = char_is_empty(sum_dep);
  status = char_is_empty(srok_dep);
  status = char_is_empty(proc_dep);
  status = char_is_empty(nalog_dep);
  status = char_is_empty(date_dep);
  status = char_is_empty(popol_mes_dep);
  status = char_is_empty(sum_popol_dep);
  status = char_is_empty(snyatiya_mes_dep);
  status = char_is_empty(snyatiya_sum_dep);
  if (status == OK) {
    double sum_dep_dbl = 0, proc_dep_dbl = 0, nalog_dep_dbl = 0,
           sum_popol_dep_dbl = 0, snyatiya_sum_dep_dbl = 0;
    int srok_dep_int = 0;
    int date_dep_day = 0, date_popol_day = 0, date_snyat_day = 0;
    int date_dep_month = 0, date_popol_month = 0, date_snyat_month = 0;
    int date_dep_year = 0, date_popol_year = 0, date_snyat_year = 0;
    int period_tmp = 0, popol_tmp = 0, snyat_tmp = 0;
    status = double_is_true(sum_dep, &sum_dep_dbl);
    status = double_is_true(proc_dep, &proc_dep_dbl);
    status = double_is_true(nalog_dep, &nalog_dep_dbl);
    status = double_is_true(sum_popol_dep, &sum_popol_dep_dbl);
    status = double_is_true(snyatiya_sum_dep, &snyatiya_sum_dep_dbl);
    status = int_is_true(srok_dep, &srok_dep_int);
    status = take_from_date(date_dep, &date_dep_day, &date_dep_month,
                            &date_dep_year);
    take_from_spisok(spisok_popol_dep, &popol_tmp);
    take_from_spisok(spisok_snyatiya_dep, &snyat_tmp);
    if (popol_tmp != 13) {
      status = take_from_date(popol_mes_dep, &date_popol_day, &date_popol_month,
                              &date_popol_year);
    }
    if (snyat_tmp != 13) {
      status = take_from_date(snyatiya_mes_dep, &date_snyat_day,
                              &date_snyat_month, &date_snyat_year);
    }
    take_from_spisok_viplat(spisok_period_dep, &period_tmp);
    double sum_dep_dbl_tmp = sum_dep_dbl;
    double sum_dep_dbl_tmp_two = sum_dep_dbl;
    double dohod_god = 0;
    int tmp = (date_popol_year - date_dep_year) * 12 + date_popol_month;
    int tmp_snyat = (date_snyat_year - date_dep_year) * 12 + date_snyat_month;
    if (status == OK) {
      for (int i = date_dep_month; i <= date_dep_month + srok_dep_int; i++) {
        if (date_popol_day < date_dep_day && tmp < i && (i % popol_tmp) == 0 &&
            popol_tmp != 13 && popol_tmp != -1) {
          func_slozh(&sum_dep_dbl_tmp, &sum_dep_dbl, &sum_dep_dbl_tmp_two,
                     &sum_popol_dep_dbl);
        }
        if (popol_tmp == -1 && tmp == i && date_popol_day < date_dep_day) {
          func_slozh(&sum_dep_dbl_tmp, &sum_dep_dbl, &sum_dep_dbl_tmp_two,
                     &sum_popol_dep_dbl);
        }
        if (date_snyat_day < date_dep_day && tmp_snyat < i &&
            (i % snyat_tmp) == 0 && snyat_tmp != 13 && snyat_tmp != -1) {
          func_vichit(&sum_dep_dbl_tmp, &sum_dep_dbl, &sum_dep_dbl_tmp_two,
                      &snyatiya_sum_dep_dbl);
        }
        if (snyat_tmp == -1 && tmp_snyat == i &&
            date_snyat_day < date_dep_day) {
          func_vichit(&sum_dep_dbl_tmp, &sum_dep_dbl, &sum_dep_dbl_tmp_two,
                      &snyatiya_sum_dep_dbl);
        }
        if ((i - date_dep_month) % period_tmp == 0 && i - date_dep_month != 0 &&
            period_tmp != 13) {
          sum_dep_dbl += (proc_dep_dbl / 1200) * sum_dep_dbl * (period_tmp);
        }
        if (period_tmp == 13 && i == date_dep_month + srok_dep_int) {
          sum_dep_dbl += (proc_dep_dbl / 1200) * sum_dep_dbl * srok_dep_int;
        }
        if (date_popol_day >= date_dep_day && tmp < i && (i % popol_tmp) == 0 &&
            popol_tmp != 13 && popol_tmp != -1) {
          func_slozh(&sum_dep_dbl_tmp, &sum_dep_dbl, &sum_dep_dbl_tmp_two,
                     &sum_popol_dep_dbl);
        }
        if (popol_tmp == -1 && tmp == i && date_popol_day >= date_dep_day) {
          func_slozh(&sum_dep_dbl_tmp, &sum_dep_dbl, &sum_dep_dbl_tmp_two,
                     &sum_popol_dep_dbl);
        }
        if (date_snyat_day >= date_dep_day && tmp_snyat < i &&
            (i % snyat_tmp) == 0 && snyat_tmp != 13 && snyat_tmp != -1) {
          func_vichit(&sum_dep_dbl_tmp, &sum_dep_dbl, &sum_dep_dbl_tmp_two,
                      &snyatiya_sum_dep_dbl);
        }
        if (popol_tmp == -1 && tmp_snyat == i &&
            date_snyat_day >= date_dep_day) {
          func_vichit(&sum_dep_dbl_tmp, &sum_dep_dbl, &sum_dep_dbl_tmp_two,
                      &snyatiya_sum_dep_dbl);
        }
        if (*type == 0) {
          *result_procent += sum_dep_dbl - sum_dep_dbl_tmp;
          dohod_god += sum_dep_dbl - sum_dep_dbl_tmp_two;
          sum_dep_dbl = sum_dep_dbl_tmp;
        } else {
          dohod_god = sum_dep_dbl - sum_dep_dbl_tmp_two;
        }
        if ((7.5 * 10000 < dohod_god && i == date_dep_month + srok_dep_int) ||
            (i % 12 == 0 && 7.5 * 10000 < dohod_god)) {
          *result_nalog += nalog_dep_dbl / 100 * (dohod_god - 7.5 * 10000);
          sum_dep_dbl_tmp_two = sum_dep_dbl;
          dohod_god = 0;
        }
      }
      if (*type == 0) {
        *result_deposit = sum_dep_dbl_tmp;
      } else {
        *result_deposit = sum_dep_dbl;
        *result_procent = *result_deposit - sum_dep_dbl_tmp;
      }
    }
  }
  return status;
}