#ifndef TRAIN_HPP
# define TRAIN_HPP

# include <iostream>
# include <string>
# include <chrono>
 
//order in input file:
//TrainAB 80 0.05 356.0 30.0 CityA CityB 14h10 00h10
//name coef_of_friction / accel / decel / from / to / dep_time/ station_time

class Train
{
private:
    int                     id;
    std::string             name;
    std::string             from;
    std::string             to;
    double                  weight;
    double                  cof;
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
    double getCOF() const;
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
    void setCOF(double cof);
    void setAcceleration(double acceleration);
    void setDeceleration(double deceleration);
    void setDepartureTime(std::chrono::minutes time);
    void setStationStopTime(std::chrono::minutes time);

	/*Constructors*/
    Train(int id, const std::string& name, const std::string& from, const std::string& to,
          double weight, double cof, double acceleration, double deceleration,
          std::chrono::minutes departureTime, std::chrono::minutes stationStopTime);
	Train(void);

	/*Destructors*/
    ~Train(void);

	/*Overload operators*/
	Train &operator=(const Train& src);
};

std::ostream& operator<<(std::ostream &output_stream, const Train& src);

#endif // TRAIN_HPP
