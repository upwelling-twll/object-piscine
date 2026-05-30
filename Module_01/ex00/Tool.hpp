#ifndef TOOL_HPP
# define TOOL_HPP

# include <iostream>
# include "Colors.hpp"

class Worker;

class Tool
{
protected:
	std::string _name;
    Worker* 	_owner;

	void		setOwner(Worker* owner);
public:
	/*Member functions*/
    virtual void use() = 0;

	/*Getters and Setters*/
	Worker* 			getOwner() const;
	const std::string& 	getName() const;

	/*Constructors*/
    Tool(std::string& _name);
	Tool(void);

	/*Destructors*/
    virtual ~Tool( void );

	/*Overload operators*/

	friend class Worker;
};

std::ostream& operator<<(std::ostream &output_stream, Tool& src);

#endif // TOOL_HPP
