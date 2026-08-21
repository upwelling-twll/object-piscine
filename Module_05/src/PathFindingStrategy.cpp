#include "PathFindingStrategy.hpp"
#include "RailwayNetwork.hpp"
#include "Logger.hpp"

const int INF=1e9;


std::pair<std::vector<int>, std::vector<int>> DijkstraDistanceStrategy::algorithm(std::vector<std::vector<std::pair<int, int>>> &graph, int start)
{
	int n = static_cast<int>(graph.size());
	std::vector<int> dist(n, INF);
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
          const RailwayNetwork& network, 
          std::string_view startNode, 
          std::string_view endNode)
{
    auto& log = railways::Logger::get();

	Node* startPtr = network.findNode(std::string(startNode));
	Node* endPtr   = network.findNode(std::string(endNode));
	if (!startPtr || !endPtr)
		return std::unexpected<std::string>("Node not found");

	int startId = static_cast<int>(startPtr->getId());
	int endId   = static_cast<int>(endPtr->getId());

	// Build adjacency list from ALL rails in the network
	std::vector<std::vector<std::pair<int, int>>> graph(network.nodeCount());
	for (const auto& rail : network.getRails())
	{
		int fromId = static_cast<int>(rail->getFrom()->getId());
		int toId   = static_cast<int>(rail->getTo()->getId());
		int length = static_cast<int>(rail->getLength());
		graph[fromId].emplace_back(toId, length);
		graph[toId].emplace_back(fromId, length); // undirected graph
	}

	auto [dist, parent] = algorithm(graph, startId);

	if (dist[endId] == INF)
		return std::unexpected<std::string>("No route found");

	// Reconstruct path from end to start using parent array
	Route r;
	r.totalDistance = dist[endId];
	for (int cur = endId; cur != -1; cur = parent[cur])
	{
		Node* node = network.getNodeById(static_cast<size_t>(cur));
		if (node)
			r.nodes.push_back(node->getName());
	}
	std::reverse(r.nodes.begin(), r.nodes.end());

	log.debug(std::format("Distance from {} to {}: {}", std::string(startNode), std::string(endNode), r.totalDistance));
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
	//TODO: implement A* algorithm
	return r;
}
