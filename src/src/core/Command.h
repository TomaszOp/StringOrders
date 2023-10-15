#ifndef _Command_H_
#define _Command_H_

#include <Arduino.h>

#include "BaseCommand.h"

class Command : public BaseCommand
{
public:

	Command();
	~Command();

	char * (*func)(int argc, char *argv[]);

	char * Run(int argc, char *argv[]);

private:

};

#endif