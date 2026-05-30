#ifndef WORKER_HPP
# define WORKER_HPP

# include <iostream>
# include <vector>
# include "Colors.hpp"
# include "Statistic.hpp"
# include "Position.hpp"

class Tool;

class Worker
{
private:
    const std::string	_name;
	Position			_pos;
	Statistic			_stats;
	std::vector<Tool*>	_tools;

	void discardTool();

public:
	/*Member functions*/
    void useTool(Tool* tool);

	/*Getters and Setters*/
	std::string getName() const;
	/*Constructors*/
    Worker(std::string _name);

	/*Destructors*/
    ~Worker( void );

	/*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, Worker& src);

#endif // WORKER_HPP
