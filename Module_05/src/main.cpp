#include "ParseRailways.hpp"
#include "ParseTrains.hpp"

#include "RailwaySimulation.hpp"
#include "Logger.hpp"

void print_welcome_header()
{
    constexpr std::string_view cyan = "\033[1;36m";
    constexpr std::string_view yellow = "\033[1;33m";
    constexpr std::string_view green = "\033[1;32m";
    constexpr std::string_view reset = "\033[0m";

    std::cout << green << R"(
+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
 ◊ ◊ ◊  "TIMER UL" RAHIM ITEGEZ  ◊ ◊ ◊
+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
)" << reset;

    std::cout << yellow << "            Khaerle Ul !" << green << reset << "\n";
    std::cout << "+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n\n";
}

int main(int argc, char** argv)
{
    if (argc != 3)
        return (1);
        // ERROR();
    print_welcome_header();
    auto sim = RailwaySimulation::create({
        .networkFile  = argv[1],
        .trainsFile   = argv[2],
        .level        = railways::LogLevel::DEBUG,
    });

    if (! sim)
        return (1);
    // parseRailwayNetwork(argv[1]);
    // parseTrains(argv[2]);

    return (0);
}