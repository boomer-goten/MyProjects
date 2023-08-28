#include <gtest/gtest.h>

#include "../BankModelOperations.cc"
#include "../headers/BankModel.h"
#include "../headers/CalculatorModel.h"

using namespace s21;
using std::stod;

TEST(deposit, TEST1) {
  BankModel bank;
  DepositInputValues values;
  values.summ_deposit_value_ = "512512";
  values.term_value_ = "3";
  values.term_start_value_ = "03.08.23";
  values.stavka_percent_value_ = "12";
  values.nalog_stavka_value_ = "13";
  values.type_deposit_ = false;
  values.periodicity_value_ = "Раз в месяц";
  values.replenishment_period_ = "Нет";
  values.replenishment_start_ = "0";
  values.replenishment_value_ = "0";
  values.withdrawals_period_ = "Нет";
  values.withdrawals_start_ = "0";
  values.withdrawals_value_ = "0";
  string ResultPercentValue;
  string ResultTaxValue;
  string ResultVkladValue;
  bank.TakeResultDeposit(values, ResultPercentValue, ResultTaxValue,
                         ResultVkladValue);
  ASSERT_DOUBLE_EQ(stod(ResultPercentValue), 15501.732822);
  ASSERT_DOUBLE_EQ(stod(ResultTaxValue), 0);
  ASSERT_DOUBLE_EQ(stod(ResultVkladValue), 512512.0);
}

TEST(deposit, TEST2) {
  BankModel bank;
  DepositInputValues values;
  values.summ_deposit_value_ = "512512";
  values.term_value_ = "3";
  values.term_start_value_ = "03.08.23";
  values.stavka_percent_value_ = "12";
  values.nalog_stavka_value_ = "13";
  values.type_deposit_ = true;
  values.periodicity_value_ = "Раз в месяц";
  values.replenishment_period_ = "Нет";
  values.replenishment_start_ = "0";
  values.replenishment_value_ = "0";
  values.withdrawals_period_ = "Нет";
  values.withdrawals_start_ = "0";
  values.withdrawals_value_ = "0";
  string ResultPercentValue;
  string ResultTaxValue;
  string ResultVkladValue;
  bank.TakeResultDeposit(values, ResultPercentValue, ResultTaxValue,
                         ResultVkladValue);
  ASSERT_DOUBLE_EQ(stod(ResultPercentValue), 15658.530866);
  ASSERT_DOUBLE_EQ(stod(ResultTaxValue), 0);
  ASSERT_DOUBLE_EQ(stod(ResultVkladValue), 528170.530866);
}

TEST(deposit, TEST3) {
  BankModel bank;
  DepositInputValues values;
  values.summ_deposit_value_ = "512512";
  values.term_value_ = "3";
  values.term_start_value_ = "03.08.23";
  values.stavka_percent_value_ = "12";
  values.nalog_stavka_value_ = "13";
  values.type_deposit_ = false;
  values.periodicity_value_ = "Раз в месяц";
  values.replenishment_period_ = "Нет";
  values.replenishment_start_ = "0";
  values.replenishment_value_ = "0";
  values.withdrawals_period_ = "Раз в месяц";
  values.withdrawals_start_ = "19.09.23";
  values.withdrawals_value_ = "100000";
  string ResultPercentValue;
  string ResultTaxValue;
  string ResultVkladValue;
  bank.TakeResultDeposit(values, ResultPercentValue, ResultTaxValue,
                         ResultVkladValue);
  ASSERT_DOUBLE_EQ(stod(ResultPercentValue), 17474.335562);
  ASSERT_DOUBLE_EQ(stod(ResultTaxValue), 0);
  ASSERT_DOUBLE_EQ(stod(ResultVkladValue), 712512.000000);
}

TEST(deposit, TEST4) {
  BankModel bank;
  DepositInputValues values;
  values.summ_deposit_value_ = "512512";
  values.term_value_ = "3";
  values.term_start_value_ = "03.08.23";
  values.stavka_percent_value_ = "12";
  values.nalog_stavka_value_ = "13";
  values.type_deposit_ = false;
  values.periodicity_value_ = "Раз в месяц";
  values.replenishment_period_ = "Раз в месяц";
  values.replenishment_start_ = "19.09.23";
  values.replenishment_value_ = "100000";
  values.withdrawals_period_ = "Нет";
  values.withdrawals_start_ = "0";
  values.withdrawals_value_ = "0";
  string ResultPercentValue;
  string ResultTaxValue;
  string ResultVkladValue;
  bank.TakeResultDeposit(values, ResultPercentValue, ResultTaxValue,
                         ResultVkladValue);
  ASSERT_DOUBLE_EQ(stod(ResultPercentValue), 13529.130082);
  ASSERT_DOUBLE_EQ(stod(ResultTaxValue), 0);
  ASSERT_DOUBLE_EQ(stod(ResultVkladValue), 312512.000000);
}

