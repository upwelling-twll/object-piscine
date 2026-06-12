#include "ILogger.hpp"
#include <vector>
#include <list>
#include <string>

int main()
{
	std::vector<ILogger*> loggers;
	std::list<std::string> strings = {
	"Lost the Fellowship in the dark mines. The Wizard fell into the abyss with the demon. They escaped, but the Grey One did not.",
	"Found their trail beside the Great River. Many Men, one Elf, one Dwarf, four Hobbits. The Precious is still with the little master.",
	"The Fellowship is broken. The tall Man was slain by orcs. The little master and his friend have gone away alone.",
	"Following the Hobbits through the dead marshes. The fat one watches me carefully. He does not trust Sméagol.",
	"The little master spared me again. Strange kindness. We guides them through the marshes toward the Black Gate.",
	"The Black Gate cannot be passed. Too many eyes, too many soldiers. We must take them by another road.",
	"The Hobbits entered the land of Ithilien. Men captured us, but the captain released the little master after questioning him.",
	"Leading them toward the pass of Cirith Ungol. The Precious grows nearer, yet the fat Hobbit remains a problem.",
	"Shelob attacked. The little master fell. The fat one took the Precious for himself. We hates him even more now.",
	"The little master reached the Fire. He claimed the Precious instead of destroying it. We fought for it, took it back at last, and fell into the Fire with our Precious."
	};

	for (auto it = loggers.begin(); it != loggers.end(); ++it)
	{
		for (auto it_s = strings.begin(); it_s != strings.end(); ++it_s)
			it->write(it_s);
	}

}