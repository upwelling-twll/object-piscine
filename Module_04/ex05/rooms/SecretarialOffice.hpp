#ifndef SecretarialOffice_HPP
# define SecretarialOffice_HPP

# include <iostream>
# include <vector>
# include <memory>

# include "Room.hpp"

class Form;

class SecretarialOffice : public Room
{
private:
	std::vector<std::unique_ptr<Form>> _archivedForms;

public:
	/*Member functions*/
	void addToArchive(std::unique_ptr<Form> p_form);

	/*Getters and Setters*/
	int getArchivedForms();

	/*Constructors*/
    SecretarialOffice();

	/*Destructors*/
    ~SecretarialOffice( void );

	/*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, SecretarialOffice& src);

#endif // SecretarialOffice_HPP
