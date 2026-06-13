#ifndef STRINGHEADER_HPP
#define STRINGHEADER_HPP

#include <iostream>
#include "IHeader.hpp"

class StringHeader : public IHeader
{
    private:
        const std::string _header;

	public:
		
        std::string getHeader()
        {
            return (this->_header);        
        }

		StringHeader(const std::string header) : IHeader(), _header(header) {}
		~StringHeader() {}
};

#endif