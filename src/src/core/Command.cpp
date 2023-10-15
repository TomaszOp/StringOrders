#include "Command.h"

Command::Command()
{
}

Command::~Command()
{
}

char * Command::Run(int argc, char *argv[])
{
    char * ret = func(argc, argv);

    return ret;
}