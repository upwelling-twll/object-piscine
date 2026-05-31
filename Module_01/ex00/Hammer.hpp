#ifndef Hammer_HPP
# define Hammer_HPP

# include <iostream>
# include "Colors.hpp"
# include "Tool.hpp"


class Worker;

class Hammer : public Tool
{

public:
	/*Member functions*/
    void use();

	/*Constructors*/
    Hammer(const std::string& _name, const std::string& _type);
	Hammer(void);

	/*Destructors*/
    virtual ~Hammer( void );

};

#endif 
