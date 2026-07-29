#include "RailwayNetwork.hpp"

void RailwayNetwork::addNode(std::unique_ptr<Node> node)
{
    Node* raw = node.get();
    _lookup[raw->getName()] = raw;
    _adjacency[raw];        // insert empty adjacency list so the node is known
    _nodes.push_back(std::move(node));
}

void RailwayNetwork::addRail(std::unique_ptr<Rail> rail)
{
    Rail* raw = rail.get();
    // Register in adjacency for both directions (undirected graph)
    _adjacency[raw->getFrom()].push_back(raw);
    _adjacency[raw->getTo()].push_back(raw);
    _rails.push_back(std::move(rail));
}


Node* RailwayNetwork::findNode(const std::string& name) const
{
    auto it = _lookup.find(name);
    if (it == _lookup.end())
        return nullptr;
    return it->second;
}

const std::vector<Rail*> RailwayNetwork::neighbours(Node* node) const
{
    auto it = _adjacency.find(node);
    if (it == _adjacency.end())
        return {};
    return it->second;
}

double RailwayNetwork::distance(const Rail& rail) const
{
    return rail.getLength();
}
