#include "headers/MainWindowView.h"

#include "ui_MainWindowView.h"

namespace s21 {
MainWindow::MainWindow(Controller *controller, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller_(controller) {
  ui->setupUi(this);
  QTextCursor cursor(ui->InputText->document());
  cursor.movePosition(QTextCursor::Start);
  ui->InputText->setTextCursor(cursor);
  ui->InputText->setFocus();
  credit_window_ = new CreditWindow(controller_);
  deposit_window_ = new DepositWindow(controller_);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::MySetCursor() {
  QTextCursor cursor(ui->InputText->document());
  cursor.movePosition(QTextCursor::End);
  ui->InputText->setTextCursor(cursor);
  ui->InputText->setFocus();
}

void MainWindow::MySetDigit(const QString StringForAdd) {
  if (ui->InputText_2->hasFocus()) {
    ui->InputText_2->insertPlainText(StringForAdd);
  } else if (ui->InputText->hasFocus()) {
    ui->InputText->insertPlainText(StringForAdd);
  } else {
    ui->InputText->insertPlainText(StringForAdd);
    MySetCursor();
  }
}

void MainWindow::on_delete_2_clicked() {
  ui->InputText->clear();
  ui->InputText_2->clear();
  ui->OutputText->setPlainText("0");
  QTextCursor cursor(ui->InputText->document());
  cursor.movePosition(QTextCursor::Start);
  ui->InputText->setTextCursor(cursor);
  ui->InputText->setFocus();
}

void MainWindow::on_zero_0_clicked() { MySetDigit("0"); }

void MainWindow::on_one_1_clicked() { MySetDigit("1"); }

void MainWindow::on_two_2_clicked() { MySetDigit("2"); }

void MainWindow::on_three_3_clicked() { MySetDigit("3"); }

void MainWindow::on_four_4_clicked() { MySetDigit("4"); }

void MainWindow::on_five_5_clicked() { MySetDigit("5"); }

void MainWindow::on_six_6_clicked() { MySetDigit("6"); }

void MainWindow::on_seven_7_clicked() { MySetDigit("7"); }

void MainWindow::on_eight_8_clicked() { MySetDigit("8"); }

void MainWindow::on_nine_9_clicked() { MySetDigit("9"); }

void MainWindow::on_open_bracket_clicked() {
  ui->InputText->insertPlainText("(");
  if (!ui->InputText->hasFocus()) {
    MySetCursor();
  }
}

void MainWindow::on_close_bracket_clicked() {
  ui->InputText->insertPlainText(")");
  if (!ui->InputText->hasFocus()) {
    MySetCursor();
  }
}

void MainWindow::on_plus_clicked() {
  ui->InputText->insertPlainText("+");
  if (!ui->InputText->hasFocus()) {
    MySetCursor();
  }
}

void MainWindow::on_minus_clicked() { MySetDigit("-"); }

void MainWindow::on_multiplication_clicked() {
  ui->InputText->insertPlainText("*");
  if (!ui->InputText->hasFocus()) {
    MySetCursor();
  }
}

void MainWindow::on_divide_clicked() {
  ui->InputText->insertPlainText("/");
  if (!ui->InputText->hasFocus()) {
    MySetCursor();
  }
}

void MainWindow::on_pointer_clicked() { MySetDigit("."); }

void MainWindow::on_mod_clicked() {
  ui->InputText->insertPlainText("mod");
  if (!ui->InputText->hasFocus()) {
    MySetCursor();
  }
}

void MainWindow::on_stepen_clicked() {
  ui->InputText->insertPlainText("^");
  if (!ui->InputText->hasFocus()) {
    MySetCursor();
  }
}

void MainWindow::on_cos_clicked() {
  ui->InputText->insertPlainText("cos()");
  if (!ui->InputText->hasFocus()) {
    MySetCursor();
  }
}

void MainWindow::on_acos_clicked() {
  ui->InputText->insertPlainText("acos()");
  if (!ui->InputText->hasFocus()) {
    MySetCursor();
  }
}

void MainWindow::on_sqrt_clicked() {
  ui->InputText->insertPlainText("sqrt()");
  if (!ui->InputText->hasFocus()) {
    MySetCursor();
  }
}

void MainWindow::on_sin_clicked() {
  ui->InputText->insertPlainText("sin()");
  if (!ui->InputText->hasFocus()) {
    MySetCursor();
  }
}

void MainWindow::on_asin_clicked() {
  ui->InputText->insertPlainText("asin()");
  if (!ui->InputText->hasFocus()) {
    MySetCursor();
  }
}

void MainWindow::on_tan_clicked() {
  ui->InputText->insertPlainText("tan()");
  if (!ui->InputText->hasFocus()) {
    MySetCursor();
  }
}

void MainWindow::on_atan_clicked() {
  ui->InputText->insertPlainText("atan()");
  if (!ui->InputText->hasFocus()) {
    MySetCursor();
  }
}

void MainWindow::on_ln_clicked() {
  ui->InputText->insertPlainText("ln()");
  if (!ui->InputText->hasFocus()) {
    MySetCursor();
  }
}

void MainWindow::on_log_clicked() {
  ui->InputText->insertPlainText("log()");
  if (!ui->InputText->hasFocus()) {
    MySetCursor();
  }
}

void MainWindow::on_edouble_clicked() {
  ui->InputText->insertPlainText("e()");
  if (!ui->InputText->hasFocus()) {
    MySetCursor();
  }
}

void MainWindow::on_calculation_clicked() {
  QString expression = ui->InputText->toPlainText();
  QString x_value = ui->InputText_2->toPlainText();
  if (x_value.isEmpty()) {
    x_value = "0";
  }
  if (expression.isEmpty()) {
    expression = "0";
  }
  std::string result_calculation = controller_->CalculateExpression(
      expression.toStdString(), x_value.toStdString());
  ui->OutputText->setPlainText(QString::fromStdString(result_calculation));
}

void MainWindow::on_credit_clicked() { credit_window_->show(); }

void MainWindow::on_deposit_clicked() { deposit_window_->show(); }

void MainWindow::on_graph_clicked() {
  QString expression = ui->InputText->toPlainText();
  graph_ = new Graph(controller_, expression.toStdString());
  graph_->show();
}
}  // namespace s21
