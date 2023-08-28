#ifndef GLWIDGET_H
#define GLWIDGET_H

#define EPS_ANGLE 1e-3
#define EPS_MOVE 1e-5
// #define PI 3.1415926535

#define GL_SILENCE_DEPRECATION
#include <QApplication>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QWidget>
extern "C" {
#include "../s21_3DViewer.h"
}

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT
 public:
  GLWidget(QWidget* parent = nullptr);
  ~GLWidget();
  data_vertex vertex_array = {NULL, 0};
  data_facet index_array = {NULL, 0, 0};
  void draw_from_file(char* filename);
  int change_model(float x_angle, float y_angle, float z_angle, float x_move,
                   float y_mpve, float z_move, float scale);
  double xRot, yRot;
  int backColor = 0, vertexColor = 0, facetColor = 0, pointSize = 1,
      facetWigth = 1, vertexType, facetType, pType;

 protected:
  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();
  QPoint mPos;
  void mousePressEvent(QMouseEvent*);
  void mouseMoveEvent(QMouseEvent*);
};

#endif  // GLWIDGET_H
