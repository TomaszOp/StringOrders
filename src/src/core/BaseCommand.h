#ifndef _BaseCommand_H_
#define _BaseCommand_H_

#include <Arduino.h>


class BaseCommand
{
public:

	BaseCommand();
	~BaseCommand();

	char * Order;
	char * Help;

private:

};

#endif