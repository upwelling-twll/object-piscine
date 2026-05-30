#include <iostream>
#include "Tool.hpp"
#include "Shover.hpp"
#include "Worker.hpp"

void testToolTransfer()
{
    Tool* tool = new Shover("Shovel");

    std::cout << "=== Tool Transfer Test ===" << std::endl;
    Worker worker1("Alice");
    Worker worker2("Bob");

    try {

        worker1.takeTool(tool);
        worker1.useTool(tool);
        worker2.takeTool(tool);
        worker2.useTool(tool);
    
        worker1.discardTool(tool);
        worker2.takeTool(tool);
        worker2.useTool(tool);
    }
    catch (const char* msg) {
        std::cerr << RED <<"Error: " << msg << RESET << std::endl;
    }
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
