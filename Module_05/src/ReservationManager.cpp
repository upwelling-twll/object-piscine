#include "ReservationManager.hpp"

/*Member functions*/
bool reserveRail(int railId, int trainId, double startTime, double endTime)
{
	if (isRailAvailable(railId, startTime, endTime))
	{
		RailReservation reservation{trainId, railId, startTime, endTime};
		if (railId >= railBookings.size())
			railBookings.resize(railId + 1);
		railBookings[railId].push_back(reservation);
		return true;
	}
	else
	{
		log.error(std::format("Rail {} is not available for the requested time slot.", railId));
		return false;
	}
}

bool reserveStation(int stationId, int trainId, double startTime, double endTime)
{
	if (isStationAvailable(stationId, startTime, endTime))
	{
		StationReservation reservation{trainId, stationId, startTime, endTime};
		if (stationId >= stationBookings.size())
			stationBookings.resize(stationId + 1);
		stationBookings[stationId].push_back(reservation);
		return true;
	}
	else
	{
		log.error(std::format("Station {} is not available for the requested time slot.", stationId));
		return false;
	}
}


bool isRailAvailable(int railId, double startTime, double endTime) const
{
	if (railId >= railBookings.size())
		return true; // No reservations for this rail yet
	for (const auto &reservation : railBookings[railId])
	{
		if (startTime < reservation.endTime && endTime > reservation.startTime)
			return false; // Conflict found
	}
	return true; // No conflicts found
}

bool isStationAvailable(int stationId, double startTime, double endTime) const
{
	if (stationId >= stationBookings.size())
		return true; // No reservations for this station yet
	for (const auto &reservation : stationBookings[stationId])
	{
		if (startTime < reservation.endTime && endTime > reservation.startTime)
			return false; // Conflict found
	}
	return true; // No conflicts found
}

/*Getters and Setters*/

double getEarliestRailEntryTime(int railId, double requestedStart, double travelTime) const
{
    if (railId >= railBookings.size())
        return requestedStart;

    double candidateStart = requestedStart;
    bool conflictFound = true;

    while (true)
    {
        conflictFound = false;
        double candidateEnd = candidateStart + travelTime;
        for (const auto& reservation : railBookings[railId])
        {
            bool overlaps = candidateStart < reservation.endTime && candidateEnd > reservation.startTime;
            if (overlaps)
            {
                candidateStart = reservation.endTime + SAFETY_GAP;
                conflictFound = true;
                break;
            }
        }
		if (!conflictFound)
            return candidateStart;
    }
}

double getEarliestStationEntryTime(int stationId, double requestedStart, double travelTime) const
{
	if (stationId >= stationBookings.size())
		return requestedStart;

	double candidateStart = requestedStart;
	bool conflictFound = true;
	while (true)
	{
		conflictFound = false;
		double candidateEnd = candidateStart + travelTime;
		for (const auto& reservation : stationBookings[stationId])
		{
			bool overlaps = candidateStart < reservation.endTime && candidateEnd > reservation.startTime;
			if (overlaps)
			{
				candidateStart = reservation.endTime + SAFETY_GAP;
				conflictFound = true;
				break;
			}
		}
		if (!conflictFound)
            return candidateStart;
	}
}

void printReservations() const
{
	log.debug("Rail Reservations:");
	for (size_t railId = 0; railId < railBookings.size(); ++railId)
	{
		for (const auto &reservation : railBookings[railId])
		{
			log.debug(std::format("Rail {}: Train {} from {} to {}", reservation.railId, reservation.trainId, reservation.startTime, reservation.endTime));
		}
	}

	log.debug("Station Reservations:");
	for (size_t stationId = 0; stationId < stationBookings.size(); ++stationId)
	{
		for (const auto &reservation : stationBookings[stationId])
		{
			log.debug(std::format("Station {}: Train {} from {} to {}", reservation.stationId, reservation.trainId, reservation.startTime, reservation.endTime));
		}
	}
}



