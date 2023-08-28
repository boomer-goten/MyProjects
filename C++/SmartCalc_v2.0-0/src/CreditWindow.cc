#include "headers/CreditWindow.h"

#include "ui_CreditWindow.h"

namespace s21 {
CreditWindow::CreditWindow(Controller *controller, QWidget *parent)
    : QWidget(parent), ui(new Ui::CreditWindow), controller_(controller) {
  ui->setupUi(this);
  QTextCursor cursor(ui->AmountCreditValue->document());
  cursor.movePosition(QTextCursor::Start);
  ui->AmountCreditValue->setTextCursor(cursor);
  ui->AmountCreditValue->setFocus();
}

CreditWindow::~CreditWindow() { delete ui; }

void CreditWindow::AlignOutputText() {
  ui->monthly_payment_value->setAlignment(Qt::AlignCenter);
  ui->total_tax_value->setAlignment(Qt::AlignCenter);
  ui->debt_with_interest_value->setAlignment(Qt::AlignCenter);
}

void CreditWindow::on_calculation_clicked() {
  std::string take_amount_credit_value =
      ui->AmountCreditValue->toPlainText().toStdString();
  std::string take_term_credit_value =
      ui->TermValue->toPlainText().toStdString();
  std::string take_interest_rate_value =
      ui->InterestRateValue->toPlainText().toStdString();
  bool type_credit = false;
  if (ui->Differ->isChecked()) {
    type_credit = true;
  }
  std::string new_monthly_payment_value, newtotal_tax_value,
      new_debt_with_interest_value;
  controller_->CalculateCredit(take_amount_credit_value, take_term_credit_value,
                               take_interest_rate_value, type_credit,
                               new_monthly_payment_value, newtotal_tax_value,
                               new_debt_with_interest_value);
  ui->monthly_payment_value->setPlainText(
      QString::fromStdString(new_monthly_payment_value));
  ui->total_tax_value->setPlainText(QString::fromStdString(newtotal_tax_value));
  ui->debt_with_interest_value->setPlainText(
      QString::fromStdString(new_debt_with_interest_value));
  AlignOutputText();
}
}  // namespace s21
