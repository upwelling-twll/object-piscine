#ifndef EMPLOYEEMANAGEMENT_HPP
#define  EMPLOYEEMANAGEMENT_HPP

#include <vector>
#include <iostream>

class Employee;

class EmployeeManger
{
private:
    std::vector<Employee *> _employees;

public:
    void addEmployee(Employee* employee);
    void removeEmployee(Employee* employee);
    void executeWorkday();
    void calculatePayroll();
};

#endif