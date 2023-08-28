#include "mainwindow.h"

#include <iostream>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setFixedSize(geometry().width(), geometry().height());
  ui->info->setReadOnly(true);
  ui->jpeg->setChecked(true);
  settings = new QSettings("3dviewer", "3D_Viewer", this);
  loadSettings();
}

MainWindow::~MainWindow() {
  saveSettings();
  delete ui;
}

void MainWindow::saveSettings() {
  settings->setValue("background color", ui->bColor->currentIndex());
  settings->setValue("vertex color", ui->vColor->currentIndex());
  settings->setValue("facet color", ui->fColor->currentIndex());
  settings->setValue("vertex size", ui->vSize->value());
  settings->setValue("facet width", ui->fWidth->value());
  settings->setValue("vertex type", ui->vType->currentIndex());
  settings->setValue("facet type", ui->fType->currentIndex());
  settings->setValue("projection type", ui->pType->currentIndex());
}

void MainWindow::loadSettings() {
  ui->bColor->setCurrentIndex(settings->value("background color", "0").toInt());
  ui->vColor->setCurrentIndex(settings->value("vertex color", "0").toInt());
  ui->fColor->setCurrentIndex(settings->value("facet color", "0").toInt());
  ui->vSize->setValue(settings->value("vertex size", "1").toInt());
  ui->fWidth->setValue(settings->value("facet width", "1").toInt());
  ui->vType->setCurrentIndex(settings->value("vertex type", "0").toInt());
  ui->fType->setCurrentIndex(settings->value("facet type", "0").toInt());
  ui->pType->setCurrentIndex(settings->value("projection type", "0").toInt());
}

void MainWindow::on_file_button_clicked() {
  on_CLEAN_clicked();
  ui->openGLWidget->xRot = 0.;
  ui->openGLWidget->yRot = 0.;
  ui->info->clear();
  QString full_filename = QFileDialog::getOpenFileName(
      this, "Choose file...", QDir::homePath(), "*.obj");
  QString filename = full_filename.right(full_filename.length() -
                                         full_filename.lastIndexOf('/') - 1);
  QByteArray path_to_file = full_filename.toLocal8Bit().data();
  char* path_to_obj = path_to_file.data();
  ui->info->insertPlainText(filename + "\n");
  ui->openGLWidget->draw_from_file(path_to_obj);
  on_applySettings_clicked();
  int ver_count = ui->openGLWidget->vertex_array.count_v;
  int index_count = ui->openGLWidget->index_array.count_f;
  if (ver_count > 0 && index_count > 0)
    ui->info->insertPlainText("Vertexes: " + QString::number(ver_count) + "\n" +
                              "Indexes: " + QString::number(index_count) +
                              "\n");
  else
    ui->info->insertPlainText("ERROR!");
}

void MainWindow::on_OK_clicked() {
  float x_angle = (float)ui->rotate_x->value();
  float y_angle = (float)ui->rotate_y->value();
  float z_angle = (float)ui->rotate_z->value();
  float x_move = (float)ui->move_x->value();
  float y_move = (float)ui->move_y->value();
  float z_move = (float)ui->move_z->value();
  float scale = (float)ui->scale->value();

  if (ui->openGLWidget->change_model(x_angle, y_angle, z_angle, x_move, y_move,
                                     z_move, scale))
    ui->info->insertPlainText("ERROR!\n");

  //    std::cout<< "x angle "<< x_angle<< std::endl;
  //    std::cout<< "y angle "<< y_angle<< std::endl;
  //    std::cout<< "z angle "<< z_angle<< std::endl;
  //    std::cout<< "x move "<< x_move<< std::endl;
  //    std::cout<< "y move "<< y_move<< std::endl;
  //    std::cout<< "z move "<< z_move<< std::endl;
  //    std::cout<< "scale "<< scale<< std::endl;
}

void MainWindow::on_CLEAN_clicked() {
  ui->move_x->setValue(0.0);
  ui->move_y->setValue(0.0);
  ui->move_z->setValue(0.0);
  ui->rotate_x->setValue(0.0);
  ui->rotate_y->setValue(0.0);
  ui->rotate_z->setValue(0.0);
  ui->scale->setValue(0.0);
}

void MainWindow::on_saveImage_clicked() {
  QString filename;
  if (ui->jpeg->isChecked()) {
    filename = QFileDialog::getSaveFileName(this, "Save as..", "name.jpeg",
                                            "JPEG (*.jpeg *.jpg)");
  } else if (ui->bmp->isChecked()) {
    filename = QFileDialog::getSaveFileName(this, "Save as..", "name.bmp",
                                            "BMP (*.bmp)");
  }
  ui->openGLWidget->grabFramebuffer().save(filename, nullptr, 100);
}

void MainWindow::on_applySettings_clicked() {
  ui->openGLWidget->backColor = ui->bColor->currentIndex();
  ui->openGLWidget->vertexColor = ui->vColor->currentIndex();
  ui->openGLWidget->facetColor = ui->fColor->currentIndex();
  ui->openGLWidget->pointSize = ui->vSize->value();
  ui->openGLWidget->facetWigth = ui->fWidth->value();
  ui->openGLWidget->vertexType = ui->vType->currentIndex();
  ui->openGLWidget->facetType = ui->fType->currentIndex();
  ui->openGLWidget->pType = ui->pType->currentIndex();
  ui->openGLWidget->update();
}

void MainWindow::on_defaultSettings_clicked() {
  ui->bColor->setCurrentIndex(0);
  ui->vColor->setCurrentIndex(0);
  ui->fColor->setCurrentIndex(0);
  ui->vSize->setValue(1);
  ui->fWidth->setValue(1);
  ui->vType->setCurrentIndex(0);
  ui->fType->setCurrentIndex(0);
  ui->pType->setCurrentIndex(0);
}
