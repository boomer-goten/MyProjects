#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPoint>
#include <QTextStream>
#include <QTimer>

#include "../headers/Controller.h"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
 public:
  MainWindow(Controller& controller_arg, QWidget* parent = nullptr)
      : QMainWindow(parent),
        ui(new Ui::MainWindow),
        controller_(controller_arg) {
    ui->setupUi(this);
    maze_scene_ = new QGraphicsScene(this);
    cave_scene_ = new QGraphicsScene(this);
    timer_ = new QTimer(this);
    ui->mazeView->setScene(maze_scene_);
    ui->caveView->setScene(cave_scene_);
    connect(timer_, &QTimer::timeout, this, &MainWindow::GenerateCave);
    connect(ui->openMazeButton, &QPushButton::clicked, this,
            &MainWindow::OpenMazeFile);
    connect(ui->openCaveButton, &QPushButton::clicked, this,
            &MainWindow::OpenCaveFile);
    connect(ui->saveMazeButton, &QPushButton::clicked, this,
            &MainWindow::SaveMazeFile);
    connect(ui->saveCaveButton, &QPushButton::clicked, this,
            &MainWindow::SaveCaveFile);
    connect(ui->generateMazeButton, &QPushButton::clicked, this,
            &MainWindow::GenerateMaze);
    connect(ui->findPathButton, &QPushButton::clicked, this,
            &MainWindow::FindPath);
    connect(ui->clearPointsButton, &QPushButton::clicked, this,
            &MainWindow::ClearPoints);
    connect(ui->clearAllMazeSceneButton, &QPushButton::clicked, this,
            &MainWindow::ClearAllMaze);
    connect(ui->initCaveButton, &QPushButton::clicked, this,
            &MainWindow::InitCave);
    connect(ui->oneGenerateCaveButton, &QPushButton::clicked, this,
            &MainWindow::OneStepGenerateCave);
    connect(ui->startAutoGenerateCaveButton, &QPushButton::clicked, this,
            &MainWindow::StartGenerateCave);
    connect(ui->stopAutoGenerateCaveButton, &QPushButton::clicked, this,
            &MainWindow::StopGenerateCave);
    connect(ui->clearAllCaveSceneButton, &QPushButton::clicked, this,
            &MainWindow::ClearAllCave);
    maze_scene_->setSceneRect(0, 0, 500, 500);
    cave_scene_->setSceneRect(0, 0, 500, 500);
  }

  ~MainWindow() { delete ui; }

 private slots:
  void OpenMazeFile() {
    QString filePath =
        QFileDialog::getOpenFileName(this, "Открыть файл с лабиринтом", "", "");
    std::string filename = filePath.toStdString();
    std::string res = controller_.ReadMazeFile(filename);
    if (!res.empty()) {
      QMessageBox::critical(this, "Ошибка",
                            "Ошибка при чтении файла: " + QString(res.c_str()));
    } else {
      controller_.get_data(mazeData_.rows, mazeData_.cols, mazeData_.matrix1,
                           mazeData_.matrix2);
      ClearPoints();
    }
  }
  void OpenCaveFile() {
    StopGenerateCave();
    QString filePath =
        QFileDialog::getOpenFileName(this, "Открыть файл с пещерой", "", "");
    std::string filename = filePath.toStdString();
    std::string res = controller_.ReadCaveFile(filename);
    if (!res.empty()) {
      QMessageBox::critical(this, "Ошибка",
                            "Ошибка при чтении файла: " + QString(res.c_str()));
    } else {
      controller_.get_data(caveData_.rows, caveData_.cols, caveData_.matrix);
      caveData_.is_cave_from_file = true;
      caveData_.is_cave_init = false;
      DrawCaveScene();
    }
  }

  void SaveMazeFile() {
    QString filePath =
        QFileDialog::getSaveFileName(this, "Сохранить лабиринт в файл", "", "");
    std::string filename = filePath.toStdString();
    bool res = controller_.SaveMazeFile(filename);
    if (!res) {
      QMessageBox::critical(
          this, "Ошибка",
          "Ошибка при сохранении: не удалось сохранить лабиринт в файл.");
    }
  }

  void SaveCaveFile() {
    StopGenerateCave();
    QString filePath =
        QFileDialog::getSaveFileName(this, "Сохранить пещеру в файл", "", "");
    std::string filename = filePath.toStdString();
    bool res = controller_.SaveCaveFile(filename);
    if (!res) {
      QMessageBox::critical(
          this, "Ошибка",
          "Ошибка при сохранении: не удалось сохранить пещеру в файл.");
    }
  }

  void GenerateMaze() {
    ClearAllMaze();
    controller_.GenerateLabirynth(ui->rowsCount->value(),
                                  ui->colsCount->value());
    controller_.get_data(mazeData_.rows, mazeData_.cols, mazeData_.matrix1,
                         mazeData_.matrix2);
    DrawMazeScene();
  }

  void GenerateCave() {
    controller_.OneStepGeneration(ui->limitLifeCount->value(),
                                  ui->limitDeathCount->value());
    controller_.get_data(caveData_.rows, caveData_.cols, caveData_.matrix);
    DrawCaveScene();
  }

  void InitCave() {
    StopGenerateCave();
    controller_.InitCave(ui->rowsCount_2->value(), ui->colsCount_2->value(),
                         ui->chanceInitCount->value());
    caveData_.is_cave_init = true;
    caveData_.is_cave_from_file = false;
    controller_.get_data(caveData_.rows, caveData_.cols, caveData_.matrix);
    DrawCaveScene();
  }

  void OneStepGenerateCave() {
    StopGenerateCave();
    if (caveData_.is_cave_init || caveData_.is_cave_from_file) {
      GenerateCave();
    }
  }

  void StartGenerateCave() {
    StopGenerateCave();
    if (caveData_.is_cave_init || caveData_.is_cave_from_file) {
      timer_->setInterval(ui->timeCount->value());
      timer_->start();
    }
  }

  void StopGenerateCave() { timer_->stop(); }

  void FindPath() {
    if (mazeData_.is_start_point_set && mazeData_.is_end_point_set) {
      int start[2] = {mazeData_.start_point.y(), mazeData_.start_point.x()};
      int finish[2] = {mazeData_.end_point.y(), mazeData_.end_point.x()};
      vector<std::vector<int>> path;
      controller_.FindPath(start, finish, path);
      if (!path.empty()) {
        DrawPathMazeScene(path);
      } else {
        QMessageBox::critical(
            this, "Ошибка",
            "Ошибка поиска пути: между выбранными точками пути нет.");
      }
    }
  }

  void mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton && mazeData_.rows && mazeData_.cols &&
        !mazeData_.matrix1.empty() && !mazeData_.matrix2.empty()) {
      if (!mazeData_.is_start_point_set) {
        mazeData_.is_start_point_set = true;
        QPoint clickPoint = event->pos();
        SetPoint(mazeData_.start_point, clickPoint);
      } else if (!mazeData_.is_end_point_set) {
        mazeData_.is_end_point_set = true;
        QPoint clickPoint = event->pos();
        SetPoint(mazeData_.end_point, clickPoint);
      }
    }
  }

  void SetPoint(QPoint& newPoint, QPoint& clickPoint) {
    int cellWidth = 500 / mazeData_.cols;
    int cellHeight = 500 / mazeData_.rows;
    if ((clickPoint.x() - 30) > (cellWidth * mazeData_.cols)) {
      newPoint.setX(mazeData_.cols - 1);
    } else if ((clickPoint.x() - 30) < 0) {
      newPoint.setX(0);
    } else {
      newPoint.setX((clickPoint.x() - 30) / cellWidth);
    }

    if ((clickPoint.y() - 120) > (cellHeight * mazeData_.rows)) {
      newPoint.setY(mazeData_.rows - 1);
    } else if ((clickPoint.y() - 30) < 0) {
      newPoint.setY(0);
    } else {
      newPoint.setY((clickPoint.y() - 120) / cellHeight);
    }

    int cellCenterX = (newPoint.x() * cellWidth) + (cellWidth / 2);
    int cellCenterY = (newPoint.y() * cellHeight) + (cellHeight / 2);
    int offsetX = (cellWidth - cellWidth / 2) / 2;
    int offsetY = (cellHeight - cellHeight / 2) / 2;
    QPen pen(Qt::red);
    QBrush brush(Qt::red);
    maze_scene_->addEllipse(cellCenterX - offsetX, cellCenterY - offsetY,
                            cellWidth / 2, cellHeight / 2, pen, brush);
  }

  void DrawMazeScene() {
    maze_scene_->clear();
    QPen pen(Qt::black);
    pen.setWidth(2);
    int cellWidth = maze_scene_->width() / mazeData_.cols;
    int cellHeight = maze_scene_->height() / mazeData_.rows;
    maze_scene_->addLine(0, 0, 0, cellHeight * mazeData_.rows);
    maze_scene_->addLine(0, 0, cellWidth * mazeData_.cols, 0);

    for (int i = 0; i < mazeData_.rows; ++i) {
      for (int j = 0; j < mazeData_.cols; ++j) {
        if (mazeData_.matrix1[i][j] == 1) {
          maze_scene_->addLine((j + 1) * cellWidth, i * cellHeight,
                               (j + 1) * cellWidth, (i + 1) * cellHeight);
        }
        if (mazeData_.matrix2[i][j] == 1) {
          maze_scene_->addLine(j * cellWidth, (i + 1) * cellHeight,
                               (j + 1) * cellWidth, (i + 1) * cellHeight);
        }
      }
    }
    ui->mazeView->update();
  }

  void DrawCaveScene() {
    cave_scene_->clear();
    QPen pen(Qt::black);
    pen.setWidth(2);
    QBrush brush(Qt::black);
    int cellWidth = cave_scene_->width() / caveData_.cols;
    int cellHeight = cave_scene_->height() / caveData_.rows;

    cave_scene_->addRect(0, 0, cellWidth * caveData_.cols,
                         cellHeight * caveData_.rows);

    for (int i = 0; i < caveData_.rows; ++i) {
      for (int j = 0; j < caveData_.cols; ++j) {
        if (caveData_.matrix[i][j] == 1) {
          cave_scene_->addRect(j * cellWidth, i * cellHeight, cellWidth,
                               cellHeight, pen, brush);
        }
      }
    }
    ui->caveView->update();
  }

  void DrawPathMazeScene(const vector<std::vector<int>>& path) {
    QPen pen(Qt::red);
    pen.setWidth(2);
    QBrush brush(Qt::red);
    int cellWidth = maze_scene_->width() / mazeData_.cols;
    int cellHeight = maze_scene_->height() / mazeData_.rows;

    for (size_t i = 0; i < path.size() - 1; ++i) {
      int x1 = path[i][1] * cellWidth + cellWidth / 2;
      int y1 = path[i][0] * cellHeight + cellHeight / 2;
      int x2 = path[i + 1][1] * cellWidth + cellWidth / 2;
      int y2 = path[i + 1][0] * cellHeight + cellHeight / 2;
      maze_scene_->addLine(x1, y1, x2, y2, pen);
    }
    ui->mazeView->update();
  }

  void ClearPoints() {
    mazeData_.is_start_point_set = false;
    mazeData_.is_end_point_set = false;
    DrawMazeScene();
  }

  void ClearAllMaze() {
    mazeData_.is_start_point_set = false;
    mazeData_.is_end_point_set = false;
    mazeData_.matrix1.clear();
    mazeData_.matrix2.clear();
    mazeData_.cols = 0;
    mazeData_.rows = 0;
    maze_scene_->clear();
  }

  void ClearAllCave() {
    StopGenerateCave();
    caveData_.rows = 0;
    caveData_.cols = 0;
    caveData_.matrix.clear();
    caveData_.is_cave_from_file = false;
    caveData_.is_cave_init = false;
    cave_scene_->clear();
  }

 private:
  struct MazeData {
    int rows;
    int cols;
    vector<vector<int>> matrix1;
    vector<vector<int>> matrix2;
    QPoint start_point;
    QPoint end_point;
    bool is_start_point_set = false;
    bool is_end_point_set = false;
  };

  struct CaveData {
    int rows;
    int cols;
    vector<vector<int>> matrix;
    bool is_cave_from_file = false;
    bool is_cave_init = false;
  };

  Ui::MainWindow* ui;
  QGraphicsScene* maze_scene_;
  QGraphicsScene* cave_scene_;
  MazeData mazeData_;
  CaveData caveData_;
  QTimer* timer_;
  Controller& controller_;
};
#endif  // MAINWINDOW_H
