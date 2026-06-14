#ifndef SPECIALOFFICE_HPP
# define SPECIALOFFICE_HPP

# include <iostream>
# include <vector>

# include "Room.hpp"

class Form;

class SpecialOffice : public Room
{
private:
   	std::vector<Form*> _archivedForms;

public:
	/*Member functions*/
	/*Getters and Setters*/

	/*Constructors*/
    // SpecialOffice(/*Parameterized Constructor*/);
	// SpecialOffice(void);

	// /*Destructors*/
    // ~SpecialOffice( void );

	// /*Overload operators*/
	// SpecialOffice &operator=(const SpecialOffice& src);
};

// std::ostream& operator<<(std::ostream &output_stream, SpecialOffice& src);

#endif // SPECIALOFFICE_HPP
