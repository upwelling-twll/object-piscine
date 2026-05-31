#ifndef Shovel_HPP
# define Shovel_HPP

# include <iostream>
# include "Colors.hpp"
# include "Tool.hpp"


class Worker;

class Shovel : public Tool
{

public:
	/*Member functions*/
    void use();

	/*Constructors*/
    Shovel(const std::string& _name, const std::string& _type);
	Shovel(void);

	/*Destructors*/
    virtual ~Shovel( void );

};

#endif 
