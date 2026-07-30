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


struct SimulationConfig {
	std::string networkFile;
	std::string	trainsFile;
	railways::LogLevel	level = railways::LogLevel::DEBUG;
};

class RailwaySimulation
{
private:
    RailwayNetwork		_network;
	std::vector<Train>	_trains;
	std::unique_ptr<PathfindingStrategy> _pathFinder;
	
	SimulationConfig	_config;


	explicit RailwaySimulation(SimulationConfig cnf);

public:
	/*Member functions*/
    static std::expected<RailwaySimulation, std::string> create(SimulationConfig config);

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
