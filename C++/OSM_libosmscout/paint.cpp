#include "paint.h"

#include "osmscout/routing/RoutingService.h"
#include "osmscout/routing/SimpleRoutingService.h"

#define BRUSH_SIZE 20

void Paint::setMap(QPixmap* value) {
  pixmapItem_.setPixmap(*value);
  pixmapItem_.setPos(0, 0);
  setBackgroundBrush(Qt::white);
  addItem(&pixmapItem_);
}

void Paint::clearMap() { QGraphicsScene::removeItem(&pixmapItem_); }

void Paint::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  if (event->buttons() & Qt::RightButton) {
    osmscout::GeoCoord data;
    projection_->PixelToGeo(event->scenePos().x(), event->scenePos().y(), data);
    coords_.push_back(data);
    QColor color(0, 0, 255, 200);
    addEllipse(event->scenePos().x() - BRUSH_SIZE / 2,
               event->scenePos().y() - 15, BRUSH_SIZE, BRUSH_SIZE,
               QPen(Qt::NoPen), QBrush(color));
  }
}

static void GetCarSpeedTable(std::map<std::string, double>& map) {
  map["highway_motorway"] = 110.0;
  map["highway_motorway_trunk"] = 100.0;
  map["highway_motorway_primary"] = 70.0;
  map["highway_motorway_link"] = 60.0;
  map["highway_motorway_junction"] = 60.0;
  map["highway_trunk"] = 100.0;
  map["highway_trunk_link"] = 60.0;
  map["highway_primary"] = 70.0;
  map["highway_primary_link"] = 60.0;
  map["highway_secondary"] = 60.0;
  map["highway_secondary_link"] = 50.0;
  map["highway_tertiary_link"] = 55.0;
  map["highway_tertiary"] = 55.0;
  map["highway_unclassified"] = 50.0;
  map["highway_road"] = 50.0;
  map["highway_residential"] = 20.0;
  map["highway_roundabout"] = 40.0;
  map["highway_living_street"] = 10.0;
  map["highway_service"] = 30.0;
}

// void Paint::PaintPath(const std::vector<Node>& graph, std::vector<size_t>&
// nodeIndexes, DrawMapDemo* database, int startNodeIndex, double *total_path,
// const osmscout::Vehicle vehicle) {
//   // TODO: fix paint for foot
//   // FIX initial parameters
//   if (nodeIndexes.empty()) {
//     this->PaintPathForZero();
//   } else {
//     if (nodeIndexes.size() == 1) {
//         nodeIndexes.push_back(nodeIndexes[0]);
//         nodeIndexes[0] = startNodeIndex;
//     }
//     std::cout << nodeIndexes.size() << std::endl;
//     osmscout::RouterParameter parametr;
//     osmscout::RoutingParameter routingparametr;
//     osmscout::FastestPathRoutingProfile
//     routingP(database->database->GetTypeConfig()); std::map<std::string,
//     double> map; GetCarSpeedTable(map); osmscout::TypeConfigRef typeConfig =
//     database->database->GetTypeConfig(); if (vehicle == osmscout::vehicleCar)
//     {
//         routingP.ParametrizeForCar(*typeConfig, map, 160);
//     } else if (vehicle == osmscout::vehicleFoot) {
//         routingP.ParametrizeForFoot(*typeConfig, 5.0);
//     }
//     std::vector<osmscout::GeoCoord> coords;
//     osmscout::SimpleRoutingService rserv(database->database, parametr,
//     "/home/alexey/libosmscout/maps/moscow-latest/"); rserv.Open(); for
//     (size_t i = 0; i < nodeIndexes.size(); ++i) {
//         coords.push_back(graph[nodeIndexes[i]].point.GetCoord());
//     }
////    auto radius = coords_[0].GetDistance(coords_[1]);
//    osmscout::RoutingResult res = rserv.CalculateRouteViaCoords(routingP,
//    coords, osmscout::Kilometers(1), routingparametr); osmscout::RouteData
//    routeDescription = res.GetRoute(); auto rdp =
//    rserv.TransformRouteDataToPoints(routeDescription); auto valueses =
//    rdp.GetPoints(); for (int i = 0; i < (int)valueses->points.size() - 1;
//    i++) {
//        osmscout::Vertex2D dataFirstDot;
//        osmscout::Vertex2D dataSecondDot;
//        projection_->GeoToPixel(valueses->points[i].GetCoord(), dataFirstDot);
//        projection_->GeoToPixel(valueses->points[i + 1].GetCoord(),
//        dataSecondDot); *total_path +=
//        valueses->points[i].GetCoord().GetDistance(valueses->points[i +
//        1].GetCoord()).AsMeter(); addLine(dataFirstDot.GetX(),
//        dataFirstDot.GetY(), dataSecondDot.GetX(), dataSecondDot.GetY());
//    }
//    rserv.Close();
//  }
//}