TEST(deposit, TEST5) {
  BankModel bank;
  DepositInputValues values;
  values.summ_deposit_value_ = "512512";
  values.term_value_ = "3";
  values.term_start_value_ = "03.08.23";
  values.stavka_percent_value_ = "12";
  values.nalog_stavka_value_ = "13";
  values.type_deposit_ = false;
  values.periodicity_value_ = "Раз в 2 месяца";
  values.replenishment_period_ = "Нет";
  values.replenishment_start_ = "0";
  values.replenishment_value_ = "0";
  values.withdrawals_period_ = "Нет";
  values.withdrawals_start_ = "0";
  values.withdrawals_value_ = "0";
  string ResultPercentValue;
  string ResultTaxValue;
  string ResultVkladValue;
  bank.TakeResultDeposit(values, ResultPercentValue, ResultTaxValue,
                         ResultVkladValue);
  ASSERT_DOUBLE_EQ(stod(ResultPercentValue), 15501.732822);
  ASSERT_DOUBLE_EQ(stod(ResultTaxValue), 0);
  ASSERT_DOUBLE_EQ(stod(ResultVkladValue), 512512.0);
}

TEST(deposit, TEST6) {
  BankModel bank;
  DepositInputValues values;
  values.summ_deposit_value_ = "512512";
  values.term_value_ = "9";
  values.term_start_value_ = "03.08.23";
  values.stavka_percent_value_ = "12";
  values.nalog_stavka_value_ = "13";
  values.type_deposit_ = false;
  values.periodicity_value_ = "Раз в квартал";
  values.replenishment_period_ = "Нет";
  values.replenishment_start_ = "0";
  values.replenishment_value_ = "0";
  values.withdrawals_period_ = "Нет";
  values.withdrawals_start_ = "0";
  values.withdrawals_value_ = "0";
  string ResultPercentValue;
  string ResultTaxValue;
  string ResultVkladValue;
  bank.TakeResultDeposit(values, ResultPercentValue, ResultTaxValue,
                         ResultVkladValue);
  ASSERT_DOUBLE_EQ(stod(ResultPercentValue), 45999.707178);
  ASSERT_DOUBLE_EQ(stod(ResultTaxValue), 0);
  ASSERT_DOUBLE_EQ(stod(ResultVkladValue), 512512.0);
}

TEST(deposit, TEST7) {
  BankModel bank;
  DepositInputValues values;
  values.summ_deposit_value_ = "512512";
  values.term_value_ = "9";
  values.term_start_value_ = "03.08.23";
  values.stavka_percent_value_ = "12";
  values.nalog_stavka_value_ = "13";
  values.type_deposit_ = false;
  values.periodicity_value_ = "Раз в полгода";
  values.replenishment_period_ = "Нет";
  values.replenishment_start_ = "0";
  values.replenishment_value_ = "0";
  values.withdrawals_period_ = "Нет";
  values.withdrawals_start_ = "0";
  values.withdrawals_value_ = "0";
  string ResultPercentValue;
  string ResultTaxValue;
  string ResultVkladValue;
  bank.TakeResultDeposit(values, ResultPercentValue, ResultTaxValue,
                         ResultVkladValue);
  ASSERT_DOUBLE_EQ(stod(ResultPercentValue), 45999.707178);
  ASSERT_DOUBLE_EQ(stod(ResultTaxValue), 0);
  ASSERT_DOUBLE_EQ(stod(ResultVkladValue), 512512.0);
}

TEST(deposit, TEST8) {
  BankModel bank;
  DepositInputValues values;
  values.summ_deposit_value_ = "512512";
  values.term_value_ = "14";
  values.term_start_value_ = "03.08.23";
  values.stavka_percent_value_ = "12";
  values.nalog_stavka_value_ = "13";
  values.type_deposit_ = false;
  values.periodicity_value_ = "Раз в год";
  values.replenishment_period_ = "Нет";
  values.replenishment_start_ = "0";
  values.replenishment_value_ = "0";
  values.withdrawals_period_ = "Нет";
  values.withdrawals_start_ = "0";
  values.withdrawals_value_ = "0";
  string ResultPercentValue;
  string ResultTaxValue;
  string ResultVkladValue;
  bank.TakeResultDeposit(values, ResultPercentValue, ResultTaxValue,
                         ResultVkladValue);
  ASSERT_DOUBLE_EQ(stod(ResultPercentValue), 71779.762849);
  ASSERT_DOUBLE_EQ(stod(ResultTaxValue), 0);
  ASSERT_DOUBLE_EQ(stod(ResultVkladValue), 512512.0);
}

TEST(deposit, TEST9) {
  BankModel bank;
  DepositInputValues values;
  values.summ_deposit_value_ = "51251200";
  values.term_value_ = "14";
  values.term_start_value_ = "03.08.23";
  values.stavka_percent_value_ = "12";
  values.nalog_stavka_value_ = "13";
  values.type_deposit_ = false;
  values.periodicity_value_ = "Раз в год";
  values.replenishment_period_ = "Нет";
  values.replenishment_start_ = "0";
  values.replenishment_value_ = "0";
  values.withdrawals_period_ = "Нет";
  values.withdrawals_start_ = "0";
  values.withdrawals_value_ = "0";
  string ResultPercentValue;
  string ResultTaxValue;
  string ResultVkladValue;
  bank.TakeResultDeposit(values, ResultPercentValue, ResultTaxValue,
                         ResultVkladValue);
  ASSERT_DOUBLE_EQ(stod(ResultPercentValue), 7177976.284932);
  ASSERT_DOUBLE_EQ(stod(ResultTaxValue), 901936.917041);
  ASSERT_DOUBLE_EQ(stod(ResultVkladValue), 51251200.000000);
}

