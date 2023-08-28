#include <gtest/gtest.h>

#include "../CalculatorModelOperations.cc"
#include "../headers/BankModel.h"
#include "../headers/CalculatorModel.h"

using namespace s21;
using std::stod;

TEST(Calculator, TESTSUM) {
  s21::CalculatorModel calc;
  const string expression = "2+2";
  const string xValue = "0";
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult(expression, xValue)), 4.0);
}

TEST(Calculator, Test2) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("2+2*x", "0")), 2.0);
}

TEST(Calculator, Test3) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("2+2*x", "2")), 6.0);
}

TEST(Calculator, Test4) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("2+2*x", "3")), 8.0);
}

TEST(Calculator, Test5) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("logx", "100")), 2.0);
}

TEST(Calculator, Test6) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("5+x", "100")), 105.0);
}

TEST(Calculator, Test7) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("5-x", "100")), -95.0);
}

TEST(Calculator, Test8) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("2*x", "100")), 200.0);
}

TEST(Calculator, Test9) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("x/2", "100")), 50.0);
}

TEST(Calculator, Test10) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("2^x", "10")), 1024.0);
}

TEST(Calculator, Test11) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("xmod3", "10")), 1);
}

TEST(Calculator, Test12) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("-x", "10")), -10.0);
}

TEST(Calculator, Test13) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("-x", "-10")), 10.0);
}

TEST(Calculator, Test14) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("+x", "100")), 100.0);
}

TEST(Calculator, Test15) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("+x", "-100")), -100.0);
}

TEST(Calculator, Test16) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("cosx", "10")), -0.839072);
}

TEST(Calculator, Test17) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("sinx", "10")), -0.544021);
}

TEST(Calculator, Test18) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("tanx", "10")), 0.648361);
}

TEST(Calculator, Test19) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("acosx", "1")), 0.0);
}

TEST(Calculator, Test20) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("asinx", "1")), 1.570796);
}

TEST(Calculator, Test21) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("atanx", "1")), 0.785398);
}

TEST(Calculator, Test22) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("sqrtx", "100")), 10.0);
}

TEST(Calculator, Test23) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("lnx", "10")), 2.302585);
}

TEST(Calculator, Test24) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("logx", "100")), 2.0);
}

TEST(Calculator, Test25) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("(2+x)*x", "100")), 10200.0);
}

TEST(Calculator, Test26) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(
      stod(calc.TakeResult("-logx+10*2+lnx+(2*4)-12+lnx+2^4-12+2*x", "100")),
      227.210340);
}

TEST(Calculator, Test27) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(
      stod(calc.TakeResult("((2+((2+4)*5)-17)+(log(12)+14*2/(24+17)))", "100")),
      16.762108);
}

TEST(Calculator, Test28) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("2e(-3)", "100")), 0.002);
}

TEST(Calculator, Test29) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("2e3", "100")), 2000);
}

TEST(Calculator, Test30) {
  CalculatorModel calc;
  ASSERT_DOUBLE_EQ(stod(calc.TakeResult("2+(-logx)", "100")), 0.0);
}

TEST(Calculator, Test31) {
  CalculatorModel calc;
  EXPECT_THROW(
      {
        stod(calc.TakeResult("2+(-logx)", "s;d;"));
        throw invalid_argument("x is invalid");
      },
      invalid_argument);
}

TEST(Calculator, Test32) {
  CalculatorModel calc;
  EXPECT_THROW(
      {
        stod(calc.TakeResult("'2+(-logx)", "7"));
        throw invalid_argument("unknown character symbol 0");
      },
      invalid_argument);
}

TEST(Calculator, Test33) {
  CalculatorModel calc;
  EXPECT_THROW(
      {
        stod(calc.TakeResult("2+(-logx)", "2.2.7"));
        throw invalid_argument("x is invalid");
      },
      invalid_argument);
}

TEST(Calculator, Test34) {
  CalculatorModel calc;
  EXPECT_THROW(
      {
        stod(calc.TakeResult("2.2.2", "7"));
        throw invalid_argument("unknown character symbol 0");
      },
      invalid_argument);
}

