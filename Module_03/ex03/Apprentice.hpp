#ifndef APPRENTICE_HPP
#define APPRENTICE_HPP

#include "salariedEmployee.hpp"

class Apprentice : public SalariedEmployee
{
	private:
		int schoolHours;

	public:
		Apprentice(int value)
			: SalariedEmployee(value), schoolHours(0) {}
		
		void addSchoolHours(int hours)
		{
			schoolHours += hours;
		}

		void executeWorkday()
		{
			//nothing happens	
		}

		int calculatePay() const
		{
			int monthlyHours = 30 * 7;
			int normalHours = monthlyHours - absenceHours - schoolHours;
			int schoolPay = schoolHours * (hourlyValue / 2);

			return (normalHours * hourlyValue + schoolPay);
		}

};

#endif