void Paint::PaintPath(const std::vector<Node>& graph,
                      std::vector<size_t>& nodeIndexes, DrawMapDemo* database,
                      int startNodeIndex, double* total_path,
                      const osmscout::Vehicle vehicle) {
  // TODO: fix paint for foot
  // FIX initial parameters
  if (nodeIndexes.empty()) {
    this->PaintPathForZero();
  } else {
    if (nodeIndexes.size() == 1) {
      nodeIndexes.push_back(nodeIndexes[0]);
      nodeIndexes[0] = startNodeIndex;
    }
    osmscout::RouterParameter parametr;
    osmscout::RoutingParameter routingparametr;
    osmscout::FastestPathRoutingProfile routingP(
        database->database->GetTypeConfig());
    std::map<std::string, double> map;
    GetCarSpeedTable(map);
    osmscout::TypeConfigRef typeConfig = database->database->GetTypeConfig();
    if (vehicle == osmscout::vehicleCar) {
      routingP.ParametrizeForCar(*typeConfig, map, 160);
    } else if (vehicle == osmscout::vehicleFoot) {
      routingP.ParametrizeForFoot(*typeConfig, 5.0);
    }
    osmscout::SimpleRoutingService rserv(
        database->database, parametr,
        "/home/alexey/libosmscout/maps/moscow-latest/");
    rserv.Open();
    for (size_t i = 0; i < nodeIndexes.size() - 1; ++i) {
      std::vector<osmscout::GeoCoord> coords = {
          graph[nodeIndexes[i]].point.GetCoord(),
          graph[nodeIndexes[i + 1]].point.GetCoord()};
      osmscout::RoutingResult res = rserv.CalculateRouteViaCoords(
          routingP, coords, osmscout::Kilometers(1), routingparametr);
      osmscout::RouteData routeDescription = res.GetRoute();
      auto rdp = rserv.TransformRouteDataToPoints(routeDescription);
      auto valueses = rdp.GetPoints();
      for (int i = 0; i < (int)valueses->points.size() - 1; i++) {
        osmscout::Vertex2D dataFirstDot;
        osmscout::Vertex2D dataSecondDot;
        projection_->GeoToPixel(valueses->points[i].GetCoord(), dataFirstDot);
        projection_->GeoToPixel(valueses->points[i + 1].GetCoord(),
                                dataSecondDot);
        *total_path += valueses->points[i]
                           .GetCoord()
                           .GetDistance(valueses->points[i + 1].GetCoord())
                           .AsMeter();
        addLine(dataFirstDot.GetX(), dataFirstDot.GetY(), dataSecondDot.GetX(),
                dataSecondDot.GetY());
      }
    }
    rserv.Close();
  }
}

void Paint::PaintDots(const std::vector<Node>& graph,
                      std::vector<size_t>& nodeIndexes) {
  for (auto i : graph) {
    QColor color;
    if (i.flag == true) {
      color = QColor(139, 0, 255, 200);
    } else {
      color = QColor(0, 0, 0, 200);
    }
    osmscout::Vertex2D dataFirstDot;
    projection_->GeoToPixel(i.point.GetCoord(), dataFirstDot);
    addEllipse(dataFirstDot.GetX() - BRUSH_SIZE / 4, dataFirstDot.GetY() - 5,
               BRUSH_SIZE / 2, BRUSH_SIZE / 2, QPen(Qt::NoPen), QBrush(color));
  }
  for (auto i : nodeIndexes) {
    QColor color(255, 0, 0, 200);
    osmscout::Vertex2D dataFirstDot;
    projection_->GeoToPixel(graph[i].point.GetCoord(), dataFirstDot);
    addEllipse(dataFirstDot.GetX() - BRUSH_SIZE / 4, dataFirstDot.GetY() - 5,
               BRUSH_SIZE / 2, BRUSH_SIZE / 2, QPen(Qt::NoPen), QBrush(color));
  }
}

void Paint::PaintPathForZero() {
  osmscout::Vertex2D dataFirstDot;
  osmscout::Vertex2D dataSecondDot;
  projection_->GeoToPixel(coords_[0], dataFirstDot);
  projection_->GeoToPixel(coords_[1], dataSecondDot);
  addLine(dataFirstDot.GetX(), dataFirstDot.GetY(), dataSecondDot.GetX(),
          dataSecondDot.GetY());
}

void Paint::wheelEvent(QGraphicsSceneWheelEvent* event) {
  QPointF value(event->scenePos().rx(), event->scenePos().rx());
  event->setScenePos(value);
  event->accept();
}

void Paint::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) {
  coords_.clear();
  foreach (QGraphicsItem* item, items())
    if (item->type() == QGraphicsEllipseItem::Type) {
      removeItem(item);
    } else if (item->type() == QGraphicsLineItem::Type) {
      removeItem(item);
    }
  update();
}
