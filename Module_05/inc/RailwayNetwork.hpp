#ifndef RAILWAYNETWORK_HPP
# define RAILWAYNETWORK_HPP

# include <memory>
# include <vector>
# include <string>
# include <unordered_map>

# include "Node.hpp"
# include "Rail.hpp"
#include "Logger.hpp"


class RailwayNetwork
{
private:
	std::vector<std::unique_ptr<Node>> _nodes; // all nodes (cities + rail nodes)
	std::vector<std::unique_ptr<Rail>> _rails; // all rail segments

	// adjacency: node → outgoing rails (for pathfinding)
	std::unordered_map<Node*, std::vector<Rail*>> _adjacency;

	std::unordered_map<std::string, Node*> _lookup;

public:
	RailwayNetwork()  = default;
	~RailwayNetwork() = default;

	RailwayNetwork(const RailwayNetwork&)            = delete;
	RailwayNetwork& operator=(const RailwayNetwork&) = delete;
	RailwayNetwork(RailwayNetwork&&)                 = default;
	RailwayNetwork& operator=(RailwayNetwork&&)      = default;

	void addNode(std::unique_ptr<Node> node);
	void addRail(std::unique_ptr<Rail> rail);

	Node*                    findNode(const std::string& name) const;
	const std::vector<Rail*> neighbours(Node* node) const;
	double                   distance(const Rail& rail) const;

	size_t nodeCount() const { return _nodes.size(); }
	size_t railCount() const { return _rails.size(); }
	
	void printGraph() const;
};

#endif