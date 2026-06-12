#ifndef EMPLOYEEMANAGER_HPP
#define  EMPLOYEEMANAGER_HPP

#include <vector>
#include <iostream>

#include "Employee.hpp"

class EmployeeManager
{
private:
    std::vector<Employee *> _employees;

public:

    void addEmployee(Employee* employee)
    {
        _employees.push_back(employee);
    }

    void removeEmployee(Employee* employee)
    {
        for (auto it = _employees.begin(); it != _employees.end(); ++it)
        {
            if (*it == employee)
            {
                _employees.erase(it);
                return;
            }
        }
    }

    void executeWorkday()
    {
        for (Employee* e : _employees)
            e->executeWorkday();
    }

    void calculatePayroll()
    {
        for (Employee* e : _employees)
            std::cout << e->calculatePay() << std::endl;
    }
};

#endif