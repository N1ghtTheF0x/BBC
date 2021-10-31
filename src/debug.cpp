#include "debug.hpp"

#include <time.h>
#include <sstream>

std::string getConsoleTime()
{
    time_t _time = time(NULL);
    tm* ctime = localtime(&_time);

    std::stringstream result;

    result << "[" << ctime->tm_hour << ":" << ctime->tm_min << ":" << ctime->tm_sec << "]";
    return result.str();
}

void Debug::print(const char* text)
{
    std::cout << getConsoleTime() << " " << text << std::endl;
}

void Debug::print(const std::string text)
{
    std::cout << getConsoleTime() << " " << text << std::endl;
}