#ifndef _CommandNoParam_H_
#define _CommandNoParam_H_

#include <Arduino.h>

#include "BaseCommand.h"

class CommandNoParam : public BaseCommand
{
public:

	CommandNoParam();
	~CommandNoParam();

	char * (*func)();

	char * Run();

private:

};

#endif