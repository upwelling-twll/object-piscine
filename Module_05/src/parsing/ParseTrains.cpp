#include "ParseTrains.hpp"
#include "Debug.hpp"
#include <cctype>

struct Train {
    int id = 0;
    std::string name;
    std::string from;
    std::string to;
    double      weight;
    double      maxSpeed;
    double      acceleration; // measured in m/s2
    double      deceleration; // measured in m/s2
};


bool isTrainTag(const std::string& tag)
{
    // Must start with "Train" and have at least one non-space character after it.
    constexpr std::string_view prefix = "Train";
    if (tag.size() <= prefix.size())
        return false;
    if (tag.rfind(std::string(prefix), 0) != 0)
        return false;
    // Ensure the remainder (the train name) contains no whitespace and is non-empty
    for (size_t i = prefix.size(); i < tag.size(); ++i)
    {
        if (std::isspace(static_cast<unsigned char>(tag[i])))
            return false;
    }
    return true;
}

std::expected<Train, std::string> parseOneTrain(std::string_view line)
{
    std::istringstream iss{std::string(line)};
    std::string tag;
    Train train;

    if (!(iss >> tag >> train.name >> train.from >> train.to >> train.weight >> train.maxSpeed >> train.acceleration >> train.deceleration) || !isTrainTag(tag))
    {
        return std::unexpected("Invalid train definition");
    }
    return train;
}

static bool isValidFile(const std::string& filename)
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
void parseTrains(const std::string& filename)
{
    LOG_DBUG("Parse Trains list");
    std::vector<Train> _trains;

    if (!isValidFile(filename))
        return;

    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        if (line.starts_with("Train"))
        {
            auto trainOrError = parseOneTrain(line);
            if (!trainOrError)
            {
                std::cerr << trainOrError.error() << "\n";
                continue;
            }
            Train train = *trainOrError;
            train.id = static_cast<int>(_trains.size()) + 1;
            _trains.push_back(std::move(train));
        }
        else
        {
            std::cerr << "Unknown line type: " << line << "\n";
        }
    }

    LOG_DBUG("Parsed " << _trains.size() << " trains.");
}