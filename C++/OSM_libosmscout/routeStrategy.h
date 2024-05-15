#ifndef ROUTESTRATEGY_H
#define ROUTESTRATEGY_H

#include <queue>
#include <unordered_set>

#include "structNodePath.h"

class RouteStrategyInterface {
 public:
  virtual Route findPath(std::vector<Node>& graph, int startNodeIndex,
                         int endNodeIndex) const = 0;
  virtual ~RouteStrategyInterface() {}
};

class DijkstraImplementation : public RouteStrategyInterface {
 public:
  DijkstraImplementation() {}
  Route findPath(std::vector<Node>& graph, int startNodeIndex,
                 int endNodeIndex) const override;
  ~DijkstraImplementation() {}
};

class AStarImplementation : public RouteStrategyInterface {
 public:
  AStarImplementation() {}
  Route findPath(std::vector<Node>& graph, int startNodeIndex,
                 int endNodeIndex) const override;
  ~AStarImplementation() {}

 private:
  double heuristicFunc(const Node& start, const Node& end) const {
    return 10.0 *
           start.point.GetCoord().GetDistance(end.point.GetCoord()).AsMeter();
  }
};

class DuoDijkstraImplementation : public RouteStrategyInterface {
 public:
  DuoDijkstraImplementation() {}
  Route findPath(std::vector<Node>& graph, int startNodeIndex,
                 int endNodeIndex) const override;
  ~DuoDijkstraImplementation() {}
};

class DuoAStarImplementation : public RouteStrategyInterface {
 public:
  DuoAStarImplementation() {}
  Route findPath(std::vector<Node>& graph, int startNodeIndex,
                 int endNodeIndex) const override;
  ~DuoAStarImplementation() {}

 private:
  double heuristicFunc(const Node& start, const Node& end) const {
    return 5.0 *
           start.point.GetCoord().GetDistance(end.point.GetCoord()).AsMeter();
  }
};

class BellManFordImplementation : public RouteStrategyInterface {
 public:
  BellManFordImplementation() {}
  Route findPath(std::vector<Node>& graph, int startNodeIndex,
                 int endNodeIndex) const override;
  ~BellManFordImplementation() {}
 private:
  void Iteration(std::vector<Node>& graph, int startNodeIndex, std::unordered_set<int> rNI);
};

class LevitImplementation : public RouteStrategyInterface {
 public:
  LevitImplementation() {}
  Route findPath(std::vector<Node>& graph, int startNodeIndex,
                 int endNodeIndex) const override;
  ~LevitImplementation() {}
};

#endif  // ROUTESTRATEGY_H
