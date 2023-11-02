#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  Controller controller;
  MainWindow window(controller);
  window.show();

  return app.exec();
}
