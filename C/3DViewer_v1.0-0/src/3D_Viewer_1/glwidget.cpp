#include "glwidget.h"

#if defined(__linux__)
#include <GL/gl.h>
#include <GL/glu.h>
#endif
#if defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#endif
// #include <math.h>
#include <iostream>

GLWidget::GLWidget(QWidget* parent) : QOpenGLWidget(parent) {}

GLWidget::~GLWidget() {
  s21_remove_matrix(&vertex_array);
  free(index_array.facets);
}

void GLWidget::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
}

void GLWidget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  update();
}

void GLWidget::paintGL() {
  if (vertex_array.matrix_vertex) {
    if (backColor == 0) {
      glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    } else if (backColor == 1) {
      glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    } else if (backColor == 2) {
      glClearColor(0.0f, 0.3f, 0.0f, 0.0f);
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (pType) {
      glClear(GL_DEPTH_BUFFER_BIT);
      glEnable(GL_DEPTH_TEST);
      glOrtho(-5, 5, -5, 5, -5, 5);
    } else {
      glFrustum(-2, 2, -2, 2, 0.5, 3.5);
    }

    glTranslatef(0.0, 0.0, -1.);

    glRotated(xRot, 1, 0, 0);
    glRotated(yRot, 0, 1, 0);
    glVertexPointer(3, GL_FLOAT, 0, vertex_array.matrix_vertex[0]);
    glEnableClientState(GL_VERTEX_ARRAY);
    if (vertexColor == 0) {
      glColor3d(0.0, 0.0, 0.0);
    } else if (vertexColor == 1) {
      glColor3d(1, 0.9, 0);
    } else if (vertexColor == 2) {
      glColor3d(1, 0.0, 0.9);
    }
    glPointSize(pointSize);
    if (vertexType != 2) {
      if (vertexType == 1) {
        glEnable(GL_POINT_SMOOTH);
      }
      glDrawArrays(GL_POINTS, 0, vertex_array.count_v);
    }
    if (vertexType == 1) {
      glDisable(GL_POINT_SMOOTH);
    }
    if (facetColor == 0) {
      glColor3d(0.0, 0.0, 0.0);
    } else if (facetColor == 1) {
      glColor3d(1, 0.9, 0);
    } else if (facetColor == 2) {
      glColor3d(1, 0.0, 0.9);
    }
    glLineWidth(facetWigth);
    if (facetType == 1) {
      glEnable(GL_LINE_STIPPLE);
      glLineStipple(1, 0x00ff);
    }
    glDrawElements(GL_LINES, index_array.count_v_in_f, GL_UNSIGNED_INT,
                   index_array.facets);
    glDisableClientState(GL_VERTEX_ARRAY);
    if (facetType == 1) {
      glDisable(GL_LINE_STIPPLE);
    }
  }
}

void GLWidget::draw_from_file(char* filename) {
  s21_remove_matrix(&vertex_array);
  free(index_array.facets);
  if (!parsing_obj_file(&vertex_array, &index_array, filename)) {
    normalize(&vertex_array);
    update();
  }
}

int GLWidget::change_model(float x_angle, float y_angle, float z_angle,
                           float x_move, float y_move, float z_move,
                           float scale) {
  int res = 0;
  if (fabs(x_angle) > EPS_ANGLE || fabs(y_angle) > EPS_ANGLE ||
      fabs(z_angle) > EPS_ANGLE)
    res = matrix_of_turn(x_angle, y_angle, z_angle, &vertex_array);
  if (!res && (fabs(x_move) > EPS_MOVE || fabs(y_move) > EPS_MOVE ||
               fabs(z_move) > EPS_MOVE))
    res = matrix_of_move(x_move, y_move, z_move, &vertex_array);
  if (!res && scale > 1e-3) res = matrix_of_scale(scale, &vertex_array);
  if (!res) update();
  return res;
}

void GLWidget::mousePressEvent(QMouseEvent* mo) { mPos = mo->pos(); }

void GLWidget::mouseMoveEvent(QMouseEvent* mo) {
  xRot = 1 / M_PI * (mo->pos().y() - mPos.y());
  yRot = 1 / M_PI * (mo->pos().x() - mPos.x());
  update();
}
