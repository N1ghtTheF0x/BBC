#include "mgr.hpp"
#include "debug.hpp"
#include <sstream>

Manager::Manager()
{
	game_path = "";
}

Manager::Manager(std::string gp)
{
	game_path = gp;
}
std::string Manager::getImagePath(std::string path)
{
	return game_path + "img/" + path;
}
std::string Manager::getAudioPath(std::string path)
{
	return game_path + "audio/" + path;
}
std::string Manager::getLuaPath(std::string path)
{
	return game_path + "lua/" + path;
}

Texture* Manager::getImage(const std::string path)
{
	std::string full_path = getImagePath(path);
	if((textures.find(path) == textures.end()) == false)
	{
		//textures.insert(path,std::pair<const std::string,Texture>(path,Texture(full_path))); // Needs fix
	}
	return &textures.at(path);
}

int Manager::removeUnused()
{
	int count = 0;
	for(auto const& [path,texture] : textures)
	{
		Texture tex = textures.at(path);
		if(!tex.isUsing())
		{
			count++;
			delete &texture;
			textures.erase(path);
			std::stringstream lol;
			lol << "Texture [" << &tex << "] has been removed";
			Debug::print(lol.str());
		}
	}
	return count;
}