#ifndef CONTRACTEMPLOYEE_HPP
#define CONTRACTEMPLOYEE_HPP

#include "salariedEmployee.hpp"

class ContractEmployee : public SalariedEmployee
{
	public:
		ContractEmployee(int value)
			: SalariedEmployee(value) {}
		
		void executeWorkday()
		{
			//nothing happens
		}

		int calculatePay() const
		{
			int monthlyHours = 30 * 7;
			int worked = monthlyHours - absenceHours;

			return (worked * hourlyValue);
		}


};

#endif