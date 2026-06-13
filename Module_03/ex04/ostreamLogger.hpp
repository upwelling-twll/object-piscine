#ifndef OSTREAMLOGGER_HPP
#define OSTREAMLOFFER_HPP

#include <iostream>
#include <fstream>

#include "ILogger.hpp"

class IHeader;

class OstreamLogger : public ILogger
{
	private:
		std::ostream*	_ostream;
		IHeader*	    header;
	
	public:
		OstreamLogger(std::ostream& ostream, IHeader* header) 
			: ILogger(), _ostream(&ostream), header(header)
		{
			if (_ostream == NULL)
				throw (std::runtime_error("Ostream cannot be NULL"));
		}

		OstreamLogger(std::ostream& ostream) : ILogger(), _ostream(&ostream)
		{
			if (_ostream == NULL)
				throw (std::runtime_error("Ostream cannot be NULL"));
		}
		
		~OstreamLogger() {}

		void write(std::string string)
		{
			std::string log;
			if (header)
				log = header->getHeader() + " : " + string;
			else
				log = string;
			(*_ostream) << log;
		}
};

#endif