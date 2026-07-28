#include "RailwaySimulation.hpp"
#include "ParseTrains.hpp"
/*Member functions*/
std::expected<RailwaySimulation, std::string> RailwaySimulation::create(SimulationConfig config)
{
    railways::Logger::get().setLevel(config.level);
    // 1. Parse & validate network using Builder pattern
    // auto network = ParseRailways::parseNetwork(config.networkFile);
    // if (!network)
    //  return std::unexpected(network.error());
    // 2. Parse & validate trains
    auto trains = parseTrains(config.trainsFile);
    if (!trains)
        return std::unexpected(trains.error());
    // 3. Assemble the simulation object
    RailwaySimulation sim(std::move(config));
    // sim._network = std::move(*network);
    // sim._trains  = std::move(*trains);
    // 4. Register default observers (result file writers)
    // if (sim.m_config.writeResults) {
    //     for (const auto& train : sim.m_trains) {
    //         auto filename = std::format("{}_{}.result", train.name(), train.departureTimeStr());
    //         sim.addObserver(std::make_unique<FileResultLogger>(filename));
    //     }
    // }
    return std::move(sim);
}

/*Getters and Setters*/

/*Constructors*/
RailwaySimulation::RailwaySimulation(SimulationConfig cnf)
{
   std::cout << "RailwaySimulation parameterized constructor is called" << std::endl;
}

/*Destructors*/
RailwaySimulation::~RailwaySimulation( void )
{
    std::cout << "RailwaySimulation destructor is called" << std::endl;
}

/*Overload operators*/


// std::ostream& operator<<(std::ostream& output_stream, RailwaySimulation& src)
// {
// 	output_stream << "* RailwaySimulation Class info*" << std::endl;
// 	return output_stream;
// }

