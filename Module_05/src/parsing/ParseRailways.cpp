#include <string>
#include <algorithm>

struct rail{
    std::string from;
    std::string to;
    double      length;
    double      maxSpeed;
}

std::expected<Rail, std::string> parseRail(std::istringstream& iss)
{
    Rail rail;

    if (!(iss >> rail.from >> rail.to >> rail.length >> rail.speed) || (iss >> extra))
    {
        return std::unexpected("Invalid rail definition");
    }
    return rail;
}

void parseRailwayNetwork(std::string filename)
{
    int fd = isValidFile(filename);
    if (!fd)
        throw std::invalid_argument("ParseRailwayNetwork() filename is invalid");
    auto rail = parseRail(iss);
    if (!rail)
        std::cerr << rail.error();


}