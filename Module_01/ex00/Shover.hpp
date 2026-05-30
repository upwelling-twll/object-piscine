#ifndef SHOVER_HPP
# define SHOVER_HPP

# include <iostream>
# include "Colors.hpp"
# include "Tool.hpp"


class Worker;

class Shover : public Tool
{

public:
	/*Member functions*/
    void use();

	/*Constructors*/
    Shover(const std::string& _name);
	Shover(void);

	/*Destructors*/
    virtual ~Shover( void );

};

#endif 
