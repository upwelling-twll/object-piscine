#ifndef PATHFINDINGSTRATEGY_HPP
#define PATHFINDINGSTRATEGY_HPP
#include <iostream>
#include <expected>
#include <string>
#include <vector>

class IEdgeCostCalculator;
class RailwayNetwork;
class Train;

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
          const Train& train
      ) = 0;
};

class DijkstraDistanceStrategy : public PathfindingStrategy {
    private:
        IEdgeCostCalculator& calculator;

    public:
      std::expected<Route, std::string> findRoute(
          const RailwayNetwork& network, 
          const Train& train
      ) override;

    // Returns {distances, parents} for path reconstruction
    std::pair<std::vector<int>, std::vector<int>> algorithm(std::vector<std::vector<std::pair<int, int>>> &graph, int start);
    DijkstraDistanceStrategy(IEdgeCostCalculator& calculator)
        : calculator(calculator)
    {
    }
};

class AStarTimeEstimatorStrategy : public PathfindingStrategy {
  public:
      std::expected<Route, std::string> findRoute(
          const RailwayNetwork& network, 
          const Train& train
      ) override;
};

#endif