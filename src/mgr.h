#ifndef MGR_H
#define MGR_H

#include <map>

class Manager
{
public:
	Manager();
	Manager(std::string gp);
	// Returns a Path to an Img (<root>/img/<path>)
	std::string getImage(std::string path);
	// Returns a Path to an Audio file (<root>/audio/<path>)
	std::string getAudio(std::string path);

private:
	std::string game_path;
};

#endif