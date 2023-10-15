#ifndef _CommandVoid_H_
#define _CommandVoid_H_

#include <Arduino.h>

#include "BaseCommand.h"

class CommandVoid : public BaseCommand
{
public:

	CommandVoid();
	~CommandVoid();

	void (*func)(int argc, char *argv[]);

	void Run(int argc, char *argv[]);

private:

};

#endif