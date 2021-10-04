#ifndef MGR_H
#define MGR_H

#include <map>

class Manager
{
public:
	Manager();
	Manager(std::string gp);
	std::string getImage(std::string path);

private:
	std::string game_path;
};

#endif