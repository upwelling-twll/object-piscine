#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

# include <iostream>
# include <vector>
# include "Colors.hpp"

class Worker;

class Workshop
{
private:
	const std::string 		_name;
    std::vector<Worker*>	_workers;
	std::string				_requiredToolType;

public:
	/*Member functions*/
    void registerWorker(Worker* worker);
	void releaseWorker(Worker* worker);
	void displayWorkers() const;
	void executeWorkDay();

	/*Getters and Setters*/
	const std::string& getName() const;
	const std::string& getRequiredToolType() const;

	/*Constructors*/
    Workshop(std::string name, std::string requiredToolType);
	Workshop(void);

	/*Destructors*/
    ~Workshop( void );

};

#endif
