#ifndef TOOL_HPP
# define TOOL_HPP

# include <iostream>
# include "Colors.hpp"

class Worker;

class Tool
{
private:
	void		setMemberOfUse(Worker* memberOfUse);

protected:
	std::string _name;
	std::string _type;
    Worker* 	_memberOfUse;
	int 		_numberOfUses;

public:
	/*Member functions*/
    virtual void use() = 0;
	
	/*Getters and Setters*/
	Worker* 			getMemberOfUse() const;
	int					getNumberOfUses() const;
	const std::string& 	getName() const;
	const std::string& 	getType() const;
	
	/*Constructors*/
    Tool(const std::string& _name, const std::string& _type);
	Tool(void);

	/*Destructors*/
    virtual ~Tool( void );

	/*Overload operators*/

	friend class Worker;
};

std::ostream& operator<<(std::ostream &output_stream, Tool& src);

#endif // TOOL_HPP
