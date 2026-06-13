#ifndef TIMEHEADER_HPP
#define TIMEHEADER_HPP

#include <iostream>
#include <chrono>
#include "IHeader.hpp"

class TimeHeader : public IHeader
{
	public:
		
        std::string getHeader()
        {
             const std::chrono::system_clock::time_point tp_utc = std::chrono::system_clock::now();
            std::time_t now = std::chrono::system_clock::to_time_t(tp_utc);
            std::string time = std::ctime(&now);
            time.erase(time.size() - 1);
            return (time);        
        }

		TimeHeader() : IHeader() {}
		~TimeHeader() {}
};

#endif