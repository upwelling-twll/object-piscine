#ifndef TRAINBUILDER_HPP
# define TRAINBUILDER_HPP

# include <string>
# include <chrono>
# include <expected>
# include "Train.hpp"

class TrainBuilder
{
private:
    int                     _id;
    std::string             _name;
    std::string             _from;
    std::string             _to;
    double                  _weight;
    double                  _cof;
    double                  _acceleration;
    double                  _deceleration;
    std::chrono::minutes    _departureTime;
    std::chrono::minutes    _stationStopTime;

public:
    TrainBuilder();
    
    // Builder methods (return *this for chaining)
    TrainBuilder& withId(int id);
    TrainBuilder& withName(const std::string& name);
    TrainBuilder& withFrom(const std::string& from);
    TrainBuilder& withTo(const std::string& to);
    TrainBuilder& withWeight(double weight);
    TrainBuilder& withCOF(double cof);
    TrainBuilder& withAcceleration(double acceleration);
    TrainBuilder& withDeceleration(double deceleration);
    TrainBuilder& withDepartureTime(std::chrono::minutes time);
    TrainBuilder& withStationStopTime(std::chrono::minutes time);
    
    // Validation methods
    static std::expected<void, std::string> validateWeight(double weight);
    static std::expected<void, std::string> validateCOF(double cof);
    static std::expected<void, std::string> validateAcceleration(double acceleration);
    static std::expected<void, std::string> validateDeceleration(double deceleration);
    static std::expected<void, std::string> validateName(const std::string& name);
    static std::expected<void, std::string> validateStation(const std::string& station);
    
    // Build and validate
    std::expected<Train, std::string> build();
};

#endif // TRAINBUILDER_HPP
