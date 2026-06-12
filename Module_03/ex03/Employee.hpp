#ifndef EMPLOYEE
#define EMPLOYEE

class Employee
{
    protected:
        int hourlyValue;

    public:

        Employee(int value) : hourlyValue(value) {}
        virtual ~Employee() {}
        
        virtual void executeWorkday() = 0;
        virtual int calulatePay() const = 0;
};

#endif