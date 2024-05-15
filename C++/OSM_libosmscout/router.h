#ifndef ROUTER_H
#define ROUTER_H

#include <osmscout/routing/RoutingService.h>
#include <osmscout/util/Geometry.h>

#include "Drawer.h"
#include "routeStrategy.h"
#include "structNodePath.h"

enum Strategy {
  Dijkstra = 0,
  AStar = 1,
  DuoDijkstra = 2,
  DuoAStar = 3,
  Bellman = 4,
  Levit = 5
};

class Router {
 public:
  Router();
  ~Router();
  std::vector<Node>& getGraph() { return graph_; }
  void LoadDataNodes(const Arguments& args, const osmscout::Distance& maxRange,
                     osmscout::GeoCoord coord);
  void SetupGraphFromNodes();
  void SetVehicle(int vehicle) noexcept {
    if (vehicle == 0) {
      vehicle_ = osmscout::vehicleCar;
    } else if (vehicle == 1) {
      vehicle_ = osmscout::vehicleFoot;
    }
  }
  osmscout::Vehicle getVehicle() const noexcept { return vehicle_; }
  void set_strategy(int strategy) {
    if (strategy == Dijkstra) {
      SetDijkstraStrategy();
    } else if (strategy == AStar) {
      SetAStarStrategy();
    } else if (strategy == DuoDijkstra) {
      SetDuoDijkstraStrategy();
    } else if (strategy == DuoAStar) {
      SetDuoAStarStrategy();
    } else if (strategy == Bellman) {
      SetBellmanStrategy();
    } else if (strategy == Levit) {
      SetALTStrategy();
    }
  }
  Route CalculatePathRoute(osmscout::GeoCoord& start, osmscout::GeoCoord& end,
                           int* startNodeindex) {
    SetupGraphFromNodes();
    *startNodeindex = GetClosestValidNodeIndex(start);
    int end_index = GetClosestValidNodeIndex(end);
    PathCosts();
    if (*startNodeindex == end_index) {
      return Route();
    }
    return current_path_strategy_->findPath(this->graph_, *startNodeindex,
                                            end_index);
  }

 private:
  DijkstraImplementation* dImplement_;
  AStarImplementation* AImplement_;
  DuoDijkstraImplementation* DuodImplement_;
  DuoAStarImplementation* DuoAImplement_;
  BellManFordImplementation* BImplement_;
  LevitImplementation* LevitImplement_;
  RouteStrategyInterface* current_path_strategy_;
  std::vector<osmscout::RouteNode> NodeList_;
  std::vector<Node> graph_;
  osmscout::Vehicle vehicle_;
  osmscout::FileScanner routeReader_;
  uint32_t nodeCount_;

 private:
  void SetDijkstraStrategy() { current_path_strategy_ = dImplement_; }
  void SetAStarStrategy() { current_path_strategy_ = AImplement_; }
  void SetDuoDijkstraStrategy() { current_path_strategy_ = DuodImplement_; }
  void SetDuoAStarStrategy() { current_path_strategy_ = DuoAImplement_; }
  void SetBellmanStrategy() { current_path_strategy_ = BImplement_; }
  void SetALTStrategy() { current_path_strategy_ = LevitImplement_; }
  void OpenFile(const Arguments& args);
  size_t GetClosestValidNodeIndex(osmscout::GeoCoord& coord);
  double PathCost(const Path& path);
  void PathCosts();
};

#endif  // ROUTER_H
