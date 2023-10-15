#include "CommandNoParam.h"

CommandNoParam::CommandNoParam()
{
}

CommandNoParam::~CommandNoParam()
{
}

char * CommandNoParam::Run()
{
    char * ret = func();

    return ret;
}