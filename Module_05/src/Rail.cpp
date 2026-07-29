#include "Rail.hpp"
#include "Node.hpp"

Rail::Rail(size_t id, Node* from, Node* to, double length, double speedLimit)
    : _id(id), _from(from), _to(to), _length(length), _speedLimit(speedLimit)
{
}
