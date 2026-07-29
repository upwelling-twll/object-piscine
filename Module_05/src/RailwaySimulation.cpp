#include "RailwaySimulation.hpp"
#include "ParseRailwaysNetwork.hpp"
#include "ParseTrains.hpp"
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

    return sim;
}

RailwaySimulation::RailwaySimulation(SimulationConfig cnf)
    : _config(std::move(cnf))
{
    // log.debug("Simulation constructor called");
}

RailwaySimulation::~RailwaySimulation()
{
    // log.debug("Simulation destructor called");
}
