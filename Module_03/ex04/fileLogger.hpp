#ifndef FILELOGGER_HPP
#define FILELOFFER_HPP

#include "ILogger.hpp"
class FileLogger : public ILogger
{
	private:
		std::string filePath;
		std::string header;
	
	public:
		FileLogger(std::string path, std::string header) 
			: ILogger(), filePath(path), header(header)
			{
				int fd = open.
			}
		~FileLogger() {}

		void write()
		{

		}
};

#endif