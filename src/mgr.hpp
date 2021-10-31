#ifndef MGR_H
#define MGR_H

#include <map>
#include "tex.hpp"

class Manager
{
public:
	Manager();
	Manager(std::string gp);
	// Returns a Path to an Img (<root>/img/<path>)
	std::string getImagePath(std::string path);
	// Returns a Path to an Audio file (<root>/audio/<path>)
	std::string getAudioPath(std::string path);
	std::string getLuaPath(std::string path);
	// Returns a pointer to that Image's Path.
	Texture* getImage(std::string path);
	// Remove unused Images to free up memory. Returns the count of removed Images.
	int removeUnused();
private:
	std::string game_path;
	std::map<std::string,Texture> textures;
};

#endif