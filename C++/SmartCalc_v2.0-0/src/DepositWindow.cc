#include "headers/DepositWindow.h"

#include "headers/DepositInputValues.h"
#include "ui_DepositWindow.h"

using std::string;

namespace s21 {
DepositWindow::DepositWindow(Controller *controller, QWidget *parent)
    : QWidget(parent), ui(new Ui::DepositWindow), controller_(controller) {
  ui->setupUi(this);
  QTextCursor cursor(ui->SummVkladValue->document());
  cursor.movePosition(QTextCursor::Start);
  ui->SummVkladValue->setTextCursor(cursor);
  ui->SummVkladValue->setFocus();
}

DepositWindow::~DepositWindow() { delete ui; }

void DepositWindow::AlignOutputText() {
  ui->ResultPercentValue->setAlignment(Qt::AlignCenter);
  ui->ResultTaxValue->setAlignment(Qt::AlignCenter);
  ui->ResultVkladValue->setAlignment(Qt::AlignCenter);
}

void DepositWindow::on_calculation_clicked() {
  DepositInputValues deposit_values;
  deposit_values.summ_deposit_value_ =
      ui->SummVkladValue->toPlainText().toStdString();
  deposit_values.term_value_ = ui->TermValue->toPlainText().toStdString();
  deposit_values.term_start_value_ =
      ui->TermStartValue->toPlainText().toStdString();
  deposit_values.stavka_percent_value_ =
      ui->StavkaPercentValue->toPlainText().toStdString();
  deposit_values.nalog_stavka_value_ =
      ui->NalogStavkaValue->toPlainText().toStdString();
  deposit_values.periodicity_value_ =
      ui->PeriodichnostValue->currentText().toStdString();
  deposit_values.replenishment_period_ =
      ui->SnyatiyaPeriod->currentText().toStdString();
  deposit_values.replenishment_start_ =
      ui->SnyatiyaStart->toPlainText().toStdString();
  deposit_values.replenishment_value_ =
      ui->SnyatiyaValue->toPlainText().toStdString();
  deposit_values.withdrawals_period_ =
      ui->PopolneniyaPeriod->currentText().toStdString();
  deposit_values.withdrawals_start_ =
      ui->PopolneniyaStart->toPlainText().toStdString();
  deposit_values.withdrawals_value_ =
      ui->PopolneniyaValue->toPlainText().toStdString();
  if (ui->KapitalizaciaYes->isChecked()) {
    deposit_values.type_deposit_ = true;
  }
  std::string NewResultPercentValue, NewResultTaxValue, NewResultVkladValue;
  controller_->CalculateDeposit(deposit_values, NewResultPercentValue,
                                NewResultTaxValue, NewResultVkladValue);
  ui->ResultPercentValue->setPlainText(
      QString::fromStdString(NewResultPercentValue));
  ui->ResultTaxValue->setPlainText(QString::fromStdString(NewResultTaxValue));
  ui->ResultVkladValue->setPlainText(
      QString::fromStdString(NewResultVkladValue));
  AlignOutputText();
}
}  // namespace s21
