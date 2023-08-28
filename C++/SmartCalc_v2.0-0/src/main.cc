#include <QApplication>

#include "headers/MainWindowView.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::CalculatorModel calc_model;
  s21::BankModel bank_model;
  s21::Controller controller(&calc_model, &bank_model);
  s21::MainWindow w(&controller);
  w.show();
  return a.exec();
}
