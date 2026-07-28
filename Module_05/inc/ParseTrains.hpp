#ifndef PARSETRAINS_HPP
# define PARSETRAINS_HPP

#include <expected>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <cctype>
#include <chrono>

class Train;

std::expected<std::vector<Train>, std::string>  parseTrains(const std::string& filename);

#endif