#ifndef RESERVATIONMANAGER_HPP
# define RESERVATIONMANAGER_HPP

# include <iostream>

static constexpr double SAFETY_GAP = 60.0;

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
    std::vector<std::vector<RailReservation>> railBookings;
    std::vector<std::vector<StationReservation>> stationBookings;

public:
	/*Member functions*/
    bool reserveRail(int railId, int trainId, double startTime, double endTime); //time in seconds from midnight
	bool reserveStation(int stationId, int trainId, double startTime, double endTime); //time in seconds from midnight
	bool isRailAvailable(int railId, double startTime, double endTime) const; //time in seconds from midnight
	bool isStationAvailable(int stationId, double startTime, double endTime) const; //time in seconds from midnight
	
	/*Getters and Setters*/
	double getEarliestRailEntryTime(int railId, double requestedStart, double travelTime) const;
	double getEarliestStationEntryTime(int stationId, double requestedStart, double travelTime) const;

	void printReservations() const;

	/*Constructors*/
	ReservationManager() = default;

	/*Destructors*/
    ~ReservationManager( void ) = default;

	/*Overload operators*/
};

#endif // RESERVATIONMANAGER_HPP
