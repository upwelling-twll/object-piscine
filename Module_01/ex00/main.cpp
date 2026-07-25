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
    Shovel Shovel("Metal shovel", "Shovel");

    worker.takeTool(&Shovel);
    worker.useTool(&Shovel);
}

void testAggregation()
{
    try {
        std::cout << "=== Aggregation Test ===" << std::endl;
        Worker* worker = new Worker("Bob");
        Shovel* shovel = new Shovel("Metal shovel", "Shovel");

        worker->takeTool(shovel);
        worker->useTool(shovel);
        delete shovel; 
        std::cout << YELLOW << *worker << RESET << std::endl;

        Shovel* NEWShovel = new Shovel("Wooden shovel","Shovel");
        worker->takeTool(NEWShovel);
        worker->useTool(NEWShovel); 
        std::cout << WHITE << *NEWShovel << RESET << std::endl; 
        // // delete worker;  
        std::cout << WHITE << *NEWShovel << RESET << std::endl;
        delete NEWShovel; 
        NEWShovel = NULL;
        std::cout << YELLOW << *worker << RESET << std::endl; 
        // worker->takeTool(NEWShovel);
        Shovel* Shovel1 = new Shovel("Shovel1", "Shovel");
        Hammer* Hammer1 = new Hammer("Hammer1", "Hammer");
        Shovel* Shovel2 = new Shovel("Shovel2", "Shovel");
        std::cout << "Taking multiple tools..." << std::endl;
        worker->takeTool(Shovel1);
        worker->takeTool(Hammer1);
        worker->takeTool(Shovel2);
        std::cout << YELLOW << *worker << RESET << std::endl;
        std::cout << YELLOW << *worker << RESET << std::endl;
        
        worker->useTool(Shovel1);
        worker->useTool(Hammer1);
        worker->useTool(Shovel2);
        std::cout << WHITE << *Shovel1 << RESET << std::endl;
        // std::cout << PINK << *Hammer1 << RESET << std::endl;
        std::cout << WHITE << *Shovel2 << RESET << std::endl;
        std::cout << YELLOW << *worker << RESET << std::endl;
        delete worker;
        delete Hammer1;
        delete Shovel1;
        delete Shovel2;
    }
    catch (const std::exception& e) {
        std::cerr << RED <<"Error: " << e.what() << RESET << std::endl;
    }
}

void testToolTransfer()
{
    Tool* tool = new Shovel("Metal shovel", "Shovel");

    std::cout << "=== Tool Transfer Test ===" << std::endl;
    Worker worker1("Alice");
    Worker worker2("Bob");

    try {

        worker1.takeTool(tool);
        std::cout << YELLOW << worker1 << RESET << std::endl;
        std::cout << WHITE << *tool << RESET << std::endl;

        worker1.useTool(tool);
        // worker2.useTool(tool);


        worker2.takeTool(tool);
        worker2.useTool(tool);
        std::cout << YELLOW << worker1 << RESET << std::endl;
        std::cout << WHITE << *tool << RESET << std::endl;
        std::cout << YELLOW << worker2 << RESET << std::endl;
        
        worker2.takeTool(tool);
        worker2.discardTool(tool);
        // worker1.discardTool(tool);
        std::cout << WHITE << *tool << RESET << std::endl;
        
        worker2.useTool(tool);
    }
    catch (const std::exception& e) {
        std::cerr << RED <<"Error: " << e.what() << RESET << std::endl;
    }
    delete tool;
}

void testWorkshopAssociation()
{
    std::cout << "=== Workshop Association Test ===" << std::endl;
    Worker worker1("uruk-hai");
    Worker worker2("orc");
    Worker worker3("gollum");
    Workshop workshop("Nan Curunír (Saruman's Workshop in Isengard)", "Shovel");
    Workshop workshop2("Gorgoroth (Sauron's Workshop in Mordor)", "Hammer");
    Workshop workshop3("Saruman's Workshop in Bag End", "Shovel");
    
    Shovel shovel1("stolen shovel", "Shovel");
    Shovel shovel2("another stolen shovel", "Shovel");
    Shovel shovel3("old shovel", "Shovel");
    Hammer hammer1("stolen hammer", "Hammer");
    Hammer hammer2("another stolen hammer", "Hammer");
    Hammer hammer3("old hammer", "Hammer");
    try {

        worker1.takeTool(&shovel1);
        worker2.takeTool(&shovel2);
        worker3.takeTool(&shovel3);

        worker1.takeTool(&hammer1);
        worker2.takeTool(&hammer2);
        worker1.takeTool(&hammer3);

        workshop.registerWorker(&worker1);
        workshop.registerWorker(&worker2);
        workshop.displayWorkers();
        std::cout << std::endl;
        std::cout << YELLOW << worker1 << RESET << std::endl;
        std::cout << YELLOW << worker2 << RESET << std::endl;

        workshop2.registerWorker(&worker2);
        workshop3.registerWorker(&worker2);
        std::cout << YELLOW << worker2 << RESET << std::endl;
        workshop.displayWorkers();
        workshop2.displayWorkers();
        workshop3.displayWorkers();

        std::cout << "\n== Test workday ==" << std::endl;
        workshop.executeWorkDay();
        // workshop.releaseWorker(&worker3);
        worker3.work(&workshop);
        worker2.discardTool(&hammer2);
        workshop.releaseWorker(&worker1);
        workshop.displayWorkers();
        // std::cout << std::endl;
        // std::cout << YELLOW << worker1 << RESET << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << RED <<"Error: " << e.what() << RESET << std::endl;
    }
}

void testToolType()
{
    Hammer hammer("newHammer", "Hammer");
    Shovel shovel1("oldShovel", "Shovel");
    Shovel shovel2("newShovel", "Shovel");

    Worker worker("Alice");

    worker.takeTool(&hammer);
    worker.takeTool(&shovel1);
    worker.takeTool(&shovel2);

    std::cout << "Found shovel: " << (worker.getTool<Shovel>())->getName() << std::endl;
    if (worker.getTool<Hammer>() == NULL)
    {
        std::cout << "No hammer found." << std::endl;
    }
    else
    {
        std::cout << BLUE << "Found hammer: " << (worker.getTool<Hammer>())->getName() << RESET << std::endl;
    }
}

void testWorshopToolRequirement()
{
    std::cout << "=== Workshop Tool Requirement Test ===" << std::endl;
    Worker worker("Orc");
    Workshop workshop("Isengard", "Hammer");
    Workshop workshop2("Mordor", "Hammer");
    Workshop workshop3("Beg End", "Shovel");



    try {
        workshop.registerWorker(&worker);
    }
    catch (const std::exception& e) {
        std::cerr << RED <<"Error: " << e.what() << RESET << std::endl;
    }

    Hammer hammer("Ugly Hammer", "Hammer");
    Shovel shovel("Stinky Shovel", "Shovel");

    worker.takeTool(&hammer);
    worker.takeTool(&shovel);

    try {
        workshop.registerWorker(&worker);
        workshop2.registerWorker(&worker);
        workshop3.registerWorker(&worker);

        workshop.displayWorkers();
        workshop2.displayWorkers();
        workshop3.displayWorkers();

    }
    catch (const std::exception& e) {
        std::cerr << RED <<"Error: " << e.what() << RESET << std::endl;
    }

    std::cout << "===Test worker loosing requested tool===" << std::endl;
    worker.discardTool(&hammer);
    workshop.displayWorkers();

}

int main()
{
    testToolTransfer();
    testComposition();
    testAggregation();
    testWorkshopAssociation();
    testToolType();
    testWorshopToolRequirement();
   
    return 0;
}
