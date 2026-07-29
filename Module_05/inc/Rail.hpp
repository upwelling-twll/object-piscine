#ifndef RAIL_HPP
# define RAIL_HPP

# include <cstddef>

class Node;

class Rail
{
private:
	size_t _id;
	Node*  _from;       
	Node*  _to;       
	double _length;     // km
	double _speedLimit; // km/h

public:
	Rail(size_t id, Node* from, Node* to, double length, double speedLimit);
	~Rail() = default;

	Rail(const Rail&)            = delete;
	Rail& operator=(const Rail&) = delete;
	Rail(Rail&&)                 = default;
	Rail& operator=(Rail&&)      = default;

	size_t getId()         const { return _id; }
	Node*  getFrom()       const { return _from; }
	Node*  getTo()         const { return _to; }
	double getLength()     const { return _length; }
	double getSpeedLimit() const { return _speedLimit; }
};

#endif
