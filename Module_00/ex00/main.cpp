#include <iostream>
#include "Bank.hpp"

int main()
{
    Bank bank(100000); // Initialize the bank with a liquidity of 100,000

    int id1 = bank.addAccount("Alice", "123 Main St");
    int id2 = bank.addAccount("Bob", "456 Elm St");

    std::cout << "New accounts created:" << id1 << ", " << id2 << std::endl;

    std::cout << "\nTest deposits" << std::endl;
    try
    {
        bank.makeDeposit(id1, 5000);
    }
    catch (const AccountException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    try
    {
        bank.makeDeposit(id2, -3000);
    }
    catch (const AccountException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // std::cout << "Bank Liquidity: " << bank.getLiquidity() << std::endl;
    std::cout << "\nTest Withdrawls and Loans" << std::endl;
    try
    {
        bank.makeWithdrawal(id1, 2000);
    }
    catch (const AccountException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    try
    {
        bank.processLoan(id2, 1016872000);
    }
    catch (const AccountException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    try
    {
         bank.makeDeposit(id1, 3000);
        std::cout << "Account 1 value: " << bank[1].getValue() << std::endl;
    }
    catch (const AccountException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // std::cout << "Bank Liquidity after transactions: " << bank.getLiquidity() << std::endl;

    return 0;
}