#include <iostream>
#include "Tool.hpp"
#include "Worker.hpp"

void testToolTransfer()
{
    std::cout << "=== Tool Transfer Test ===" << std::endl;
    Worker worker1("Alice");
    Worker worker2("Bob");
}

int main()
{
    // testComposition();
    // testAggregation();
    // testInheritance();
    // testWorkshopAssociation();
    testToolTransfer();
    // testAutoRelease();
    // testInvalidOperations();
    return 0;
}
