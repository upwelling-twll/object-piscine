#ifndef FILELOGGER_HPP
#define FILELOGGER_HPP

#include <iostream>
#include <fstream>

#include "ILogger.hpp"

class IHeader;

class FileLogger : public ILogger
{
	private:
		std::string	filePath;
		IHeader*	header;

		std::ofstream fileStream;
	
	public:
		FileLogger(std::string path, IHeader* header) 
			: ILogger(), filePath(path), header(header)
		{
			fileStream.open(filePath);
			if (!(fileStream.is_open()))
				throw (std::runtime_error("File " + filePath + " cannot be used"));
		}

		FileLogger(std::string path) : ILogger(), filePath(path)
		{
			fileStream.open(filePath);
			header = NULL;
			if (!(fileStream.is_open()))
				throw (std::runtime_error("File " + filePath + " cannot be used"));
			std::cout << "FileLogger to " << path << std::endl;
		}
		
		~FileLogger()
		{
			if (fileStream.is_open())
				fileStream.close();
		}

		void write(std::string string)
		{
			if (header)
				fileStream << header->getHeader() << " : " << string << "\n";
			else
				fileStream << string << "\n";
			fileStream.flush();
		}
};

#endif