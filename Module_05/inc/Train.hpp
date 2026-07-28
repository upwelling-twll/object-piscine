#ifndef TRAIN_HPP
# define TRAIN_HPP

# include <iostream>
# include <string>
# include <chrono>

class Train
{
private:
    int                     id;
    std::string             name;
    std::string             from;
    std::string             to;
    double                  weight;
    double                  maxSpeed;
    double                  acceleration;
    double                  deceleration;
    std::chrono::minutes    departureTime;
    std::chrono::minutes    stationStopTime;

public:
	/*Getters*/
    int getId() const;
    const std::string& getName() const;
    const std::string& getFrom() const;
    const std::string& getTo() const;
    double getWeight() const;
    double getMaxSpeed() const;
    double getAcceleration() const;
    double getDeceleration() const;
    std::chrono::minutes getDepartureTime() const;
    std::chrono::minutes getStationStopTime() const;

	/*Setters*/
    void setId(int id);
    void setName(const std::string& name);
    void setFrom(const std::string& from);
    void setTo(const std::string& to);
    void setWeight(double weight);
    void setMaxSpeed(double maxSpeed);
    void setAcceleration(double acceleration);
    void setDeceleration(double deceleration);
    void setDepartureTime(std::chrono::minutes time);
    void setStationStopTime(std::chrono::minutes time);

	/*Constructors*/
    Train(int id, const std::string& name, const std::string& from, const std::string& to,
          double weight, double maxSpeed, double acceleration, double deceleration,
          std::chrono::minutes departureTime, std::chrono::minutes stationStopTime);
	Train(void);

	/*Destructors*/
    ~Train(void);

	/*Overload operators*/
	Train &operator=(const Train& src);
};

std::ostream& operator<<(std::ostream &output_stream, const Train& src);

#endif // TRAIN_HPP
