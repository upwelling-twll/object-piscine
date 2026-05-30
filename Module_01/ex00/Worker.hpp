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

public:
	/*Member functions*/
    void useTool(Tool* tool);
	void takeTool(Tool* tool);
	void discardTool(Tool* tool);

	/*Getters and Setters*/
	const std::string getName() const;

	Position&	getPosition();
	Statistic&	getStats();
	int			getNumberOfTools() const;

	/*Constructors*/
    Worker(std::string _name);

	/*Destructors*/
    ~Worker( void );

	/*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, Worker& src);

#endif // WORKER_HPP
