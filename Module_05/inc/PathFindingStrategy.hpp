#ifndef PATHFINDINGSTRATEGY_HPP
#define PATHFINDINGSTRATEGY_HPP
#include <iostream>
#include <expected>
#include <string>
#include <vector>

class RailwayNetwork;

struct Route {
      std::vector<std::string> nodes;
      double totalDistance;
};

class PathfindingStrategy
{
	public:
      virtual ~PathfindingStrategy() = default;
      virtual std::expected<Route, std::string> findRoute(
          const RailwayNetwork& network, 
          std::string_view startNode, 
          std::string_view endNode
      ) = 0;
};

class DijkstraDistanceStrategy : public PathfindingStrategy {
  public:
      std::expected<Route, std::string> findRoute(
          const RailwayNetwork& network, 
          std::string_view startNode, 
          std::string_view endNode
      ) override;

    // Returns {distances, parents} for path reconstruction
    std::pair<std::vector<int>, std::vector<int>> algorithm(std::vector<std::vector<std::pair<int, int>>> &graph, int start);
};

class AStarTimeEstimatorStrategy : public PathfindingStrategy {
  public:
      std::expected<Route, std::string> findRoute(
          const RailwayNetwork& network, 
          std::string_view startNode, 
          std::string_view endNode
      ) override;
};

#endif