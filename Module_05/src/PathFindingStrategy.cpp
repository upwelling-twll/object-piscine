#include "PathFindingStrategy.hpp"
#include "RailwayNetwork.hpp"
#include "Train.hpp"
#include "Logger.hpp"
#include "IEdgeCostCalculator.hpp"

const int INF=1e9;


std::pair<std::vector<double>, std::vector<int>> DijkstraDistanceStrategy::algorithm(std::vector<std::vector<std::pair<int, double>>> &graph, int start)
{
	int n = static_cast<int>(graph.size());
	std::vector<double> dist(n, INF);
	std::vector<int> parent(n, -1);
	dist[start] = 0;
	std::vector<bool> visited(n, false);

	for (int i = 0; i < n; i++)
	{
		// 1. Find the nearest unvisited node
		int nearest = -1;
		for (int v = 0; v < n; v++)
		{
			if (!visited[v] && (nearest == -1 || dist[v] < dist[nearest]))
				nearest = v;
		}

		// All remaining nodes are unreachable
		if (nearest == -1 || dist[nearest] == INF)
			break;

		// 2. Mark it as visited
		visited[nearest] = true;

		// 3. Relax its neighbours
		for (auto &[to, weight] : graph[nearest])
		{
			if (dist[to] > dist[nearest] + weight)
			{
				dist[to] = dist[nearest] + weight;
				parent[to] = nearest;
			}
		}
	}
	return {dist, parent};
}

std::expected<Route, std::string> DijkstraDistanceStrategy::findRoute(
		IEdgeCostCalculator& calculator,
        const RailwayNetwork& network, 
        const Train& train)
{
    auto& log = railways::Logger::get();
	std::string_view startNode = train.getFrom();
    std::string_view endNode = train.getTo();
	Node* startPtr = network.findNode(std::string(startNode));
	Node* endPtr   = network.findNode(std::string(endNode));
	if (!startPtr || !endPtr)
	return std::unexpected<std::string>("Node not found");
	
	int startId = static_cast<int>(startPtr->getId());
	int endId   = static_cast<int>(endPtr->getId());
	
	// Build adjacency list from ALL rails in the network
	log.debug(std::format("node count {}", std::to_string(network.nodeCount())));
	//std::pair<int, int> - here first int is an index of NODE at the end of the edge, second int is WEIGHT of the edge
	std::vector<std::vector<std::pair<int, double>>> graph(network.nodeCount());
	for (const auto& rail : network._rails)
	{
		log.debug(std::format("checking rail #{}, extracting its To and From values", rail->getId()));
		int fromId = static_cast<int>(rail->getFrom()->getId());
		int toId   = static_cast<int>(rail->getTo()->getId());
		log.debug(std::format("checking rail #{}, passing to edgeCost", rail->getId()));

		double edgeWeight = calculator.edgeCost(train, *rail);
		if (toId != endId)
		{
			log.debug(std::format("Station stop time for train {} is {} minutes", train.getId(), train.getStationStopTime()));
			edgeWeight += train.getStationStopTime().count() * 60.0; // convert minutes to seconds
			log.debug(std::format("Adding station stop time {} for rail #{}, edgeWeight before: {}, edgeWeight after: {}", train.getStationStopTime().count(), rail->getId(), std::to_string(edgeWeight - train.getStationStopTime().count() * 60.0), std::to_string(edgeWeight)));
		}
		int length = static_cast<int>(rail->getLength());
		log.debug(std::format("Adding rail from {} with id {} ", rail->getFrom()->getName(), std::to_string(rail->getFrom()->getId())));
		graph[fromId].emplace_back(toId, edgeWeight);
		log.debug(std::format("Adding rail from {} with id {} ", rail->getTo()->getName(), std::to_string(rail->getTo()->getId())));
		graph[toId].emplace_back(fromId, edgeWeight); // undirected graph so we add both directions
	}
	log.debug(std::format("starting algo"));
	auto [dist, parent] = algorithm(graph, startId);

	if (dist[endId] == INF)
		return std::unexpected<std::string>("No route found");

	log.debug("===== DIJKSTRA RESULT =====");
	for (size_t i = 0; i < dist.size(); ++i)
	{
		Node* node = network.findNodeById(i);
		std::string nodeName = node ? std::string(node->getName()) : "UNKNOWN";
		std::string parentName = "NONE";

		if (parent[i] != -1)
		{
			Node* parentNode = network.findNodeById(parent[i]);
			if (parentNode)
			{
				parentName = std::string(parentNode->getName());
			}
		}
		log.debug(std::format(
			"{} | distance: {} | previous: {}",
			nodeName,
			dist[i],
			parentName
		));
	}
	log.debug("===========================");

	// Reconstruct path from end to start using parent array
	std::vector<int> path;
	for (int cur = endId; cur != -1; cur = parent[cur])
	{
		path.push_back(cur);
	}
	std::reverse(path.begin(), path.end());
	log.debug(std::format("Best route from {} to {}: ", std::string(startNode), std::string(endNode)));
	for (size_t i = 0; i + 1 < path.size(); ++i)
	{
		int fromId = path[i];
		int toId   = path[i + 1];

		// Find the unique rail connecting these nodes
		for (const auto& rail : network._rails)
		{
			int railFrom = static_cast<int>(rail->getFrom()->getId());
			int railTo   = static_cast<int>(rail->getTo()->getId());

			if ((railFrom == fromId && railTo == toId) ||
				(railFrom == toId && railTo == fromId))
			{
				// This is the rail used by the route
				log.debug(std::format("Using rail #{}, from {} to {}", rail->getId(), rail->getFrom()->getName(), rail->getTo()->getName()));
				break;
			}
		}
	}
	Route r;
	r.totalDistance = dist[endId];
	// TODO : for output build route using Node instances
	// for (int cur = endId; cur != -1; cur = parent[cur])
	// {
	// 	Node* node = network.findNodeById(static_cast<size_t>(cur));
	// 	if (node)
	// 		r.nodes.push_back(node->getName());
	// }
	// std::reverse(r.nodes.begin(), r.nodes.end());
	log.debug(std::format("Best route distance from {} to {}: time in seconds: {}; in minutes: {}; in hours: {}", std::string(startNode), std::string(endNode), r.totalDistance, r.totalDistance / 60.0, r.totalDistance / 3600.0));
	return r;
}

std::expected<Route, std::string> AStarTimeEstimatorStrategy::findRoute(
		  IEdgeCostCalculator& calculator,
          const RailwayNetwork& network, 
          const Train& train)
{
	Route r;
	// r.nodes.push_back(std::string(endNode));
	r.totalDistance = 100;
	//TODO: implement A* algorithm
	return r;
}
