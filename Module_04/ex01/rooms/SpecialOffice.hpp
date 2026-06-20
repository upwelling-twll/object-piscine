#ifndef SECRETARIALOFFICE_HPP
# define SECRETARIALOFFICE_HPP

# include <iostream>
# include <vector>

# include "Room.hpp"

class Form;

class SecretarialOffice : public Room
{
private:
   	std::vector<Form*> _archivedForms;

public:
	/*Member functions*/
	/*Getters and Setters*/

	/*Constructors*/
    // SecretarialOffice(/*Parameterized Constructor*/);
	// SecretarialOffice(void);

	// /*Destructors*/
    // ~SecretarialOffice( void );

	// /*Overload operators*/
	// SecretarialOffice &operator=(const SecretarialOffice& src);
};

// std::ostream& operator<<(std::ostream &output_stream, SecretarialOffice& src);

#endif // SecretarialOffice_HPP
