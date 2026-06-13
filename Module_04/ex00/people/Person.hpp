#ifndef PERSON_HPP
# define PERSON_HPP

# include <iostream>

class Person
{
private:
    std::string _name;
	Room* _currentRoom;

public:
	Personne(std::string p_name);
	Room* room() {return (_currentRoom);}

	/*Getters and Setters*/

	/*Constructors*/
    // Person(/*Parameterized Constructor*/);
	// Person(void);

	// /*Destructors*/
    // ~Person( void );

	// /*Overload operators*/
	// Person &operator=(const Person& src);
};

// std::ostream& operator<<(std::ostream &output_stream, Person& src);

#endif // PERSON_HPP
