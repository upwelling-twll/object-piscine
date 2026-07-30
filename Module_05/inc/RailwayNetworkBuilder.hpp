#ifndef RAILWAYNETWORKBUILDER_HPP
# define RAILWAYNETWORKBUILDER_HPP

# include <string>
# include <vector>
# include <expected>

# include "RailwayNetwork.hpp"

//   Names starting with "City" → City subclass
//   Everything else            → RailNode subclass

class RailwayNetworkBuilder
{
public:
	
	struct ParsedNode
	{
		std::string name;
	};

	struct ParsedRail
	{
		std::string from;
		std::string to;
		double      length;     // km
		double      speedLimit; // km/h
	};

private:
	std::vector<ParsedNode> _nodes;
	std::vector<ParsedRail> _rails;

public:
	RailwayNetworkBuilder() = default;

	RailwayNetworkBuilder& addNode(const std::string& name);
	RailwayNetworkBuilder& addRail(const std::string& from, const std::string& to, double length, double speedLimit);

	static std::expected<const std::string, std::string> validateNodeName(const std::string& name, const RailwayNetwork& network);
	static std::expected<void, std::string> validateLength(double length);
	static std::expected<void, std::string> validateSpeedLimit(double speed);
	bool uniqueRail(const RailwayNetwork& network, Node* from, Node* to);

	std::expected<RailwayNetwork, std::string> build();
};

#endif 
