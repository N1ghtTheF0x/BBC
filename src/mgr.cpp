#include "mgr.h"

Manager::Manager()
{
	game_path = "";
}

Manager::Manager(std::string gp)
{
	game_path = gp;
}
std::string Manager::getImage(std::string path)
{
	return game_path + "img/" + path;
}
std::string Manager::getAudio(std::string path)
{
	return game_path + "audio/" + path;
}