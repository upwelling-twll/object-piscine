#ifndef SecretarialOffice_HPP
# define SecretarialOffice_HPP

# include <iostream>
# include <vector>

# include "Room.hpp"

// class Form;

class SecretarialOffice : public Room
{
private:
   	// std::vector<Form*> _archivedForms;

public:
	/*Member functions*/
	/*Getters and Setters*/

	/*Constructors*/
    SecretarialOffice(int ID);

	/*Destructors*/
    ~SecretarialOffice( void );

	/*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, SecretarialOffice& src);

#endif // SecretarialOffice_HPP
