#ifndef CALC_HEADERS_DEPOSITWINDOW_H_
#define CALC_HEADERS_DEPOSITWINDOW_H_

#include <QWidget>

#include "Controller.h"

namespace Ui {
class DepositWindow;
}

namespace s21 {
class DepositWindow : public QWidget {
  Q_OBJECT

 public:
  explicit DepositWindow(Controller *controller, QWidget *parent = nullptr);
  // Выравнивание текста поцентру
  void AlignOutputText();
  ~DepositWindow();

 private slots:
  void on_calculation_clicked();

 private:
  Ui::DepositWindow *ui;
  Controller *controller_;
};
}  // namespace s21

#endif  // CALC_HEADERS_DEPOSITWINDOW_H_
