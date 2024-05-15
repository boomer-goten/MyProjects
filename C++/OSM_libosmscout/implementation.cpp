#include <queue>
#include <thread>
#include <deque>

#include "routeStrategy.h"

Route DijkstraImplementation::findPath(std::vector<Node>& graph,
                                       int startNodeIndex,
                                       int endNodeIndex) const {
  std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
  std::priority_queue<std::pair<double, int>,
                      std::vector<std::pair<double, int>>,
                      std::greater<std::pair<double, int>>>
      prior_queue;
  std::vector<double> distance(graph.size(),
                               std::numeric_limits<double>::max());
  std::vector<size_t> previous(graph.size(), SIZE_MAX);
  distance[startNodeIndex] = 0.0;
  prior_queue.push({0.0, startNodeIndex});
  while (!prior_queue.empty()) {
    int currentNodeIndex = prior_queue.top().second;
    prior_queue.pop();
    if (currentNodeIndex == endNodeIndex) {
      break;
    }
    for (const auto& path : graph[currentNodeIndex].paths) {
      size_t neighborNodeIndex = path.targetNodeIndex;
      double edgeWeight = path.costs;
      graph[neighborNodeIndex].flag = true;
      if (distance[currentNodeIndex] + edgeWeight <
          distance[neighborNodeIndex]) {
        distance[neighborNodeIndex] = distance[currentNodeIndex] + edgeWeight;
        previous[neighborNodeIndex] = currentNodeIndex;
        prior_queue.push({distance[neighborNodeIndex], neighborNodeIndex});
      }
    }
  }
  std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
  Route route;
  route.total_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000000.0;
  size_t currentNodeIndex = endNodeIndex;
  while (currentNodeIndex != (size_t)startNodeIndex) {
    route.nodeIndexes.push_back(currentNodeIndex);
    currentNodeIndex = previous[currentNodeIndex];
  }
  route.nodeIndexes.push_back(startNodeIndex);
  route.totalCosts = distance[endNodeIndex];
  std::reverse(route.nodeIndexes.begin(), route.nodeIndexes.end());
  return route;
}

Route AStarImplementation::findPath(std::vector<Node>& graph,
                                    int startNodeIndex,
                                    int endNodeIndex) const {
  std::priority_queue<std::pair<double, int>,
                      std::vector<std::pair<double, int>>,
                      std::greater<std::pair<double, int>>>
      prior_queue;
  std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
  std::vector<double> distance(graph.size(),
                               std::numeric_limits<double>::max());
  std::vector<size_t> previous(graph.size(), SIZE_MAX);
  distance[startNodeIndex] = 0.0;
  prior_queue.push({0.0, startNodeIndex});
  while (!prior_queue.empty()) {
    int currentNodeIndex = prior_queue.top().second;
    prior_queue.pop();
    if (currentNodeIndex == endNodeIndex) {
      break;
    }
    for (const auto& path : graph[currentNodeIndex].paths) {
      size_t neighborNodeIndex = path.targetNodeIndex;
      graph[neighborNodeIndex].flag = true;
      double edgeWeight = path.costs;
      if (distance[currentNodeIndex] + edgeWeight <
          distance[neighborNodeIndex]) {
        distance[neighborNodeIndex] = distance[currentNodeIndex] + edgeWeight;
        double newPriorityCost =
            distance[neighborNodeIndex] +
            heuristicFunc(graph[neighborNodeIndex], graph[endNodeIndex]);
        previous[neighborNodeIndex] = currentNodeIndex;
        prior_queue.push({newPriorityCost, neighborNodeIndex});
      }
    }
  }
  std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
  Route route;
  route.total_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000000.0;
  size_t currentNodeIndex = endNodeIndex;
  while (currentNodeIndex != (size_t)startNodeIndex) {
    route.nodeIndexes.push_back(currentNodeIndex);
    currentNodeIndex = previous[currentNodeIndex];
  }
  route.nodeIndexes.push_back(startNodeIndex);
  route.totalCosts = distance[endNodeIndex];
  std::reverse(route.nodeIndexes.begin(), route.nodeIndexes.end());
  return route;
}

