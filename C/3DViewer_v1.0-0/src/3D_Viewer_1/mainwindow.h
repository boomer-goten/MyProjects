#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QFileDialog>
#include <QMainWindow>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void saveSettings();
  void loadSettings();

 private slots:
  void on_file_button_clicked();

  void on_OK_clicked();

  void on_CLEAN_clicked();

  void on_saveImage_clicked();

  void on_applySettings_clicked();

  void on_defaultSettings_clicked();

 private:
  Ui::MainWindow *ui;
  QSettings *settings;
};
#endif  // MAINWINDOW_H
