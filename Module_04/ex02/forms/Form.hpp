#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <ctime>

# include "../FormType.hpp"
# include "../Debug.hpp"

class Headmaster;

class Form
{
protected:
   FormType 	_formType;
   time_t		_creationDate;
   time_t		_expirationDate;
   bool			_signStatus;
   bool			_execStatus;

public:
	/*Member functions*/
	virtual void	execute(Headmaster *hm) = 0;
	virtual bool	isComplete() = 0;
	void			beSigned();
	
	/*Getters and Setters*/
	FormType	getType();
	bool		getSignStatus();
	bool		getExecStatus();

	time_t		getCreationDate();
	time_t		getExpirationDate();
	/*Constructors*/
	Form(FormType p_formType, time_t expirationDate);
	
	/*Destructors*/
    virtual ~Form( void );

	// /*Overload operators*/
};

// std::ostream& operator<<(std::ostream &output_stream, Form& src);

#endif // FORM_HPP