Route DuoDijkstraImplementation::findPath(std::vector<Node>& graph,
                                          int startNodeIndex,
                                          int endNodeIndex) const {
  std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
  std::priority_queue<std::pair<double, int>,
                      std::vector<std::pair<double, int>>,
                      std::greater<std::pair<double, int>>>
      prior_queue_forward;
  std::priority_queue<std::pair<double, int>,
                      std::vector<std::pair<double, int>>,
                      std::greater<std::pair<double, int>>>
      prior_queue_back;
  std::vector<double> distance_forward(graph.size(),
                               std::numeric_limits<double>::max());
  std::vector<double> distance_back(graph.size(),
                                    std::numeric_limits<double>::max());
  std::vector<size_t> previous_forward(graph.size(), SIZE_MAX);
  std::vector<size_t> previous_back(graph.size(), SIZE_MAX);
  distance_forward[startNodeIndex] = 0.0;
  prior_queue_forward.push({0.0, startNodeIndex});
  distance_back[endNodeIndex] = 0.0;
  prior_queue_back.push({0.0, endNodeIndex});
  size_t touch_point = 0;
  while (!prior_queue_forward.empty() && !prior_queue_back.empty()) {
    int currentNodeIndexForward = prior_queue_forward.top().second;
    prior_queue_forward.pop();
    int currentNodeIndexBack = prior_queue_back.top().second;
    prior_queue_back.pop();
    if (distance_forward[currentNodeIndexBack] != std::numeric_limits<double>::max()) {
      touch_point = currentNodeIndexBack;
      break;
    }
    if (distance_back[currentNodeIndexForward] != std::numeric_limits<double>::max()) {
      touch_point = currentNodeIndexForward;
      break;
    }
//    std::thread path_forward([&]() {
        for (const auto& path : graph[currentNodeIndexForward].paths) {
            size_t neighborNodeIndex = path.targetNodeIndex;
            double edgeWeight = path.costs;
            graph[neighborNodeIndex].flag = true;
            if (distance_forward[currentNodeIndexForward] + edgeWeight <
                distance_forward[neighborNodeIndex]) {
                distance_forward[neighborNodeIndex] = distance_forward[currentNodeIndexForward] + edgeWeight;
                previous_forward[neighborNodeIndex] = currentNodeIndexForward;
                prior_queue_forward.push({distance_forward[neighborNodeIndex], neighborNodeIndex});
            }
        }
//    });
//    std::thread path_back([&]() {
        for (const auto& path : graph[currentNodeIndexBack].paths) {
            size_t neighborNodeIndex = path.targetNodeIndex;
            double edgeWeight = path.costs;
            graph[neighborNodeIndex].flag = true;
            if (distance_back[currentNodeIndexBack] + edgeWeight <
                distance_back[neighborNodeIndex]) {
                distance_back[neighborNodeIndex] = distance_back[currentNodeIndexBack] + edgeWeight;
                previous_back[neighborNodeIndex] = currentNodeIndexBack;
                prior_queue_back.push({distance_back[neighborNodeIndex], neighborNodeIndex});
            }
        }
//    });
//    path_forward.join();
//    path_back.join();
  }
  std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
  Route route;
  route.total_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000000.0;
  size_t currentNodeIndex = touch_point;
  double total_distance = 0;
  while (currentNodeIndex != (size_t)startNodeIndex) {
    route.nodeIndexes.push_back(currentNodeIndex);
    currentNodeIndex = previous_forward[currentNodeIndex];
  }
  route.nodeIndexes.push_back(startNodeIndex);
  total_distance += distance_forward[touch_point];
  currentNodeIndex = touch_point;
  std::reverse(route.nodeIndexes.begin(), route.nodeIndexes.end());
  route.nodeIndexes.pop_back();
  while (currentNodeIndex != (size_t)endNodeIndex) {
    route.nodeIndexes.push_back(currentNodeIndex);
    currentNodeIndex = previous_back[currentNodeIndex];
  }
  route.nodeIndexes.push_back(endNodeIndex);
  total_distance += distance_back[touch_point];
  route.totalCosts = total_distance;
  return route;
}

