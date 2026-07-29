#ifndef PARSERAILWAYS_HPP
# define PARSERAILWAYS_HPP

# include <expected>
# include <fstream>
# include <iostream>
# include <sstream>
# include <string>

# include "RailwayNetwork.hpp"

std::expected<RailwayNetwork, std::string> parseRailwayNetwork(const std::string& filename);

#endif // PARSERAILWAYS_HPP