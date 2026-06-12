#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

class Employee
{
    protected:
        int hourlyValue;

    public:

        Employee(int value) : hourlyValue(value) {}
        virtual ~Employee() {}
        
        virtual void executeWorkday() = 0;
        virtual int calculatePay() const = 0;
};

#endif