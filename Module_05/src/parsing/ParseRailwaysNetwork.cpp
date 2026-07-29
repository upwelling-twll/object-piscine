#include "ParseRailwaysNetwork.hpp"
#include "RailwayNetworkBuilder.hpp"
#include "Logger.hpp"

#include <format>


struct RailRaw {
    std::string from;
    std::string to;
    double      length;
    double      speedLimit;
};

struct NodeRaw {
    std::string name;
};

static std::expected<RailRaw, std::string> parseRailLine(std::string_view line)
{
    std::istringstream iss{std::string(line)};
    std::string tag;
    RailRaw rail;

    if (!(iss >> tag >> rail.from >> rail.to >> rail.length >> rail.speedLimit)
        || tag != "Rail")
    {
        return std::unexpected("Invalid rail definition");
    }
    return rail;
}

static std::expected<NodeRaw, std::string> parseNodeLine(std::string_view line)
{
    std::istringstream iss{std::string(line)};
    std::string tag;
    NodeRaw node;

    if (!(iss >> tag >> node.name) || tag != "Node")
        return std::unexpected("Invalid node definition");
    return node;
}

static bool isValidFile(const std::string& filename)
{
    if (filename.empty())
        return false;
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file: " << filename << "\n";
        return false;
    }
    return true;
}


std::expected<RailwayNetwork, std::string> parseRailwayNetwork(const std::string& filename)
{
    LOG_DBUG("parseRailwayNetwork: start");

    if (!isValidFile(filename))
        return std::unexpected("Cannot open railway network file: " + filename);

    RailwayNetworkBuilder builder;

    std::ifstream file(filename);
    std::string   line;
    int           lineNum = 0;

    while (std::getline(file, line))
    {
        ++lineNum;
        if (line.empty() || line[0] == '#')
            continue;

        if (line.starts_with("Node "))
        {
            auto result = parseNodeLine(line);
            if (!result)
            {
                std::cerr << "[line " << lineNum << "] " << result.error() << ": " << line << "\n";
                continue;
            }
            builder.addNode(result->name);
        }
        else if (line.starts_with("Rail "))
        {
            auto result = parseRailLine(line);
            if (!result)
            {
                std::cerr << "[line " << lineNum << "] " << result.error() << ": " << line << "\n";
                continue;
            }
            builder.addRail(result->from, result->to, result->length, result->speedLimit);
        }
        else
        {
            std::cerr << "[line " << lineNum << "] Unknown token: " << line << "\n";
        }
    }

    // Delegate validation + construction to the builder
    auto networkOrError = builder.build();
    if (!networkOrError)
    {
        std::cerr << "Failed to build railway network: " << networkOrError.error() << "\n";
        return std::unexpected(networkOrError.error());
    }
    return networkOrError;
}