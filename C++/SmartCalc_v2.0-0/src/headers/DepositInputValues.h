#ifndef CALC_HEADERS_DEPOSITINPUTVALUES_H_
#define CALC_HEADERS_DEPOSITINPUTVALUES_H_

using std::string;

class DepositInputValues {
 public:
  string summ_deposit_value_;
  string term_value_;
  string term_start_value_;
  string stavka_percent_value_;
  string nalog_stavka_value_;
  string periodicity_value_;
  bool type_deposit_;
  string replenishment_period_;
  string replenishment_start_;
  string replenishment_value_;
  string withdrawals_period_;
  string withdrawals_start_;
  string withdrawals_value_;
  DepositInputValues() : type_deposit_(false) {}
};

#endif  // CALC_HEADERS_DEPOSITINPUTVALUES_H_