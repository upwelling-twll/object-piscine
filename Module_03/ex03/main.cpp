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
}