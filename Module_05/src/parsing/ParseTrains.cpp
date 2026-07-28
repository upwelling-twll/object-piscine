#include "ParseTrains.hpp"
#include "Logger.hpp"

struct TrainRaw {
    int id = 0;
    std::string name;
    std::string from;
    std::string to;
    double      weight;
    double      maxSpeed;
    double      acceleration; // measured in m/s2
    double      deceleration; // measured in m/s2
    std::chrono::minutes departureTime; //in minutes , time since midnight
    std::chrono::minutes stationStopTime; //in minutes
};

bool isTrainTag(const std::string& tag)
{
    // Must start with "Train" and have at least one non-space character after it.
    constexpr std::string_view prefix = "Train";
    if (tag.size() <= prefix.size())
        return false;
    if (tag.rfind(std::string(prefix), 0) != 0)
        return false;
    // Ensure the remainder (the TrainRawname) contains no whitespace and is non-empty
    for (size_t i = prefix.size(); i < tag.size(); ++i)
    {
        if (std::isspace(static_cast<unsigned char>(tag[i])))
            return false;
    }
    return true;
}

void   saveTrainName(std::string tag, TrainRaw* train)
{
    constexpr std::string_view prefix = "Train";
    train->name = tag.substr(prefix.size(), tag.size() - prefix.size());
}

bool    saveTime(TrainRaw* train, std::string str, std::string fieldName)
{
    std::stringstream ss(str);
    int hours = -1;
    int minutes = -1;
    char symbol_h = 0;
    if (! (ss >> hours >> symbol_h >> minutes))
        return (false);
    if (symbol_h != 'h' && symbol_h != 'H')
        return (false);
    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59)
        return (false);
    if (fieldName == "departure")
        train->departureTime = std::chrono::hours(hours) + std::chrono::minutes(minutes);
    else if (fieldName == "stop")
        train->stationStopTime = std::chrono::hours(hours) + std::chrono::minutes(minutes);
    return (true);
}

std::expected<TrainRaw, std::string> parseOneTrain(std::string_view line)
{
    std::istringstream iss{std::string(line)};
    std::string tag;
    std::string departure;
    std::string stop;
    TrainRaw train;
    iss >> tag;

    if (!isTrainTag(tag))
        return std::unexpected("Invalid train definition. Wrong tag : ");
    saveTrainName(tag, &train);
    if (!(iss >> train.maxSpeed >> train.acceleration >> train.weight >> 
        train.deceleration >> train.from >> train.to >> departure >> stop))
    {
        return std::unexpected("Invalid train definition : ");
    }
    if (!saveTime(&train, departure, "departure"))
        return std::unexpected("Invalid train definition. Departure time: ");
    if (!saveTime(&train, stop, "stop"))
        return std::unexpected("Invalid train definition Stop time: ");
    //TODO : validate all physical characteristics of train (weight; maxSpeed; acceleration; deceleration) 
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

#include "TrainBuilder.hpp"  // Add this include

void parseTrains(const std::string& filename)
{
    LOG_DBUG("Parse Trains list");
    std::vector<Train> _trains;  // Changed from TrainRaw to Train

    if (!isValidFile(filename))
        return;

    std::ifstream file(filename);
    std::string line;
    int trainCount = 0;
    
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        if (line.starts_with("Train"))
        {
            auto trainRawOrError = parseOneTrain(line);
            if (!trainRawOrError)
            {
                std::cerr << trainRawOrError.error() << line << "\n";
                continue;
            }
            
            // Use TrainBuilder to construct and validate
            TrainRaw rawTrain = *trainRawOrError;
            auto trainOrError = TrainBuilder()
                .withId(trainCount + 1)
                .withName(rawTrain.name)
                .withFrom(rawTrain.from)
                .withTo(rawTrain.to)
                .withWeight(rawTrain.weight)
                .withMaxSpeed(rawTrain.maxSpeed)
                .withAcceleration(rawTrain.acceleration)
                .withDeceleration(rawTrain.deceleration)
                .withDepartureTime(rawTrain.departureTime)
                .withStationStopTime(rawTrain.stationStopTime)
                .build();
            
            if (!trainOrError)
            {
                std::cerr << "Train validation failed: " << trainOrError.error() << "\n";
                continue;
            }
            
            _trains.push_back(*trainOrError);
            trainCount++;
        }
        else
        {
            std::cerr << "Unknown line type: " << line << "\n";
        }
    }
    
    auto& log = railways::Logger::get();
    log.info(std::format("Parsed {} trains.", std::to_string(_trains.size())));
    for (const auto& train : _trains)
    {
        log.debug(std::format(
            "Train: {}; from: {}; to: {}; weight: {}; maxSpeed: {}; accel: {}; decel: {}",
            train.getName(),
            train.getFrom(),
            train.getTo(),
            train.getWeight(),
            train.getMaxSpeed(),
            train.getAcceleration(),
            train.getDeceleration()
        ));
    }
}