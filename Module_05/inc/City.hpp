#ifndef CITY_HPP
# define CITY_HPP

# include "Node.hpp"

class City : public Node
{
public:
	City(size_t id, const std::string& name) : Node(id, name) {}
	~City() override = default;

	bool isCity() const override { return true; }
};

#endif