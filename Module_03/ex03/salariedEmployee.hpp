#ifndef SALARIEDEMPLOYEE_HPP
#define SALARIEDEMPLOYEE_HPP

#include "Employee.hpp"

class SalariedEmployee : public Employee
{
	protected:
		int absenceHours;

	public: 
		SalariedEmployee(int value) 
			: Employee(value), absenceHours (0) {}
		
		void addAbscence(int hours)
		{
			absenceHours += hours;
		}

};


#endif