#ifndef SCHOOL_HPP
# define SCHOOL_HPP

# include <iostream>

class School
{
private:
    Headmaster*			_hm;
	const std::string	_schoolName;


public:
	/*Member functions*/
    void runDayRoutine();

	/*Getters and Setters*/

	/*Constructors*/
    School(std::string name);

	/*Destructors*/
    ~School( void );

	/*Overload operators*/
	School &operator=(const School& src);
};

#endif // SCHOOL_HPP
