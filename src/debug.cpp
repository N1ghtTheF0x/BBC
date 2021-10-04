#include "debug.h"
#include <time.h>

void Debug::print(const char* text)
{
    time_t _time = time(NULL);
    tm* ctime = localtime(&_time);


    std::cout << "[" << ctime->tm_hour << ":" << ctime->tm_min << ":" << ctime->tm_sec << "] " << text << std::endl;
}