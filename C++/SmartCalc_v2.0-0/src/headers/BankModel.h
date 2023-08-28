#ifndef CALC_HEADERS_BANKMODEL_H_
#define CALC_HEADERS_BANKMODEL_H_

#include <clocale>
#include <iomanip>
#include <sstream>

#include "CalculatorModel.h"
#include "DepositInputValues.h"
#include "ctime"
#include "regex"

using std::string;

namespace s21 {
class BankModel {
 public:
  BankModel()
      : total_percent_(0),
        total_deposit_(0),
        debt_with_interest_(0),
        total_tax_(0){};

  void TakeResultCredit(const string& amount_credit, const string& term,
                        const string& interest_rate, const bool& payment_type,
                        string& monthly_payment_value, string& total_tax_value,
                        string& debt_with_interest_value);
  void TakeResultDeposit(DepositInputValues& deposit_values,
                         string& result_percent, string& result_tax,
                         string& result_vklad);

 private:
  // deposit variables
  double total_percent_;
  double total_deposit_;

  // credit variables
  string monthly_payment_;
  double debt_with_interest_;

  // common variable
  double total_tax_;

  // index - month, value - days
  const vector<int> month_date_ = {31, 28, 31, 30, 31, 30,
                                   31, 31, 30, 31, 30, 31};

  struct DepositValues {
    int amount_month;
    double withdrawals_value_double;
    double replenishmnet_value_double;
    double nalog_procent;
    int term_start_day;
    int term_start_month;
    int replenishment_start_day;
    int replenishment_start_month;
    int withdrawal_start_day;
    int withdrawals_start_month;
    int month_start_replenishment;
    int month_start_withdrawals;
    double percent_one_day;
    double total_percent_year;
    double total_percent;
    int periodicity_payment;
    int periodicity_replenishment;
    int periodicity_withdrawals;
    DepositValues()
        : amount_month(0),
          withdrawals_value_double(0),
          replenishmnet_value_double(0),
          nalog_procent(0),
          term_start_day(0),
          term_start_month(0),
          replenishment_start_day(0),
          replenishment_start_month(0),
          withdrawal_start_day(0),
          withdrawals_start_month(0),
          month_start_replenishment(0),
          month_start_withdrawals(0),
          percent_one_day(0),
          total_percent_year(0),
          total_percent(0),
          periodicity_payment(0),
          periodicity_replenishment(0),
          periodicity_withdrawals(0) {}
  };

  void Credit(const string& amount_credit, const string& term,
              const string& interest_rate, const bool& payment_type);
  void Deposit(DepositInputValues& deposit_values);

  // Проверка строк на ввод double числа, count количество аргументов
  void CheckStringValue(int count, ...);
  // Проверка строк с датами на ввод
  void CheckDateValue(const string& date_value, int& day, int& month) const;
  // Проверка периодичности
  int CheckList(const string& string_list) const;
  // Узнать количество месяцев между двумя датами
  int GetMonthBeetwenDate(const string& first_date, const string& second_date);
  void CalculateDeposit(DepositValues& dep_values,
                        const bool& type_deposit) noexcept;
};
}  // namespace s21

#endif  // CALC_HEADERS_CONTROLLER_H_