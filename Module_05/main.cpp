#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <expected>
#include "inc/Debug.hpp"

struct rail{
    std::string from;
    std::string to;
    double      length;
    double      maxSpeed;
};

std::expected<Rail, std::string> parseRail(std::istringstream& iss)
{
    Rail rail;

    if (!(iss >> rail.from >> rail.to >> rail.length >> rail.speed) || (iss >> extra))
    {
        return std::unexpected("Invalid rail definition: " + iss);
    }
    return rail;
}

bool isValidFile(std::string filename)
{
    if (filename.empty())
        return (1);
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }

}

void parseRailwayNetwork(std::string filename)
{
    if (!isValidFile(filename))
        return (0);
    std::stringstream iss;
    iss << file.rdbuf();
    auto rail = parseRail(iss);
    if (!rail)
    {
        std::cerr << rail.error() << "\n";
        return;
    }
}

int main()
{
    if (argc != 2)
        return (1);
        // ERROR();
    parseRailwayNetwork(argv[1]);
    return (0);
}