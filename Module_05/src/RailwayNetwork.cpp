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
    auto& log = railways::Logger::get();
    // log.debug(std::format("Found node: {} with ID: {}", it->second->getName(), it->second->getId()));
    return it->second;
}

Node* RailwayNetwork::findNodeById(size_t id) const
{
    if (id >= _nodes.size())
        return nullptr;
    return _nodes[id].get();
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

// std::vector<std::unique_ptr<Rail>> RailwayNetwork::getRails() const
// {
//     return _rails;
// }

// vector<vector<pair<int, int>>> RailwayNetwork::getGraph()
// {
//     vector<vector<pair<int, int>>> graph(_nodes.size());
//     for (const auto& rail : _rails)
//     {
//         size_t fromId = rail->getFrom()->getId();
//         size_t toId = rail->getTo()->getId();
//         int length = static_cast<int>(rail->getLength());
//         graph[fromId].emplace_back(toId, length);
//         graph[toId].emplace_back(fromId, length); // undirected graph
//     }
//     return graph;
// }

void RailwayNetwork::printGraph() const
{
    auto& log = railways::Logger::get();
    
    log.debug("Railway Network Graph:");
    for (const auto& node : _nodes)
    {
        log.debug(std::format("- Node: {}", node->getName()));
        const auto& neighbors = neighbours(node.get());
        for (const auto& rail : neighbors)
        {
            if (rail->getTo() != node.get())
                log.debug(std::format("  -> {} (Length: {:.2f} km)", rail->getTo()->getName(), rail->getLength()));
            else
                log.debug(std::format("  -> {} (Length: {:.2f} km)", rail->getFrom()->getName(), rail->getLength()));
        }
    }
}
