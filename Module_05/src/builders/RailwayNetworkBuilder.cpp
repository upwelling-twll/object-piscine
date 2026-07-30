#include "RailwayNetworkBuilder.hpp"
#include "City.hpp"
#include "RailNode.hpp"
#include "Rail.hpp"
#include "Logger.hpp"

#include <format>
#include <unordered_set>


RailwayNetworkBuilder& RailwayNetworkBuilder::addNode(const std::string& name)
{
    _nodes.push_back({name});
    return *this;
}

RailwayNetworkBuilder& RailwayNetworkBuilder::addRail(const std::string& from,
                                                      const std::string& to,
                                                      double length,
                                                      double speedLimit)
{
    _rails.push_back({from, to, length, speedLimit});
    return *this;
}


std::expected<const std::string, std::string> RailwayNetworkBuilder::validateNodeName(const std::string& name, const RailwayNetwork& network)
{
    auto& log = railways::Logger::get();
    if (name.empty())
        return std::unexpected("Node name cannot be empty");
    if (name.size() > 100)
        return std::unexpected("Node name exceeds maximum length (100 chars)");
    std::string_view prefix = "";
    if (name.starts_with("RailNode"))
        prefix = "RailNode";
    else if (name.starts_with("City"))
        prefix = "City";
    else
        return std::unexpected("Node name does not have expected prefix ('City' or 'RailNode')");
    std::string cleanName = name.substr(prefix.size(), name.size() - prefix.size());
    if (cleanName.empty())
        return std::unexpected("Node name is empty string");
    if (network.findNode(cleanName) != nullptr)
        return std::unexpected(std::format("Node name is not unique: {}", name));  
    return cleanName;
}

std::expected<void, std::string> RailwayNetworkBuilder::validateLength(double length)
{
    if (length <= 0.0)
        return std::unexpected("Rail length must be positive");
    if (length > 100000.0)
        return std::unexpected("Rail length exceeds maximum (100 000 km)");
    return {};
}

std::expected<void, std::string> RailwayNetworkBuilder::validateSpeedLimit(double speed)
{
    if (speed <= 0.0)
        return std::unexpected("Rail speed limit must be positive");
    if (speed > 600.0)
        return std::unexpected("Rail speed limit exceeds maximum (600 km/h)");
    return {};
}

bool    RailwayNetworkBuilder::uniqueRail(const RailwayNetwork& network, Node* from, Node* to)
{
    const auto& rails = network.neighbours(from);
    for (const auto& rail : rails)
    {
        if (rail->getTo() == to)
            return false;
    }
    return true;
}

// Build

std::expected<RailwayNetwork, std::string> RailwayNetworkBuilder::build()
{
    auto& log = railways::Logger::get();

    // 1. Validate and insert nodes, detect duplicates
    std::unordered_set<std::string> seen;
    RailwayNetwork network;

    size_t nodeId = 1;
    for (const auto& pn : _nodes)
    {   
        // Reject duplicate names
        if (!seen.insert(pn.name).second)
            return std::unexpected(std::format("Duplicate node name: '{}'", pn.name));
        
            // Validate name
        auto nameOk = validateNodeName(pn.name, network);
        if (!nameOk)
            return std::unexpected(std::format("Node '{}': {}", pn.name, nameOk.error()));

        std::unique_ptr<Node> node;
        if (pn.name.starts_with("City"))
            node = std::make_unique<City>(nodeId, *nameOk);
        else
            node = std::make_unique<RailNode>(nodeId, *nameOk);

        log.debug(std::format("  Node [{}] '{}' ({})",
            nodeId, *nameOk, node->isCity() ? "City" : "RailNode"));

        network.addNode(std::move(node));
        ++nodeId;
    }

    // 2. Validate and insert rails
    size_t railId = 1;
    for (const auto& pr : _rails)
    {
        // Validate numeric fields
        auto lenOk = validateLength(pr.length);
        if (!lenOk)
            return std::unexpected(std::format("Rail '{}'→'{}': {}", pr.from, pr.to, lenOk.error()));

        auto spdOk = validateSpeedLimit(pr.speedLimit);
        if (!spdOk)
            return std::unexpected(std::format("Rail '{}'→'{}': {}", pr.from, pr.to, spdOk.error()));

        // Resolve node pointers — must already exist in the network
        Node* fromNode = network.findNode(pr.from);
        if (!fromNode)
            return std::unexpected(std::format("Rail references unknown node: '{}'", pr.from));

        Node* toNode = network.findNode(pr.to);
        if (!toNode)
            return std::unexpected(std::format("Rail references unknown node: '{}'", pr.to));

        if (fromNode == toNode)
            return std::unexpected(std::format("Rail '{}' → '{}': self-loop not allowed", pr.from, pr.to));
        if (!uniqueRail(network, fromNode, toNode))
            return std::unexpected(std::format("Rail '{}' → '{}': duplicate rail", pr.from, pr.to));

        log.debug(std::format("  Rail [{}] '{}' → '{}' | {:.2f} km | {:.0f} km/h",
            railId, pr.from, pr.to, pr.length, pr.speedLimit));

        network.addRail(std::make_unique<Rail>(railId, fromNode, toNode, pr.length, pr.speedLimit));
        ++railId;
    }

    log.info(std::format("RailwayNetwork built: {} nodes, {} rails.",
        network.nodeCount(), network.railCount()));

    return network;
}
