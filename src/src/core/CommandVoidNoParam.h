#ifndef _CommandVoidNoParam_H_
#define _CommandVoidNoParam_H_

#include <Arduino.h>

#include "BaseCommand.h"

class CommandVoidNoParam : public BaseCommand
{
public:

	CommandVoidNoParam();
	~CommandVoidNoParam();

	void (*func)();

	void Run();

private:

};

#endif