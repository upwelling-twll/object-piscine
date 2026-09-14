#include "RailwaySimulation.hpp"
#include "ParseRailwaysNetwork.hpp"
#include "ParseTrains.hpp"
#include "RailwayNetwork.hpp"
#include "Logger.hpp"

std::expected<RailwaySimulation, std::string>
RailwaySimulation::create(SimulationConfig config)
{
    railways::Logger::get().setLevel(config.level);

    auto network = parseRailwayNetwork(config.networkFile);
    if (!network)
        return std::unexpected(network.error());

    auto trains = parseTrains(config.trainsFile);
    if (!trains)
        return std::unexpected(trains.error());

    RailwaySimulation sim(std::move(config));
    sim._network = std::move(*network);
    sim._trains  = std::move(*trains);
    sim._network.printGraph();
    return sim;
}

void    RailwaySimulation::runSimulation()
{
    auto& log = railways::Logger::get();

    for (auto& train : _trains)
    {
        auto route = _pathFinder->findRoute(_network, train);
        if (route)
        {
            // std::stringstream ss;
            // for (const auto& s : route->nodes) ss << s << " ";
            log.debug(std::format("Train {} from {} to {}: fastest route found {}.", train.getId(), train.getFrom(), train.getTo(), route->totalDistance));
        }
        else
            log.error(std::format("Train {} not found route", train.getId()));
    }
}

RailwaySimulation::RailwaySimulation(SimulationConfig cnf)
    : _config(std::move(cnf))
{
     switch (_config.strategy)
    {
        case STRATEGY::DIJKSTRA_DISTANCE:
            _pathFinder = std::make_unique<DijkstraDistanceStrategy>(); 
            break;
        case STRATEGY::A_STAR_TIME:
            _pathFinder = std::make_unique<AStarTimeEstimatorStrategy>();
            break;
    }
    auto& log = railways::Logger::get();
    log.debug("Simulation constructor called");
}

RailwaySimulation::~RailwaySimulation()
{
    // log.debug("Simulation destructor called");
}
