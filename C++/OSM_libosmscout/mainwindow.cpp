#include "mainwindow.h"

#include <Drawer.h>
#include <osmscout/db/Database.h>
#include <osmscout/feature/ConstructionYearFeature.h>
#include <osmscoutmap/MapService.h>
#include <osmscoutmapqt/MapPainterQt.h>

#include <QGuiApplication>

#include "StyleWidgetTab.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(int argc, char* argv[], double screen, QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      MapData_("QMap", argc, argv, screen) {
  ui->setupUi(this);
  ui->Tab->tabBar()->setStyle(new CustomTabStyle);
  scene_ = new Paint();
  ui->graphicsView->setScene(scene_);
  ui->graphicsView->viewport()->installEventFilter(this);
  scene_->setView(ui->graphicsView);
  MapData_.OpenDatabase();
  router_ = new Router();
  args_ = MapData_.GetArguments();
  scene_->setProjections(&MapData_.projection);
  pixmap_ = new QPixmap(static_cast<int>(args_.width),
                        static_cast<int>(args_.height));
  painter_ = new QPainter(pixmap_);
}

void MainWindow::SetData() {
  osmscout::MapPainterQt mapPainter(MapData_.styleConfig);
  osmscout::TypeInfoRef buildingType =
      MapData_.database->GetTypeConfig()->GetTypeInfo("building");
  MapData_.LoadData();
  if (mapPainter.DrawMap(MapData_.projection, MapData_.drawParameter,
                         MapData_.data, painter_)) {
    scene_->setMap(pixmap_);
  }
}

void MainWindow::calculateNewImageSize(double zoom) {
  scene_->clearMap();
  args_.zoom.SetMagnification(args_.zoom.GetMagnification() * zoom);
  MapData_.projection.Set(args_.center, args_.angle.AsRadians(), args_.zoom,
                          args_.dpi, args_.width, args_.height);
  delete painter_;
  delete pixmap_;
  pixmap_ = new QPixmap(static_cast<int>(args_.width),
                        static_cast<int>(args_.height));
  painter_ = new QPainter(pixmap_);
  osmscout::MapPainterQt mapPainter(MapData_.styleConfig);
  MapData_.LoadData();
  if (mapPainter.DrawMap(MapData_.projection, MapData_.drawParameter,
                         MapData_.data, painter_)) {
    scene_->setMap(pixmap_);
  }
}

bool MainWindow::eventFilter(QObject* object, QEvent* event) {
  if (event->type() == QEvent::Wheel) {
    QWheelEvent* eve = dynamic_cast<QWheelEvent*>(event);
    double scaleZoom = 1.2;
    zoom *= scaleZoom;
    if (eve->delta() > 0) {
      calculateNewImageSize(scaleZoom);
    } else if (eve->delta() < 0) {
      calculateNewImageSize(1.0 / scaleZoom);
    }
  }
  return false;
}

MainWindow::~MainWindow() {
  delete ui;
  delete router_;
}

void MainWindow::on_CalculatePath_clicked() {
  router_->SetVehicle(ui->VehicleBox->currentIndex());
  router_->set_strategy(ui->StrategyBox->currentIndex());
  std::vector<osmscout::GeoCoord> points = scene_->getPoints();
  if (points.size() > 1) {
    osmscout::Distance dist = points[0].GetDistance(points[1]);
    router_->LoadDataNodes(args_, dist, points[0]);
    int startNodeIndex;
    Route Path =
        router_->CalculatePathRoute(points[0], points[1], &startNodeIndex);
    std::vector<Node> graph = router_->getGraph();
    int touch_size = std::count_if(graph.begin(), graph.end(), [](Node& i) { return i.flag == true; });
    if (ui->CheckDots->isChecked()) {
      scene_->PaintDots(graph, Path.nodeIndexes);
    }
    double total_path = 0.0;
    scene_->PaintPath(graph, Path.nodeIndexes, &MapData_, startNodeIndex,
                      &total_path, router_->getVehicle());
    ui->Lat_start->setText(QString::number(points[0].GetLat()));
    ui->Lon_start->setText(QString::number(points[0].GetLon()));
    ui->Lat_end->setText(QString::number(points[1].GetLat()));
    ui->Lon_end->setText(QString::number(points[1].GetLon()));
    ui->Distance->setText(QString::number(dist.AsMeter()) + " м");
    ui->graph_size->setText(QString::number(graph.size()) + " точек");
    ui->touch_size->setText(QString::number(touch_size) + " точек");
    ui->total_time->setText(QString::number(Path.total_time) + " мc");
    ui->real_distance->setText(QString::number(total_path) + " м");
  }
}
