#include "headers/BankModel.h"

namespace s21 {
void BankModel::Credit(const string& amount_credit, const string& term,
                       const string& interest_rate, const bool& payment_type) {
  std::setlocale(LC_ALL, "en_US.UTF-8");
  CheckStringValue(3, amount_credit, term, interest_rate);
  const double amount_credit_value = std::stod(amount_credit);
  const int term_value = std::stoi(term);
  const double interest_rate_value = std::stod(interest_rate) / (12.0 * 100);
  double monthly_payment = 0;
  if (interest_rate_value < 0.0008 || term_value <= 0) {
    throw invalid_argument(
        "Минимальная процентная ставка 1 и Срок должен быть больше нуля "
        "месяцев");
  }
  if (!payment_type) {
    monthly_payment =
        amount_credit_value * interest_rate_value *
        (1.0 + 1.0 / (pow(1.0 + interest_rate_value, term_value) - 1));
    monthly_payment_ = to_string(monthly_payment);
    debt_with_interest_ = monthly_payment * term_value;
    total_tax_ = debt_with_interest_ - amount_credit_value;
  } else {
    monthly_payment = amount_credit_value / term_value;
    total_tax_ = 0;
    for (int i = 0; i < term_value; i++) {
      total_tax_ +=
          interest_rate_value * (amount_credit_value - i * monthly_payment);
    }
    monthly_payment_ = to_string(monthly_payment +
                                 (amount_credit_value * interest_rate_value));
    monthly_payment_ += "...";
    monthly_payment_ += to_string(monthly_payment * (1 + interest_rate_value));
    debt_with_interest_ = total_tax_ + amount_credit_value;
  }
}

void BankModel::Deposit(DepositInputValues& deposit_values) {
  std::setlocale(LC_ALL, "en_US.UTF-8");
  CheckStringValue(
      6, deposit_values.summ_deposit_value_, deposit_values.term_value_,
      deposit_values.stavka_percent_value_, deposit_values.nalog_stavka_value_,
      deposit_values.replenishment_value_, deposit_values.withdrawals_value_);
  total_deposit_ = std::stod(deposit_values.summ_deposit_value_);
  total_percent_ = 0;
  total_tax_ = 0;
  DepositValues DepValues;
  DepValues.amount_month = std::stoi(deposit_values.term_value_);
  DepValues.nalog_procent = std::stod(deposit_values.nalog_stavka_value_);
  DepValues.periodicity_payment = CheckList(deposit_values.periodicity_value_);
  DepValues.periodicity_replenishment =
      CheckList(deposit_values.replenishment_period_);
  DepValues.periodicity_withdrawals =
      CheckList(deposit_values.withdrawals_period_);
  CheckDateValue(deposit_values.term_start_value_, DepValues.term_start_day,
                 DepValues.term_start_month);
  if (deposit_values.replenishment_period_ != "Нет") {
    CheckDateValue(deposit_values.replenishment_start_,
                   DepValues.replenishment_start_day,
                   DepValues.replenishment_start_month);
    DepValues.month_start_replenishment =
        DepValues.term_start_month +
        GetMonthBeetwenDate(deposit_values.term_start_value_,
                            deposit_values.replenishment_start_);
    DepValues.replenishmnet_value_double =
        std::stod(deposit_values.replenishment_value_);
  }
  if (deposit_values.withdrawals_period_ != "Нет") {
    CheckDateValue(deposit_values.withdrawals_start_,
                   DepValues.withdrawal_start_day,
                   DepValues.withdrawals_start_month);
    DepValues.month_start_withdrawals =
        DepValues.term_start_month +
        GetMonthBeetwenDate(deposit_values.term_start_value_,
                            deposit_values.withdrawals_start_);
    DepValues.withdrawals_value_double =
        std::stod(deposit_values.withdrawals_value_);
  }
  DepValues.percent_one_day =
      std::stod(deposit_values.stavka_percent_value_) / (100 * 365);
  CalculateDeposit(DepValues, deposit_values.type_deposit_);
}

void BankModel::CalculateDeposit(DepositValues& DepValues,
                                 const bool& type_deposit) noexcept {
  for (int i = DepValues.term_start_month;
       i < DepValues.term_start_month + DepValues.amount_month; i++) {
    DepValues.total_percent +=
        month_date_[(i - 1) % 12] * DepValues.percent_one_day * total_deposit_;
    DepValues.total_percent_year +=
        month_date_[(i - 1) % 12] * DepValues.percent_one_day * total_deposit_;
    if (DepValues.periodicity_withdrawals != 0 &&
        i >= DepValues.month_start_withdrawals) {
      DepValues.total_percent +=
          (DepValues.term_start_day - DepValues.withdrawal_start_day +
           month_date_[(i - 1) % 12]) *
          DepValues.percent_one_day * DepValues.withdrawals_value_double;
      DepValues.total_percent_year +=
          (DepValues.term_start_day - DepValues.withdrawal_start_day +
           month_date_[(i - 1) % 12]) *
          DepValues.percent_one_day * DepValues.withdrawals_value_double;
    }
    if (DepValues.periodicity_replenishment != 0 &&
        i >= DepValues.month_start_replenishment) {
      DepValues.total_percent -=
          (DepValues.term_start_day - DepValues.replenishment_start_day +
           month_date_[(i - 1) % 12]) *
          DepValues.percent_one_day * DepValues.replenishmnet_value_double;
      DepValues.total_percent_year -=
          (DepValues.term_start_day - DepValues.replenishment_start_day +
           month_date_[(i - 1) % 12]) *
          DepValues.percent_one_day * DepValues.replenishmnet_value_double;
    }
    if ((i - DepValues.term_start_month) % DepValues.periodicity_payment == 0 &&
        type_deposit == 1) {
      total_deposit_ += DepValues.total_percent;
      total_percent_ += DepValues.total_percent;
      DepValues.total_percent = 0;
    }
    if (DepValues.periodicity_replenishment != 0 &&
        (i - DepValues.term_start_month) %
                DepValues.periodicity_replenishment ==
            0 &&
        i >= DepValues.month_start_replenishment) {
      total_deposit_ -= DepValues.replenishmnet_value_double;
    }
    if (DepValues.periodicity_withdrawals != 0 &&
        ((i - DepValues.term_start_month) %
         DepValues.periodicity_withdrawals) == 0 &&
        i >= DepValues.month_start_withdrawals) {
      total_deposit_ += DepValues.withdrawals_value_double;
    }
    if ((i - DepValues.term_start_day) % 12 == 0 &&
        i != DepValues.term_start_day) {
      if (DepValues.percent_one_day * 365 * 1000000 <
          DepValues.total_percent_year) {
        total_tax_ += (DepValues.nalog_procent / 100) *
                      (DepValues.total_percent_year -
                       DepValues.percent_one_day * 365 * 1000000);
        DepValues.total_percent_year = 0;
      }
    }
  }
  if (type_deposit == false) {
    total_percent_ = DepValues.total_percent;
  } else {
    total_percent_ += DepValues.total_percent;
    total_deposit_ += DepValues.total_percent;
  }
  if (DepValues.percent_one_day * 365 * 1000000 <
      DepValues.total_percent_year) {
    total_tax_ += (DepValues.nalog_procent / 100) *
                  (DepValues.total_percent_year -
                   DepValues.percent_one_day * 365 * 1000000);
    DepValues.total_percent_year = 0;
  }
}

void BankModel::CheckStringValue(int count, ...) {
  va_list args;
  va_start(args, count);
  for (int i = 0; i < count; i++) {
    string arg = *(va_arg(args, string*));
    int amount_point = 0, index = 0;
    if (arg[index] == '+') index++;
    while (isdigit(arg[index]) || arg[index] == '.') {
      if (arg[index] == '.') amount_point++;
      index++;
      if (amount_point > 1) {
        break;
      }
    }
    if ((int)arg.size() != index) {
      throw invalid_argument("Введены неверные значения");
    }
  }
  va_end(args);
}

void BankModel::CheckDateValue(const string& date_value, int& day,
                               int& month) const {
  std::regex pattern("^\\d{2}\\.\\d{2}\\.\\d{2}$");
  if (!std::regex_match(date_value, pattern)) {
    throw invalid_argument("Введены неверные форматы дат");
  }
  day = std::stoi(date_value.substr(0, 2));
  month = std::stoi(date_value.substr(3, 2));
  if (month < 1 || month > 12) {
    throw invalid_argument("Введены неверные форматы дат");
  }
  int daysInMonth = month_date_[month - 1];
  if (day < 1 || day > daysInMonth) {
    throw invalid_argument("Введены неверные форматы дат");
  }
}

int BankModel::CheckList(const string& string_list) const {
  if (string_list == "Раз в месяц") {
    return 1;
  } else if (string_list == "Раз в 2 месяца") {
    return 2;
  } else if (string_list == "Раз в квартал") {
    return 3;
  } else if (string_list == "Раз в полгода") {
    return 6;
  } else if (string_list == "Раз в год") {
    return 12;
  }
  return 0;
}

int BankModel::GetMonthBeetwenDate(const string& first_date,
                                   const string& second_date) {
  std::tm date_one = {};
  std::istringstream stream_first(first_date);
  stream_first >> std::get_time(&date_one, "%d.%m.%y");
  std::tm date_two = {};
  std::istringstream stream_second(second_date);
  stream_second >> std::get_time(&date_two, "%d.%m.%y");
  int months = (date_two.tm_year - date_one.tm_year) * 12 + date_two.tm_mon -
               date_one.tm_mon;
  if (months < 0) {
    throw invalid_argument(
        "Дата начала снятий или пополнений раньше даты начала депозита");
  }
  return months;
}

void BankModel::TakeResultCredit(const string& amount_credit,
                                 const string& term,
                                 const string& interest_rate,
                                 const bool& payment_type,
                                 string& monthly_payment_value,
                                 string& total_tax_value,
                                 string& debt_with_interest_value) {
  try {
    Credit(amount_credit, term, interest_rate, payment_type);
    monthly_payment_value = monthly_payment_;
    total_tax_value = std::to_string(total_tax_);
    debt_with_interest_value = std::to_string(debt_with_interest_);
  } catch (invalid_argument& InvalidArgumentExpression) {
    monthly_payment_value = InvalidArgumentExpression.what();
    total_tax_value = InvalidArgumentExpression.what();
    debt_with_interest_value = InvalidArgumentExpression.what();
  }
}

void BankModel::TakeResultDeposit(DepositInputValues& deposit_values,
                                  string& result_percent, string& result_tax,
                                  string& result_vklad) {
  try {
    Deposit(deposit_values);
    result_percent = std::to_string(total_percent_);
    result_tax = std::to_string(total_tax_);
    result_vklad = std::to_string(total_deposit_);
  } catch (invalid_argument& InvalidArgumentExpression) {
    result_percent = InvalidArgumentExpression.what();
    result_tax = InvalidArgumentExpression.what();
    result_vklad = InvalidArgumentExpression.what();
  }
}
}  // namespace s21