TEST(Calculator, Test35) {
  CalculatorModel calc;
  EXPECT_THROW(
      {
        stod(calc.TakeResult("loz7", "7"));
        throw invalid_argument("unknown character symbol 0");
      },
      invalid_argument);
}

TEST(Calculator, Test36) {
  CalculatorModel calc;
  EXPECT_THROW(
      {
        calc.TakeResult("log", "7");
        throw domain_error(
            "Унарный оператор не может быть последним элементом символ 0");
      },
      domain_error);
}

TEST(Calculator, Test37) {
  CalculatorModel calc;
  EXPECT_THROW(
      {
        calc.TakeResult("((2+2)))", "7");
        throw domain_error(
            "Количество закрывающих скобок больше чем открывающих символ 7");
      },
      domain_error);
}

TEST(Calculator, Test38) {
  CalculatorModel calc;
  EXPECT_THROW(
      {
        calc.TakeResult("((((2+2)))", "7");
        throw domain_error(
            "Количество закрывающих скобок больше чем открывающих символ");
      },
      domain_error);
}

TEST(Calculator, Test39) {
  CalculatorModel calc;
  EXPECT_THROW(
      {
        calc.TakeResult("((((2+2)))", "7");
        throw domain_error(
            "Количество закрывающих скобок больше чем открывающих символ");
      },
      domain_error);
}

TEST(Calculator, Test40) {
  CalculatorModel calc;
  EXPECT_THROW(
      {
        calc.TakeResult("2(2+2)", "7");
        throw domain_error(
            "Перед открывающей скобкой не может стоять число символ 0");
      },
      domain_error);
}

TEST(Calculator, Test41) {
  CalculatorModel calc;
  EXPECT_THROW(
      {
        calc.TakeResult("(*2+2)", "7");
        throw domain_error(
            "После открывающей скобки из бинарных операторов может быть только "
            "открывающая скобка символ 0");
      },
      domain_error);
}

TEST(Calculator, Test42) {
  CalculatorModel calc;
  EXPECT_THROW(
      {
        calc.TakeResult("(2+2-)", "7");
        throw domain_error(
            "После бинарного оператора могут стоять числа унарные операторы и "
            "открывающая скобка символ 4");
      },
      domain_error);
}

TEST(Calculator, Test43) {
  CalculatorModel calc;
  EXPECT_THROW(
      {
        calc.TakeResult("(2+2)2", "7");
        throw domain_error("Перед числом не может стоять закрывающая скобка 5");
      },
      domain_error);
}

TEST(Calculator, Test44) {
  CalculatorModel calc;
  EXPECT_THROW(
      {
        calc.TakeResult("(2+2+log)", "7");
        throw domain_error(
            "Перед закрывающей скобкой может быть либо число либо другая "
            "скобка "
            "символ 6");
      },
      domain_error);
}

TEST(Calculator, Test45) {
  CalculatorModel calc;
  EXPECT_THROW(
      {
        calc.TakeResult("log*2", "7");
        throw domain_error(
            "Перед бинарным оператором может стоять либо число либо "
            "закрывающая "
            "скобка символ 1");
      },
      domain_error);
}

TEST(Calculator, Test46) {
  CalculatorModel calc;
  EXPECT_THROW(
      {
        calc.TakeResult("*2", "7");
        throw domain_error(
            "Кроме скобок бинарные операторы не могут стоять в начале и конце");
      },
      domain_error);
}

TEST(Calculator, Test47) {
  CalculatorModel calc;
  EXPECT_THROW(
      {
        calc.TakeResult("e-2", "7");
        throw domain_error(
            "После е может быть либо число ли открывающая скобка символ 0");
      },
      domain_error);
}

TEST(Calculator, Test48) {
  CalculatorModel calc;
  EXPECT_THROW(
      {
        calc.TakeResult("(2+2)(2+2)", "7");
        throw domain_error(
            "После закрывающей скобки, открывающая скобка стоять не может "
            "символ 4");
      },
      domain_error);
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}