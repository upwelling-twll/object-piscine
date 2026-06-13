#ifndef IHEADER_HPP
#define IHEADER_HPP

#include <iostream>

class IHeader
{
	public:
		virtual std::string getHeader() = 0;

		IHeader() {}
		virtual ~IHeader() {}
};

#endif