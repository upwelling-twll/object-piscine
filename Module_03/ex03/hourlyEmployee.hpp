#ifndef HOURLYEMPLOYEE_HPP
#define HOURLYEMPLOYEE_HPP

#include "Employee.hpp"

class HourlyEmployee : public Employee
{
	protected:
		int workedHours;

	public:
		HourlyEmployee(int value) 
			: Employee(value), workedHours(0) {}

		void  addWorkhours(int hours)
		{
			this->workedHours += hours;
		}
	
};


#endif