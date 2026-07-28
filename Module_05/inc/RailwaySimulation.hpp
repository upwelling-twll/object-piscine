#ifndef RAILWAYSIMULATION_HPP
# define RAILWAYSIMULATION_HPP
# include <expected>
# include <vector>
# include <iostream>
# include "Logger.hpp"
# include "Train.hpp"

// class Rails;
class RailwayNetwork;

struct SimulationConfig {
	std::string networkFile;
	std::string	trainsFile;
	railways::LogLevel	level = railways::LogLevel::DEBUG;
};

class RailwaySimulation
{
private:
    // RailwayNetwork		_network;
	// std::vector<Rails>	_network;
	std::vector<Train>	_trains;
	SimulationConfig	_config;

	explicit RailwaySimulation(SimulationConfig cnf);

public:
	/*Member functions*/
    static std::expected<RailwaySimulation, std::string> create(SimulationConfig config);

	/*Getters and Setters*/

	/*Destructors*/
    ~RailwaySimulation( void );

	/*Overload operators*/
};

// std::ostream& operator<<(std::ostream &output_stream, RailwaySimulation& src);

#endif // RAILWAYSIMULATION_HPP
