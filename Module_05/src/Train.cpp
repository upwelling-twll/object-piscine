#include "Train.hpp"

// Constructors
Train::Train(void) 
    : id(0), name(""), from(""), to(""), weight(0.0), cof(0.0), 
      acceleration(0.0), deceleration(0.0), 
      departureTime(0), stationStopTime(0)
{
}

Train::Train(int id, const std::string& name, const std::string& from, const std::string& to,
             double weight, double cof, double acceleration, double deceleration,
             std::chrono::minutes departureTime, std::chrono::minutes stationStopTime)
    : id(id), name(name), from(from), to(to), weight(weight), cof(cof),
      acceleration(acceleration), deceleration(deceleration),
      departureTime(departureTime), stationStopTime(stationStopTime)
{
}

// Destructor
Train::~Train(void)
{
}

// Getters
int Train::getId() const { return id; }
const std::string& Train::getName() const { return name; }
const std::string& Train::getFrom() const { return from; }
const std::string& Train::getTo() const { return to; }
double Train::getWeight() const { return weight; }
double Train::getCOF() const { return cof; }
double Train::getAcceleration() const { return acceleration; }
double Train::getDeceleration() const { return deceleration; }
std::chrono::minutes Train::getDepartureTime() const { return departureTime; }
std::chrono::minutes Train::getStationStopTime() const { return stationStopTime; }

// Setters
void Train::setId(int id) { this->id = id; }
void Train::setName(const std::string& name) { this->name = name; }
void Train::setFrom(const std::string& from) { this->from = from; }
void Train::setTo(const std::string& to) { this->to = to; }
void Train::setWeight(double weight) { this->weight = weight; }
void Train::setCOF(double cof) { this->cof = cof; }
void Train::setAcceleration(double acceleration) { this->acceleration = acceleration; }
void Train::setDeceleration(double deceleration) { this->deceleration = deceleration; }
void Train::setDepartureTime(std::chrono::minutes time) { this->departureTime = time; }
void Train::setStationStopTime(std::chrono::minutes time) { this->stationStopTime = time; }

// Operator=
Train& Train::operator=(const Train& src)
{
    if (this != &src)
    {
        id = src.id;
        name = src.name;
        from = src.from;
        to = src.to;
        weight = src.weight;
        cof = src.cof;
        acceleration = src.acceleration;
        deceleration = src.deceleration;
        departureTime = src.departureTime;
        stationStopTime = src.stationStopTime;
    }
    return *this;
}

// Operator<<
std::ostream& operator<<(std::ostream &output_stream, const Train& src)
{
    output_stream << "Train: " << src.getName() 
                  << " (ID: " << src.getId() << ")\n"
                  << "  From: " << src.getFrom() << " -> To: " << src.getTo() << "\n"
                  << "  Weight: " << src.getWeight() << " kg\n"
                  << "  Max Speed: " << src.getCOF() << " km/h\n"
                  << "  Acceleration: " << src.getAcceleration() << " m/s²\n"
                  << "  Deceleration: " << src.getDeceleration() << " m/s²\n"
                  << "  Departure: " << src.getDepartureTime().count() << " min\n"
                  << "  Stop Time: " << src.getStationStopTime().count() << " min";
    return output_stream;
}
