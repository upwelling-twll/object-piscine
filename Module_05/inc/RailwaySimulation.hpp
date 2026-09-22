#ifndef RAILWAYSIMULATION_HPP
# define RAILWAYSIMULATION_HPP
# include <expected>
# include <memory>
# include <vector>
# include <iostream>
# include "Logger.hpp"
# include "Train.hpp"
# include "RailwayNetwork.hpp"
# include "PathFindingStrategy.hpp"

class IEdgeCostCalculator;
class RoutePlanner;

enum class STRATEGY
{
    DIJKSTRA_DISTANCE,
    A_STAR_TIME,
    ALL_STRATEGIES
};


struct SimulationConfig {
	std::string		networkFile;
	std::string		trainsFile;
	STRATEGY		strategy = STRATEGY::DIJKSTRA_DISTANCE;
	railways::LogLevel	level = railways::LogLevel::DEBUG;
};

class RailwaySimulation
{
private:
    RailwayNetwork							_network;
	std::vector<Train>						_trains;
	std::unique_ptr<PathfindingStrategy>	_pathFinder;
	
	SimulationConfig						_config;
	std::unique_ptr<IEdgeCostCalculator>	_calculator;
	RoutePlanner							_planner;

	explicit RailwaySimulation(SimulationConfig cnf);

public:
	/*Member functions*/
    static std::expected<RailwaySimulation, std::string> create(SimulationConfig config);
	void	runSimulation();
	
	/*Getters and Setters*/

	 /*Constructors - Deleted copy, move allowed*/
	RailwaySimulation(const RailwaySimulation&) = delete;
	RailwaySimulation& operator=(const RailwaySimulation&) = delete;
	RailwaySimulation(RailwaySimulation&&) = default;
	RailwaySimulation& operator=(RailwaySimulation&&) = default;

	/*Destructors*/
    ~RailwaySimulation( void );

	/*Overload operators*/
};

// std::ostream& operator<<(std::ostream &output_stream, RailwaySimulation& src);

#endif // RAILWAYSIMULATION_HPP
