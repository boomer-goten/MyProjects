#ifndef CALC_HEADERS_CONTROLLER_H_
#define CALC_HEADERS_CONTROLLER_H_

#include "BankModel.h"
#include "CalculatorModel.h"
#include "DepositInputValues.h"

namespace s21 {
class Controller {
 public:
  Controller(CalculatorModel* calcmodel, BankModel* bankmodel)
      : calc_model_(calcmodel), bank_model_(bankmodel){};
  ~Controller(){};
  string CalculateExpression(string expression, string x_value) {
    return calc_model_->TakeResult(expression, x_value);
  }

  void CalculateCredit(const string& amount_credit, const string& term,
                       const string& interest_rate, const bool& payment_type,
                       string& monthly_payment_value, string& total_tax_value,
                       string& debt_with_interest_value) {
    bank_model_->TakeResultCredit(amount_credit, term, interest_rate,
                                  payment_type, monthly_payment_value,
                                  total_tax_value, debt_with_interest_value);
  }

  void CalculateDeposit(DepositInputValues& deposit_values,
                        string& result_percent, string& result_tax,
                        string& result_vklad) {
    return bank_model_->TakeResultDeposit(deposit_values, result_percent,
                                          result_tax, result_vklad);
  }

 private:
  CalculatorModel* calc_model_;
  BankModel* bank_model_;
};
}  // namespace s21

#endif  // CALC_HEADERS_CONTROLLER_H_