Route DuoAStarImplementation::findPath(std::vector<Node>& graph,
                                       int startNodeIndex,
                                       int endNodeIndex) const {
  std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
  std::priority_queue<std::pair<double, int>,
                      std::vector<std::pair<double, int>>,
                      std::greater<std::pair<double, int>>>
      prior_queue_forward;
  std::priority_queue<std::pair<double, int>,
                      std::vector<std::pair<double, int>>,
                      std::greater<std::pair<double, int>>>
      prior_queue_back;
  std::vector<double> distance_forward(graph.size(),
                                       std::numeric_limits<double>::max());
  std::vector<double> distance_back(graph.size(),
                                    std::numeric_limits<double>::max());
  std::vector<size_t> previous_forward(graph.size(), SIZE_MAX);
  std::vector<size_t> previous_back(graph.size(), SIZE_MAX);
  distance_forward[startNodeIndex] = 0.0;
  prior_queue_forward.push({0.0, startNodeIndex});
  distance_back[endNodeIndex] = 0.0;
  prior_queue_back.push({0.0, endNodeIndex});
  size_t touch_point = 0;
  while (!prior_queue_forward.empty() && !prior_queue_back.empty()) {
    int currentNodeIndexForward = prior_queue_forward.top().second;
    prior_queue_forward.pop();
    int currentNodeIndexBack = prior_queue_back.top().second;
    prior_queue_back.pop();
    if (distance_forward[currentNodeIndexBack] != std::numeric_limits<double>::max()) {
      touch_point = currentNodeIndexBack;
      break;
    }
    if (distance_back[currentNodeIndexForward] != std::numeric_limits<double>::max()) {
      touch_point = currentNodeIndexForward;
      break;
    }
        for (const auto& path : graph[currentNodeIndexForward].paths) {
            size_t neighborNodeIndex = path.targetNodeIndex;
            double edgeWeight = path.costs;
            graph[neighborNodeIndex].flag = true;
            if (distance_forward[currentNodeIndexForward] + edgeWeight <
                distance_forward[neighborNodeIndex]) {
                distance_forward[neighborNodeIndex] = distance_forward[currentNodeIndexForward] + edgeWeight;
                double newPriorityCost =
                    distance_forward[neighborNodeIndex] +
                    heuristicFunc(graph[neighborNodeIndex], graph[endNodeIndex]);
                previous_forward[neighborNodeIndex] = currentNodeIndexForward;
                prior_queue_forward.push({newPriorityCost, neighborNodeIndex});
            }
        }
        for (const auto& path : graph[currentNodeIndexBack].paths) {
            size_t neighborNodeIndex = path.targetNodeIndex;
            double edgeWeight = path.costs;
            graph[neighborNodeIndex].flag = true;
            if (distance_back[currentNodeIndexBack] + edgeWeight <
                distance_back[neighborNodeIndex]) {
                distance_back[neighborNodeIndex] = distance_back[currentNodeIndexBack] + edgeWeight;
                double newPriorityCost =
                    distance_back[neighborNodeIndex] +
                    heuristicFunc(graph[neighborNodeIndex], graph[endNodeIndex]);
                previous_back[neighborNodeIndex] = currentNodeIndexBack;
                prior_queue_back.push({newPriorityCost, neighborNodeIndex});
            }
        }
  }
  std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
  Route route;
  route.total_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000000.0;
  size_t currentNodeIndex = touch_point;
  double total_distance = 0;
  while (currentNodeIndex != (size_t)startNodeIndex) {
    route.nodeIndexes.push_back(currentNodeIndex);
    currentNodeIndex = previous_forward[currentNodeIndex];
  }
  route.nodeIndexes.push_back(startNodeIndex);
  total_distance += distance_forward[touch_point];
  currentNodeIndex = touch_point;
  std::reverse(route.nodeIndexes.begin(), route.nodeIndexes.end());
  route.nodeIndexes.pop_back();
  while (currentNodeIndex != (size_t)endNodeIndex) {
    route.nodeIndexes.push_back(currentNodeIndex);
    currentNodeIndex = previous_back[currentNodeIndex];
  }
  route.nodeIndexes.push_back(endNodeIndex);
  total_distance += distance_back[touch_point];
  route.totalCosts = total_distance;
  return route;
}

