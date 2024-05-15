#include <QApplication>
#include <QGuiApplication>
#include <QScreen>

#include "mainwindow.h"

int main(int argc, char* argv[]) {
  QApplication application(argc, argv, true);
  MainWindow w(argc, argv,
               QGuiApplication::primaryScreen()->physicalDotsPerInch());
  w.SetData();
  w.setWindowTitle("QMap");
  w.show();
  return application.exec();
}