TEST(deposit, TEST10) {
  BankModel bank;
  DepositInputValues values;
  values.summ_deposit_value_ = "51251200";
  values.term_value_ = "14";
  values.term_start_value_ = "35.08.23";
  values.stavka_percent_value_ = "12";
  values.nalog_stavka_value_ = "13";
  values.type_deposit_ = false;
  values.periodicity_value_ = "Раз в год";
  values.replenishment_period_ = "Нет";
  values.replenishment_start_ = "0";
  values.replenishment_value_ = "0";
  values.withdrawals_period_ = "Нет";
  values.withdrawals_start_ = "0";
  values.withdrawals_value_ = "0";
  string ResultPercentValue;
  string ResultTaxValue;
  string ResultVkladValue;
  bank.TakeResultDeposit(values, ResultPercentValue, ResultTaxValue,
                         ResultVkladValue);
  EXPECT_THROW(
      {
        bank.TakeResultDeposit(values, ResultPercentValue, ResultTaxValue,
                               ResultVkladValue);
        throw invalid_argument("Введены неверные форматы дат");
      },
      invalid_argument);
}

TEST(deposit, TEST11) {
  BankModel bank;
  DepositInputValues values;
  values.summ_deposit_value_ = "51251200";
  values.term_value_ = "14";
  values.term_start_value_ = "24.15.23";
  values.stavka_percent_value_ = "12";
  values.nalog_stavka_value_ = "13";
  values.type_deposit_ = false;
  values.periodicity_value_ = "Раз в год";
  values.replenishment_period_ = "Нет";
  values.replenishment_start_ = "0";
  values.replenishment_value_ = "0";
  values.withdrawals_period_ = "Нет";
  values.withdrawals_start_ = "0";
  values.withdrawals_value_ = "0";
  string ResultPercentValue;
  string ResultTaxValue;
  string ResultVkladValue;
  bank.TakeResultDeposit(values, ResultPercentValue, ResultTaxValue,
                         ResultVkladValue);
  EXPECT_THROW(
      {
        bank.TakeResultDeposit(values, ResultPercentValue, ResultTaxValue,
                               ResultVkladValue);
        throw invalid_argument("Введены неверные форматы дат");
      },
      invalid_argument);
}

TEST(deposit, TEST12) {
  BankModel bank;
  DepositInputValues values;
  values.summ_deposit_value_ = "51251200";
  values.term_value_ = "14";
  values.term_start_value_ = "24.dr.23";
  values.stavka_percent_value_ = "12";
  values.nalog_stavka_value_ = "13";
  values.type_deposit_ = false;
  values.periodicity_value_ = "Раз в год";
  values.replenishment_period_ = "Нет";
  values.replenishment_start_ = "0";
  values.replenishment_value_ = "0";
  values.withdrawals_period_ = "Нет";
  values.withdrawals_start_ = "0";
  values.withdrawals_value_ = "0";
  string ResultPercentValue;
  string ResultTaxValue;
  string ResultVkladValue;
  bank.TakeResultDeposit(values, ResultPercentValue, ResultTaxValue,
                         ResultVkladValue);
  EXPECT_THROW(
      {
        bank.TakeResultDeposit(values, ResultPercentValue, ResultTaxValue,
                               ResultVkladValue);
        throw invalid_argument("Введены неверные форматы дат");
      },
      invalid_argument);
}

TEST(deposit, TEST13) {
  BankModel bank;
  DepositInputValues values;
  values.summ_deposit_value_ = "51251200";
  values.term_value_ = "14";
  values.term_start_value_ = "24.08.23";
  values.stavka_percent_value_ = "12";
  values.nalog_stavka_value_ = "13";
  values.type_deposit_ = false;
  values.periodicity_value_ = "Раз в год";
  values.replenishment_period_ = "Раз в месяц";
  values.replenishment_start_ = "19.06.23";
  values.replenishment_value_ = "100000";
  values.withdrawals_period_ = "Нет";
  values.withdrawals_start_ = "0";
  values.withdrawals_value_ = "0";
  string ResultPercentValue;
  string ResultTaxValue;
  string ResultVkladValue;
  bank.TakeResultDeposit(values, ResultPercentValue, ResultTaxValue,
                         ResultVkladValue);
  EXPECT_THROW(
      {
        bank.TakeResultDeposit(values, ResultPercentValue, ResultTaxValue,
                               ResultVkladValue);
        throw invalid_argument(
            "Дата начала снятий или пополнений раньше даты начала депозита");
      },
      invalid_argument);
}