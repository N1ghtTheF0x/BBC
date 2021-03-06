#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>

class Debug
{
public:
    // Print simple text in the console with timestamp
    static void print(const char* text);
    static void print(const std::string text);
};

#endif // DEBUG_H
