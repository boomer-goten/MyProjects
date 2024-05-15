#include "router.h"

Router::Router()
    : dImplement_(new DijkstraImplementation()),
      AImplement_(new AStarImplementation()),
      DuodImplement_(new DuoDijkstraImplementation()),
      DuoAImplement_(new DuoAStarImplementation()),
      BImplement_(new BellManFordImplementation()),
      LevitImplement_(new LevitImplementation()) {
  current_path_strategy_ = dImplement_;
  vehicle_ = osmscout::vehicleCar;
}

Router::~Router() {
  delete dImplement_;
  delete AImplement_;
  delete DuodImplement_;
  delete DuoAImplement_;
  delete BImplement_;
  delete LevitImplement_;
}

void Router::LoadDataNodes(const Arguments& args,
                           const osmscout::Distance& maxRange,
                           osmscout::GeoCoord coord) {
  try {
    if (!routeReader_.IsOpen()) {
      OpenFile(args);
    }
    NodeList_.clear();
    for (uint32_t i = 1; i <= nodeCount_; ++i) {
      osmscout::RouteNode node;
      node.Read(routeReader_);
      size_t validPaths = 0;
      for (const auto& path : node.paths) {
        if (path.IsUsable(vehicle_) || path.IsRestricted(vehicle_)) {
          ++validPaths;
        }
      }
      osmscout::Distance directDistance =
          osmscout::GetSphericalDistance(coord, node.GetCoord());
      if (validPaths > 0 && directDistance <= maxRange) {
        NodeList_.push_back(node);
      }
    }
    if (routeReader_.IsOpen()) {
      routeReader_.Close();
    }
  } catch (osmscout::IOException& e) {
    osmscout::log.Error() << "Error: " << e.GetErrorMsg();
    routeReader_.CloseFailsafe();
    throw e;
  }
}

void Router::SetupGraphFromNodes() {
  graph_.clear();
  std::unordered_map<osmscout::Id, size_t> idToIndexMap;
  for (size_t i = 0; i < NodeList_.size(); ++i) {
    idToIndexMap[NodeList_[i].GetId()] = i;
  }
  graph_.reserve(NodeList_.size());
  for (const auto& routeNode : NodeList_) {
    Node node;
    node.point = routeNode.GetPoint();
    for (const auto& routePath : routeNode.paths) {
      if (!routePath.IsUsable(vehicle_) || routePath.IsRestricted(vehicle_)) {
        continue;
      }
      Path path;
      path.distanceLength = routePath.distance;
      path.targetNodeIndex = idToIndexMap[routePath.id];
      path.flags = routePath.flags;
      path.fileRef = routeNode.objects[routePath.objectIndex].object;
      node.paths.push_back(path);
    }
    graph_.push_back(node);
  }
}

void Router::OpenFile(const Arguments& args) {
  routeReader_.Open(args.map + "router.dat", osmscout::FileScanner::Sequential,
                    true);
  routeReader_.ReadFileOffset();
  nodeCount_ = routeReader_.ReadUInt32();
  routeReader_.ReadUInt32();
  NodeList_.reserve(nodeCount_);
}

size_t Router::GetClosestValidNodeIndex(osmscout::GeoCoord& coord) {
  size_t startNodeIndex = std::numeric_limits<size_t>::max();
  osmscout::Distance distance =
      osmscout::GetSphericalDistance(coord, graph_[0].point.GetCoord());
  for (size_t i = 1; i < graph_.size(); ++i) {
    osmscout::Distance currentDistance =
        osmscout::GetSphericalDistance(coord, graph_[i].point.GetCoord());
    if (currentDistance < distance) {
      startNodeIndex = i;
      distance = currentDistance;
    }
  }
  return startNodeIndex;
}

double Router::PathCost(const Path& path) {
  double costs = path.distanceLength.AsMeter();
  if (path.flags & osmscout::RouteNode::usableByCar) {
    costs += 5.0 * path.distanceLength.AsMeter();
  }
  if (path.flags & osmscout::RouteNode::usableByFoot) {
    costs += 2.0 * path.distanceLength.AsMeter();
  }
  return costs;
}

void Router::PathCosts() {
  for (auto& node : graph_) {
    for (auto& path : node.paths) {
      path.costs = PathCost(path);
    }
  }
}
