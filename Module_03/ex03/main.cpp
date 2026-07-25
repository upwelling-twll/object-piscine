#include "EmployeeManager.hpp"
#include "TempWorker.hpp"
#include "ContractEmployee.hpp"
#include "Apprentice.hpp"

int main()
{
    EmployeeManager manager;

    TempWorker temp(10);
    ContractEmployee contract(20);
    Apprentice apprentice(15);

    manager.addEmployee(&temp);
    manager.addEmployee(&contract);
    manager.addEmployee(&apprentice);

    for (int i = 0; i < 10; i++)
        manager.executeWorkday();

    apprentice.addSchoolHours(14);
    contract.addAbsence(7);

    manager.calculatePayroll();


    std::cout << "\n=== Test one month of work ====" << std::endl;
    TempWorker temp2(300);
    ContractEmployee contract2(300);
    Apprentice apprentice2(100);

    EmployeeManager manager2;


    manager2.addEmployee(&temp2);
    manager2.addEmployee(&contract2);
    manager2.addEmployee(&apprentice2);

    //apprentice is visiting 42 scool 80 hours per month
    apprentice2.addSchoolHours(80);
    //contractEmployee had 15 days of unpaied leave
    contract2.addAbsence(105);
    //temp employee works 15 days per month
    for (int i = 0; i < 15; i++)
        temp2.executeWorkday();

    manager2.calculatePayroll();



}