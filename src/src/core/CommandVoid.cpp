#include "CommandVoid.h"

CommandVoid::CommandVoid()
{
}

CommandVoid::~CommandVoid()
{
}

void CommandVoid::Run(int argc, char *argv[])
{
    func(argc, argv);
}