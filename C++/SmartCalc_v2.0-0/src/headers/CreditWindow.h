#ifndef CALC_HEADERS_CREDITWINDOW_H_
#define CALC_HEADERS_CREDITWINDOW_H_

#include <QWidget>

#include "Controller.h"

namespace Ui {
class CreditWindow;
}

namespace s21 {
class CreditWindow : public QWidget {
  Q_OBJECT

 public:
  explicit CreditWindow(Controller *controller, QWidget *parent = nullptr);
  void AlignOutputText();
  ~CreditWindow();

 private slots:
  void on_calculation_clicked();

 private:
  Ui::CreditWindow *ui;
  Controller *controller_;
};
}  // namespace s21

#endif  // CALC_HEADERS_CREDITWINDOW_H_
