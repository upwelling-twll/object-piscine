#ifndef RESERVATIONMANAGER_HPP
# define RESERVATIONMANAGER_HPP

# include <iostream>

struct RailReservation
{
	int trainId;
	int railId; 
	double startTime; // in seconds from midnight
	double endTime;   // in seconds from midnight
};

struct StationReservation
{
	int trainId;
	int stationId; 
	double startTime; // in seconds from midnight
	double endTime;   // in seconds from midnight
};

class ReservationManager
{
private:
    

public:
	/*Member functions*/
    void reserveRail(int railId, int trainId, double startTime, double endTime); //time in seconds from midnight
	void reserveStation(int stationId, int trainId, double startTime, double endTime); //time in seconds from midnight
	bool isRailAvailable(int railId, double startTime, double endTime) const; //time in seconds from midnight
	bool isStationAvailable(int stationId, double startTime, double endTime) const; //time in seconds from midnight
	/*Getters and Setters*/

	void printReservations() const;

	/*Constructors*/
	ReservationManager() = default;

	/*Destructors*/
    ~ReservationManager( void ) = default;

	/*Overload operators*/
};

#endif // RESERVATIONMANAGER_HPP
