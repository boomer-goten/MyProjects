#include <gtest/gtest.h>

#include "../BankModelOperations.cc"
#include "../headers/BankModel.h"
#include "../headers/CalculatorModel.h"

using namespace s21;
using std::stod;

TEST(credit, TEST1) {
  BankModel bank;
  string Payment;
  string TotalTax;
  string TotalCredit;
  bank.TakeResultCredit("100000", "12", "5", false, Payment, TotalTax,
                        TotalCredit);
  ASSERT_DOUBLE_EQ(stod(Payment), 8560.748179);
  ASSERT_DOUBLE_EQ(stod(TotalTax), 2728.978146);
  ASSERT_DOUBLE_EQ(stod(TotalCredit), 102728.978146);
}

TEST(credit, TEST2) {
  BankModel bank;
  string Payment;
  string TotalTax;
  string TotalCredit;
  bank.TakeResultCredit("125467", "84", "6", false, Payment, TotalTax,
                        TotalCredit);
  ASSERT_DOUBLE_EQ(stod(Payment), 1832.891505);
  ASSERT_DOUBLE_EQ(stod(TotalTax), 28495.886455);
  ASSERT_DOUBLE_EQ(stod(TotalCredit), 153962.886455);
}

TEST(credit, TEST3) {
  BankModel bank;
  string Payment;
  string TotalTax;
  string TotalCredit;
  EXPECT_THROW(
      {
        bank.TakeResultCredit("125467", "-2", "6", false, Payment, TotalTax,
                              TotalCredit);
        throw invalid_argument(
            "Минимальная процентная ставка 1 и Срок должен быть больше нуля "
            "месяцев");
      },
      invalid_argument);
}

TEST(credit, TEST4) {
  BankModel bank;
  string Payment;
  string TotalTax;
  string TotalCredit;
  EXPECT_THROW(
      {
        bank.TakeResultCredit("125467", "24", "-6", false, Payment, TotalTax,
                              TotalCredit);
        throw invalid_argument(
            "Минимальная процентная ставка 1 и Срок должен быть больше нуля "
            "месяцев");
      },
      invalid_argument);
}

TEST(credit, TEST5) {
  BankModel bank;
  string Payment;
  string TotalTax;
  string TotalCredit;
  bank.TakeResultCredit("12412", "7", "6", true, Payment, TotalTax,
                        TotalCredit);
  EXPECT_TRUE(Payment == "1835.202857...1782.008571");
  ASSERT_DOUBLE_EQ(stod(TotalTax), 248.240000);
  ASSERT_DOUBLE_EQ(stod(TotalCredit), 12660.240000);
}

TEST(credit, TEST6) {
  BankModel bank;
  string Payment;
  string TotalTax;
  string TotalCredit;
  bank.TakeResultCredit("738256", "21", "10", true, Payment, TotalTax,
                        TotalCredit);
  EXPECT_TRUE(Payment == "41307.180952...35448.006349");
  ASSERT_DOUBLE_EQ(stod(TotalTax), 67673.466667);
  ASSERT_DOUBLE_EQ(stod(TotalCredit), 805929.466667);
}

TEST(credit, TEST7) {
  BankModel bank;
  string Payment;
  string TotalTax;
  string TotalCredit;
  EXPECT_THROW(
      {
        bank.TakeResultCredit("125467", "2", "-6", false, Payment, TotalTax,
                              TotalCredit);
        throw invalid_argument(
            "Минимальная процентная ставка 1 и Срок должен быть больше нуля "
            "месяцев");
      },
      invalid_argument);
}
