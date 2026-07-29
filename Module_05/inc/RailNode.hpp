#ifndef RAILNODE_HPP
# define RAILNODE_HPP

# include "Node.hpp"

class RailNode : public Node
{
public:
	RailNode(size_t id, const std::string& name) : Node(id, name) {}
	~RailNode() override = default;

	bool isCity() const override { return false; }
};

#endif