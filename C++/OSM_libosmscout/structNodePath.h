#ifndef STRUCTNODEPATH_H
#define STRUCTNODEPATH_H

#include <osmscout/routing/RoutingService.h>

struct Path {
  osmscout::Distance distanceLength;
  osmscout::ObjectFileRef fileRef;
  size_t targetNodeIndex;
  uint8_t flags;
  double costs;
};

struct Node {
  osmscout::Point point;
  std::vector<Path> paths;
  double costs;
  bool flag = false;
  size_t previousNodeIndex = SIZE_MAX;
};

struct Route {
  std::vector<size_t> nodeIndexes;
  double totalCosts;
  osmscout::Distance totalLength;
  double total_time;
};

#endif  // STRUCTNODEPATH_H
