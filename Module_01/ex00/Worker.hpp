#ifndef WORKER_HPP
# define WORKER_HPP

# include <iostream>
# include <vector>
# include "Colors.hpp"
# include "Statistic.hpp"
# include "Position.hpp"

class Tool;
class Workshop;
class Worker
{
private:
    const std::string	_name;
	Position			_pos;
	Statistic			_stats;
	std::vector<Tool*>	_tools;
	std::vector<Workshop*> _workshops;

public:
	/*Member functions*/
    void useTool(Tool* tool);
	void takeTool(Tool* tool);
	void discardTool(Tool* tool);
	void registerInWorkshop(Workshop* workshop);
	void leaveWorkshop(Workshop* workshop);
	Tool* getTool(const std::string& toolType);
	void work(Workshop* workshop);
	
	template<typename ToolType>
	ToolType* getTool()
	{
		for (std::vector<Tool*>::iterator it = this->_tools.begin(); it != this->_tools.end(); ++it)
		{
			ToolType* castedTool = dynamic_cast<ToolType*>(*it);
			if (castedTool)
			{
				return castedTool;
			}
		}
		return NULL;
	};

	/*Getters and Setters*/
	const std::string getName() const;

	Position&	getPosition();
	Statistic&	getStats();
	int			getNumberOfTools() const;
	int			getNumberOfWorkshops() const;
	
	/*Constructors*/
    Worker(std::string _name);

	/*Destructors*/
    ~Worker( void );

	/*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, Worker& src);

#endif // WORKER_HPP