Route BellManFordImplementation::findPath(std::vector<Node>& graph,
                                          int startNodeIndex,
                                          int endNodeIndex) const {
  std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
  std::vector<double> distance(graph.size(), std::numeric_limits<double>::max());
  distance[startNodeIndex] = 0;
  for (int i = 1; i < graph.size(); ++i) {
    for (int j = 0; j < graph.size(); ++j) {
        for (const Path& path : graph[j].paths) {
            graph[path.targetNodeIndex].flag = true;
            if (distance[j] != std::numeric_limits<int>::max() &&
                distance[j] + path.costs < distance[path.targetNodeIndex]) {
                distance[path.targetNodeIndex] = distance[j] + path.costs;
                graph[path.targetNodeIndex].previousNodeIndex = j;
            }
        }
    }
  }
  std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
  Route route;
  route.total_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000000.0;
  size_t currentNodeIndex = endNodeIndex;
  while (currentNodeIndex != startNodeIndex) {
    route.nodeIndexes.push_back(currentNodeIndex);
    currentNodeIndex = graph[currentNodeIndex].previousNodeIndex;
  }
  route.nodeIndexes.push_back(startNodeIndex);
  route.totalCosts = distance[endNodeIndex];
  std::reverse(route.nodeIndexes.begin(), route.nodeIndexes.end());
  return route;
}

Route LevitImplementation::findPath(std::vector<Node>& graph, int startNodeIndex,
                                  int endNodeIndex) const {
  std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
  std::vector<double> distance(graph.size(), std::numeric_limits<double>::max());
  distance[startNodeIndex] = 0.0;
  std::deque<int> dq;
  dq.push_back(startNodeIndex);
  std::vector<int> Sp(graph.size());
  while (!dq.empty()) {
    int currentNodeIndex = dq.front();
    dq.pop_front();
    Sp[currentNodeIndex] = 1;
    for (const auto& path : graph[currentNodeIndex].paths) {
        graph[path.targetNodeIndex].flag = true;
        if (distance[path.targetNodeIndex] > distance[currentNodeIndex] + path.costs) {
            distance[path.targetNodeIndex] = distance[currentNodeIndex] + path.costs;
            graph[path.targetNodeIndex].previousNodeIndex = currentNodeIndex;
            if (Sp[path.targetNodeIndex] == 0) {
                dq.push_back(path.targetNodeIndex);
            } else if (Sp[path.targetNodeIndex] == 1){
                dq.push_front(path.targetNodeIndex);
            }
            Sp[path.targetNodeIndex] = 1;
        }
    }
  }
  std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
  Route route;
  route.total_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000000.0;
  if (graph[endNodeIndex].previousNodeIndex == SIZE_MAX) {
    return route;
  }
  size_t currentNodeIndex = endNodeIndex;
  while (currentNodeIndex != startNodeIndex) {
    route.nodeIndexes.push_back(currentNodeIndex);
    currentNodeIndex = graph[currentNodeIndex].previousNodeIndex;
  }
  route.nodeIndexes.push_back(startNodeIndex);
  route.totalCosts = distance[endNodeIndex];
  std::reverse(route.nodeIndexes.begin(), route.nodeIndexes.end());
  return route;
}
