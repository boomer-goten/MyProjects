#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Drawer.h"
#include "paint.h"
#include "router.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(int argc, char *argv[], double screen, QWidget *parent = nullptr);
  ~MainWindow();
  void SetData();
  void calculateNewImageSize(double zoom);
  bool eventFilter(QObject *object, QEvent *event);

 private slots:
  void on_CalculatePath_clicked();

 private:
  Paint *scene_;
  Ui::MainWindow *ui;
  DrawMapDemo MapData_;
  Arguments args_;
  QPainter *painter_;
  QPixmap *pixmap_;
  double zoom = 1;
  Router *router_;
};
#endif  // MAINWINDOW_H
