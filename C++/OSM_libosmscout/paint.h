#ifndef PAINT_H
#define PAINT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QImage>
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <iostream>

#include "Drawer.h"
#include "structNodePath.h"

class Paint : public QGraphicsScene {
  Q_OBJECT
 public:
  explicit Paint(QObject* parent = 0) : QGraphicsScene(parent) {
    setBackgroundBrush(Qt::white);
  };
  ~Paint(){};

  void setMap(QPixmap* value);
  void setView(QGraphicsView* view) { view_ = view; }
  void clearMap();
  void setProjections(osmscout::MercatorProjection* projection) {
    projection_ = projection;
  }
  std::vector<osmscout::GeoCoord> getPoints() { return coords_; }
  void PaintPath(const std::vector<Node>& graph,
                 std::vector<size_t>& nodeIndexes, DrawMapDemo* database,
                 int startNodeIndex, double* total_path,
                 osmscout::Vehicle vehicle);
  void PaintDots(const std::vector<Node>& graph,
                 std::vector<size_t>& nodeIndexes);
  using QGraphicsScene::QGraphicsScene;

 private:
  void PaintPathForZero();
  void wheelEvent(QGraphicsSceneWheelEvent* event) override;
  QGraphicsPixmapItem pixmapItem_;
  QGraphicsView* view_;
  osmscout::MercatorProjection* projection_;
  void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
  std::vector<osmscout::GeoCoord> coords_;
};

#endif  // PAINT_H
