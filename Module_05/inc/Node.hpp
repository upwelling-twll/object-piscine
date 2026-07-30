#ifndef NODE_HPP
# define NODE_HPP
# include <iostream>
# include <string>
#include "Logger.hpp"


class Node
{
private:
	size_t      _id;
	std::string _name;

public:

	size_t             getId()   const { return _id; }
	const std::string& getName() const { return _name; }

	virtual bool isCity() const = 0;
	virtual ~Node() = 0;

	Node(size_t id, const std::string& name) : _id(id), _name(name) {}

	Node(const Node&)            = delete;
	Node& operator=(const Node&) = delete;
	Node(Node&&)                 = default;
	Node& operator=(Node&&)      = default;
};

// Out-of-line definition required for pure virtual destructor
inline Node::~Node() {}

#endif