#include "ParseRailways.hpp"
#include "ParseTrains.hpp"

#include "Debug.hpp"

int main(int argc, char** argv)
{
    if (argc != 3)
        return (1);
        // ERROR();
    std::cout << "hello from Timer Ul " << std::endl;
    parseRailwayNetwork(argv[1]);
    parseTrains(argv[2]);
    return (0);
}