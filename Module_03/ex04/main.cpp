#include "ILogger.hpp"
#include "IHeader.hpp"
#include "fileLogger.hpp"
#include "ostreamLogger.hpp"
#include "stringHeader.hpp"
#include "timeHeader.hpp"

#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <string>

#define RED "\033[31m"
# define RESET  "\033[0m"


int main()
{
	try 
	{
		std::ofstream out3("golumReport.txt");
		TimeHeader* time1 = new TimeHeader(	);
		
		StringHeader* s1 = new StringHeader("GOLUM REPORTING");
		StringHeader* s2 = new StringHeader("SMEAGOL REPORTING");
		
		FileLogger* log1 = new FileLogger("log1");
		FileLogger* log2 = new FileLogger("log2", time1);
		
		// if (out3.open())
		OstreamLogger* log3 = new OstreamLogger(out3, s1);
		// else
			// std::cout << "MAIN: can not open file" << std::endl;
		OstreamLogger* log4 = new OstreamLogger(std::cout, s2);
		
		std::vector<ILogger*> loggers;
		loggers.push_back(log1);
		loggers.push_back(log2);
		loggers.push_back(log3);
		loggers.push_back(log4);
	
		std::list<std::string> strings = {
		"Lost the Fellowship in the dark mines. The Wizard fell into the abyss with the demon. They escaped, but the Grey One did not.\n",
		"Found their trail beside the Great River. Many Men, one Elf, one Dwarf, four Hobbits. The Precious is still with the little master.\n",
		"The Fellowship is broken. The tall Man was slain by orcs. The little master and his friend have gone away alone.\n",
		"Following the Hobbits through the dead marshes. The fat one watches me carefully. He does not trust Sméagol.\n",
		"The little master spared me again. Strange kindness. We guides them through the marshes toward the Black Gate.\n",
		"The Black Gate cannot be passed. Too many eyes, too many soldiers. We must take them by another road.\n",
		"The Hobbits entered the land of Ithilien. Men captured us, but the captain released the little master after questioning him.\n",
		"Leading them toward the pass of Cirith Ungol. The Precious grows nearer, yet the fat Hobbit remains a problem.\n",
		"Shelob attacked. The little master fell. The fat one took the Precious for himself. We hates him even more now.\n",
		"The little master reached the Fire. He claimed the Precious instead of destroying it. We fought for it, took it back at last, and fell into the Fire with our Precious.\n"
		};
	
		for (auto it = loggers.begin(); it != loggers.end(); ++it)
		{
			for (auto it_s = strings.begin(); it_s != strings.end(); ++it_s)
				(*it)->write(*it_s);
		}
	}
	catch (const char* msg)
	{
    	std::cerr << RED <<"Error: " << msg << RESET << std::endl;
	}
	return 0;
}