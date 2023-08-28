#ifndef CALC_HEADERS_MAINWINDOWVIEW_H_
#define CALC_HEADERS_MAINWINDOWVIEW_H_

#include <QMainWindow>
#include <iostream>

#include "Controller.h"
#include "CreditWindow.h"
#include "DepositWindow.h"
#include "Graph.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(Controller *controller, QWidget *parent = nullptr);
  void MySetDigit(const QString StringForAdd);
  void MySetCursor();
  ~MainWindow();

 private slots:
  void on_delete_2_clicked();

  void on_one_1_clicked();

  void on_zero_0_clicked();

  void on_two_2_clicked();

  void on_three_3_clicked();

  void on_four_4_clicked();

  void on_five_5_clicked();

  void on_six_6_clicked();

  void on_seven_7_clicked();

  void on_eight_8_clicked();

  void on_nine_9_clicked();

  void on_open_bracket_clicked();

  void on_close_bracket_clicked();

  void on_plus_clicked();

  void on_minus_clicked();

  void on_multiplication_clicked();

  void on_divide_clicked();

  void on_pointer_clicked();

  void on_mod_clicked();

  void on_stepen_clicked();

  void on_cos_clicked();

  void on_acos_clicked();

  void on_sqrt_clicked();

  void on_sin_clicked();

  void on_asin_clicked();

  void on_tan_clicked();

  void on_atan_clicked();

  void on_ln_clicked();

  void on_log_clicked();

  void on_edouble_clicked();

  void on_calculation_clicked();

  void on_credit_clicked();

  void on_deposit_clicked();

  void on_graph_clicked();

 private:
  Ui::MainWindow *ui;
  Controller *controller_;
  CreditWindow *credit_window_;
  DepositWindow *deposit_window_;
  Graph *graph_;
};
}  // namespace s21
#endif  // CALC_HEADERS_MAINWINDOWVIEW_H_
