#include "TrainBuilder.hpp"

TrainBuilder::TrainBuilder()
    : _id(0), _name(""), _from(""), _to(""), _weight(0.0), _maxSpeed(0.0),
      _acceleration(0.0), _deceleration(0.0),
      _departureTime(0), _stationStopTime(0)
{
}

// Builder methods
TrainBuilder& TrainBuilder::withId(int id)
{
    _id = id;
    return *this;
}

TrainBuilder& TrainBuilder::withName(const std::string& name)
{
    _name = name;
    return *this;
}

TrainBuilder& TrainBuilder::withFrom(const std::string& from)
{
    _from = from;
    return *this;
}

TrainBuilder& TrainBuilder::withTo(const std::string& to)
{
    _to = to;
    return *this;
}

TrainBuilder& TrainBuilder::withWeight(double weight)
{
    _weight = weight;
    return *this;
}

TrainBuilder& TrainBuilder::withMaxSpeed(double maxSpeed)
{
    _maxSpeed = maxSpeed;
    return *this;
}

TrainBuilder& TrainBuilder::withAcceleration(double acceleration)
{
    _acceleration = acceleration;
    return *this;
}

TrainBuilder& TrainBuilder::withDeceleration(double deceleration)
{
    _deceleration = deceleration;
    return *this;
}

TrainBuilder& TrainBuilder::withDepartureTime(std::chrono::minutes time)
{
    _departureTime = time;
    return *this;
}

TrainBuilder& TrainBuilder::withStationStopTime(std::chrono::minutes time)
{
    _stationStopTime = time;
    return *this;
}

// Validation methods
std::expected<void, std::string> TrainBuilder::validateWeight(double weight)
{
    if (weight <= 0.0)
        return std::unexpected("Weight must be positive");
    if (weight > 1000000.0)  // 1M kg max
        return std::unexpected("Weight exceeds maximum (1M kg)");
    return {};
}

std::expected<void, std::string> TrainBuilder::validateMaxSpeed(double maxSpeed)
{
    if (maxSpeed <= 0.0)
        return std::unexpected("Max speed must be positive");
    if (maxSpeed > 500.0)  // 500 km/h max
        return std::unexpected("Max speed exceeds maximum (500 km/h)");
    return {};
}

std::expected<void, std::string> TrainBuilder::validateAcceleration(double acceleration)
{
    if (acceleration <= 0.0)
        return std::unexpected("Acceleration must be positive");
    if (acceleration > 10.0)  // 10 m/s² max
        return std::unexpected("Acceleration exceeds maximum (10 m/s²)");
    return {};
}

std::expected<void, std::string> TrainBuilder::validateDeceleration(double deceleration)
{
    if (deceleration <= 0.0)
        return std::unexpected("Deceleration must be positive");
    if (deceleration > 10.0)  // 10 m/s² max
        return std::unexpected("Deceleration exceeds maximum (10 m/s²)");
    return {};
}

std::expected<void, std::string> TrainBuilder::validateName(const std::string& name)
{
    if (name.empty())
        return std::unexpected("Train name cannot be empty");
    if (name.length() > 100)
        return std::unexpected("Train name exceeds maximum length (100 chars)");
    return {};
}

std::expected<void, std::string> TrainBuilder::validateStation(const std::string& station)
{
    if (station.empty())
        return std::unexpected("Station name cannot be empty");
    if (station.length() > 100)
        return std::unexpected("Station name exceeds maximum length (100 chars)");
    return {};
}

// Build and validate
std::expected<Train, std::string> TrainBuilder::build()
{
    // Validate all fields
    auto nameValidation = validateName(_name);
    if (!nameValidation)
        return std::unexpected(nameValidation.error());
    
    auto fromValidation = validateStation(_from);
    if (!fromValidation)
        return std::unexpected(fromValidation.error());
    
    auto toValidation = validateStation(_to);
    if (!toValidation)
        return std::unexpected(toValidation.error());
    
    auto weightValidation = validateWeight(_weight);
    if (!weightValidation)
        return std::unexpected(weightValidation.error());
    
    auto maxSpeedValidation = validateMaxSpeed(_maxSpeed);
    if (!maxSpeedValidation)
        return std::unexpected(maxSpeedValidation.error());
    
    auto accelValidation = validateAcceleration(_acceleration);
    if (!accelValidation)
        return std::unexpected(accelValidation.error());
    
    auto decelValidation = validateDeceleration(_deceleration);
    if (!decelValidation)
        return std::unexpected(decelValidation.error());
    
    // Build and return Train
    return Train(_id, _name, _from, _to, _weight, _maxSpeed, 
                 _acceleration, _deceleration, _departureTime, _stationStopTime);
}
