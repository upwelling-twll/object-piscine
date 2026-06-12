#ifndef TEMPWORKER_HPP
#define TEMPWORKER_HPP

#include "hourlyEmployee.hpp"

class TempWorker : public HourlyEmployee
{
	public:

		TempWorker(int value) : HourlyEmployee(value) {}

		void executeWorkday()
		{
			workedHours += 7;
		}

		int calculatePay() const
		{
			return (workedHours * hourlyValue);
		}

};

#endif