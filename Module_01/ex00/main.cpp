#include <iostream>
#include "Tool.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Worker.hpp"
#include "Workshop.hpp"

void testComposition()
{
    std::cout << "=== Composition Test ===" << std::endl;
    Worker worker("Alice");
    Shovel Shovel("Shovel");

    worker.takeTool(&Shovel);
    worker.useTool(&Shovel);
}

void testAggregation()
{
    try {
        std::cout << "=== Aggregation Test ===" << std::endl;
        Worker* worker = new Worker("Bob");
        Shovel* shovel = new Shovel("Shovel");

        worker->takeTool(shovel);
        worker->useTool(shovel);
        delete shovel; 
        std::cout << YELLOW << *worker << RESET << std::endl;

        Shovel* NEWShovel = new Shovel("Shovel");
        worker->takeTool(NEWShovel);
        worker->useTool(NEWShovel); 
        std::cout << WHITE << *NEWShovel << RESET << std::endl; 
        // delete worker;  
        std::cout << WHITE << *NEWShovel << RESET << std::endl;
        delete NEWShovel; 
        NEWShovel = NULL;
        std::cout << YELLOW << *worker << RESET << std::endl; 
        // worker->takeTool(NEWShovel);
        Shovel* Shovel1 = new Shovel("Shovel1");
        Hammer* Hammer1 = new Hammer("Hammer1");
        Shovel* Shovel2 = new Shovel("Shovel2");
        std::cout << "Taking multiple tools..." << std::endl;
        worker->takeTool(Shovel1);
        worker->takeTool(Hammer1);
        worker->takeTool(Shovel2);
        std::cout << YELLOW << *worker << RESET << std::endl;
        worker->useTool(Shovel1);
        worker->useTool(Hammer1);
        worker->useTool(Shovel2);
        std::cout << WHITE << *Shovel1 << RESET << std::endl;
        std::cout << PINK << *Hammer1 << RESET << std::endl;
        std::cout << WHITE << *Shovel2 << RESET << std::endl;
        delete Hammer1;
        std::cout << YELLOW << *worker << RESET << std::endl;
        delete worker;
        delete Shovel1;
        delete Shovel2;
    }
    catch (const char* msg) {
        std::cerr << RED <<"Error: " << msg << RESET << std::endl;
    }
}

void testToolTransfer()
{
    Tool* tool = new Shovel("Shovel");

    std::cout << "=== Tool Transfer Test ===" << std::endl;
    Worker worker1("Alice");
    Worker worker2("Bob");

    try {

        worker1.takeTool(tool);
        std::cout << YELLOW << worker1 << RESET << std::endl;
        std::cout << WHITE << *tool << RESET << std::endl;

        worker1.useTool(tool);

        worker2.takeTool(tool);
        worker2.useTool(tool);
        std::cout << YELLOW << worker1 << RESET << std::endl;
        std::cout << WHITE << *tool << RESET << std::endl;
        std::cout << YELLOW << worker2 << RESET << std::endl;
        
        worker2.takeTool(tool);
        worker2.discardTool(tool);
        worker1.discardTool(tool);
        
        // worker2.useTool(tool);
    }
    catch (const char* msg) {
        std::cerr << RED <<"Error: " << msg << RESET << std::endl;
    }
    delete tool;
}

void testWorkshopAssociation()
{
    std::cout << "=== Workshop Association Test ===" << std::endl;
    Worker worker1("uruk-hai");
    Worker worker2("orc");
    Worker worker3("gollum");
    Workshop workshop("Nan Curunír (Saruman's Workshop in Isengard)");
    Workshop workshop2("Gorgoroth (Sauron's Workshop in Mordor)");
    Workshop workshop3("Saruman's Workshop in Bag End");

    try {
        workshop.registerWorker(&worker1);
        workshop.registerWorker(&worker2);
        workshop.registerWorker(&worker1);
        workshop.displayWorkers();
        std::cout << std::endl;
        std::cout << YELLOW << worker1 << RESET << std::endl;
        std::cout << YELLOW << worker2 << RESET << std::endl;

        workshop2.registerWorker(&worker2);
        workshop3.registerWorker(&worker2);
        std::cout << YELLOW << worker1 << RESET << std::endl;
        workshop2.displayWorkers();
        workshop3.displayWorkers();

        workshop.executeWorkDay();
        workshop.releaseWorker(&worker3);
        // worker3.work();
        workshop.releaseWorker(&worker1);
        workshop.displayWorkers();
        std::cout << std::endl;
        std::cout << YELLOW << worker1 << RESET << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << RED <<"Error: " << e.what() << RESET << std::endl;
    }
}

void testToolType()
{
    // Hammer hammer("Hammer");
    Shovel shovel1("oldShovel");
    Shovel shovel2("newShovel");
    
    Worker worker("Alice");

    // worker.takeTool(&hammer);
    worker.takeTool(&shovel1);
    worker.takeTool(&shovel2);

    std::cout << "Found shovel: " << (worker.getTool<Shovel>())->getName() << std::endl;
    if (worker.getTool<Hammer>() == NULL)
    {
        std::cout << "No hammer found." << std::endl;
    }
    else
    {
        std::cout << "Found hammer: " << (worker.getTool<Hammer>())->getName() << std::endl;
    }

}

int main()
{

    // testComposition();
    // testAggregation();
    // testInheritance();
    // testWorkshopAssociation();
    // testToolTransfer();
    // testAutoRelease();
    // testInvalidOperations();
    testToolType();
    return 0;
}
