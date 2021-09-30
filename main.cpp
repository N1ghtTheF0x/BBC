#include "app.h"
#include "debug.h"

int main(int argc,char** argv)
{
    Debug::print("main(): Start");
    App app(argc,argv);
    Debug::print("main(): End");
    return app.onExecute();
}
