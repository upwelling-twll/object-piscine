#include "PathFindingStrategy.hpp"
#include "RailwayNetwork.hpp"

std::expected<Route, std::string> DijkstraDistanceStrategy::findRoute(
          const RailwayNetwork& network, 
          std::string_view startNode, 
          std::string_view endNode)
{
	Route r;
	r.nodes.push_back(std::string(endNode));
	r.totalDistance = 100;
	return r;
}

std::expected<Route, std::string> AStarTimeEstimatorStrategy::findRoute(
          const RailwayNetwork& network, 
          std::string_view startNode, 
          std::string_view endNode)
{
	Route r;
	r.nodes.push_back(std::string(endNode));
	r.totalDistance = 100;
	return r;
}
