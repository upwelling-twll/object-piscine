#include "ParseRailways.hpp"
#include "Debug.hpp"
struct Rail {
    std::string from;
    std::string to;
    double      length;
    double      speed;
};

struct City {
    int         id = 0;
    std::string name;
};

std::expected<Rail, std::string> parseRail(std::string_view line)
{
    std::istringstream iss{std::string(line)};
    std::string tag;
    Rail rail;

    if (!(iss >> tag >> rail.from >> rail.to >> rail.length >> rail.speed) || tag != "Rail")
    {
        return std::unexpected("Invalid rail definition");
    }
    return rail;
}

std::expected<City, std::string> parseNode(std::string_view line)
{
    std::istringstream iss{std::string(line)};
    std::string tag;
    City city;

    if (!(iss >> tag >> city.name) || tag != "Node")
    {
        return std::unexpected("Invalid city definition");
    }
    return city;
}

bool isValidFile(const std::string& filename)
{
    if (filename.empty())
        return false;

    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return false;
    }
    return true;
}

void parseRailwayNetwork(const std::string& filename)
{
    LOG_DBUG("Parse Railway Network");
    std::vector<Rail> _rails;
    std::vector<City> _cities;

    if (!isValidFile(filename))
        return;

    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        if (line.starts_with("Node "))
        {
            auto cityOrError = parseNode(line);
            if (!cityOrError)
            {
                std::cerr << cityOrError.error() << "\n";
                continue;
            }
            City city = *cityOrError;
            city.id = static_cast<int>(_cities.size()) + 1;
            _cities.push_back(std::move(city));
        }
        else if (line.starts_with("Rail "))
        {
            auto railOrError = parseRail(line);
            if (!railOrError)
            {
                std::cerr << railOrError.error() << "\n";
                continue;
            }
            _rails.push_back(*railOrError);
        }
        else
        {
            std::cerr << "Unknown line type: " << line << "\n";
        }
    }

    LOG_DBUG("Parsed " << _cities.size() << " cities and " << _rails.size() << " rails.");
}