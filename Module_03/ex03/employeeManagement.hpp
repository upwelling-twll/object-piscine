#ifndef EMPLOYEEMANAGEMENT_HPP
#define  EMPLOYEEMANAGEMENT_HPP

#include <set>
#include <iostream>

class Employee;

class EmployeeManger
{
private:
    std::set<Employee *> _employees;

public:
    void addEmployee(Employee* employee);
    void removeEmployee(Employee* employee);
    void executeWorkday();
    void calculatePayroll();
};

#endif