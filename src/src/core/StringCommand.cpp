#include "StringCommand.h"


StringCommand::StringCommand()
{
    countCommands = 0;
}

StringCommand::~StringCommand()
{
}

bool StringCommand::AddCommand(char * order,  char * (*func)(int argc, char *argv[]), char* help)
{
    if(ExistCommand(order, 0))
    {
        return false;
    }

    #ifdef Debug_StringCommand
    Serial.println("AddCommand");
    #endif

    if(countCommands == 0)
        Commands = (Command*)malloc(sizeof(Command)); 
    else
        Commands = (Command*)realloc(Commands, (countCommands + 1) * sizeof(Command));

    Commands[countCommands].Order = order;
    Commands[countCommands].func = func;
    Commands[countCommands].Help = help;

    countCommands++;
    
    return true;
}

bool StringCommand::AddCommandNoParam(char * order, char * (*func)(), char* help)
{
    if(ExistCommand(order, 1))
    {
        return false;
    }

    #ifdef Debug_StringCommand
    Serial.println("AddCommand NoParam");
    #endif

    if(countCommandsNoParam == 0)
        CommandsNoParam = (CommandNoParam*)malloc(sizeof(CommandNoParam)); 
    else
        CommandsNoParam = (CommandNoParam*)realloc(CommandsNoParam, (countCommandsNoParam + 1) * sizeof(CommandNoParam));

    CommandsNoParam[countCommandsNoParam].Order = order;
    CommandsNoParam[countCommandsNoParam].func = func;
    CommandsNoParam[countCommandsNoParam].Help = help;

    countCommandsNoParam++;   

    return true;
}

bool StringCommand::AddCommandVoid(char * order, void (*func)(int argc, char *argv[]), char* help)
{
    if(ExistCommand(order, 2))
    {
        return false;
    }

    #ifdef Debug_StringCommand
    Serial.println("AddCommand void");
    #endif

    if(countCommandsVoid == 0)
        CommandsVoid = (CommandVoid*)malloc(sizeof(CommandVoid)); 
    else
        CommandsVoid = (CommandVoid*)realloc(CommandsVoid, (countCommandsVoid + 1) * sizeof(CommandVoid));

    CommandsVoid[countCommandsVoid].Order = order;
    CommandsVoid[countCommandsVoid].func = func;
    CommandsVoid[countCommandsVoid].Help = help;

    countCommandsVoid++; 

    return true;
}

bool StringCommand::AddCommandVoidNoParam(char * order, void (*func)(), char* help)
{
    if(ExistCommand(order, 3))
    {
        return false;
    }

    #ifdef Debug_StringCommand
    Serial.println("AddCommand void NoParam");
    #endif

    if(countCommandsVoidNoParam == 0)
        CommandsVoidNoParam = (CommandVoidNoParam*)malloc(sizeof(CommandVoidNoParam)); 
    else
        CommandsVoidNoParam = (CommandVoidNoParam*)realloc(CommandsVoidNoParam, (countCommandsVoidNoParam + 1) * sizeof(CommandVoidNoParam));

    CommandsVoidNoParam[countCommandsVoidNoParam].Order = order;
    CommandsVoidNoParam[countCommandsVoidNoParam].func = func;
    CommandsVoidNoParam[countCommandsVoidNoParam].Help = help;

    countCommandsVoidNoParam++; 

    return true;
}


bool StringCommand::Add(char * order, char * (*func)(int argc, char *argv[]), char* help)
{
    return AddCommand(order,  func, help);
}

bool StringCommand::Add(char * order, char * (*func)(), char* help)
{
    return AddCommandNoParam(order,  func, help);
}

bool StringCommand::Add(char * order, void (*func)(int argc, char *argv[]), char* help)
{
    return AddCommandVoid(order,  func, help);
}

bool StringCommand::Add(char * order, void (*func)(), char* help)
{
    return AddCommandVoidNoParam(order,  func, help);
}




char * StringCommand::RunCommand(char * order, int argc, char *argv[])
{
    #ifdef Debug_StringCommand
    Serial.println("RunCommand");
    #endif

    Command * ptrCommand = NULL;

    int orderPoz = 0;
    for(orderPoz = 0; orderPoz < countCommands; orderPoz++)
    {
        if(strcmp(order, Commands[orderPoz].Order) == 0)
        {
            ptrCommand = &Commands[orderPoz];
            break;
        }
    }

    if(ptrCommand == NULL) 
    {
        #ifdef Debug_StringCommand
        Serial.println("Command not found");
        #endif

        return NULL;
    }

    char * result =  ptrCommand->func(argc, argv);

    return result;
}

char * StringCommand::RunCommand(char * order)
{
    #ifdef Debug_StringCommand
    Serial.println("RunCommand no param");
    #endif

    CommandNoParam * ptrCommand = NULL;

    int orderPoz = 0;
    for(orderPoz = 0; orderPoz < countCommandsNoParam; orderPoz++)
    {
        if(strcmp(order, CommandsNoParam[orderPoz].Order) == 0)
        {
            ptrCommand = &CommandsNoParam[orderPoz];
            break;
        }
    }

    if(ptrCommand == NULL) return NULL;

    char * result =  ptrCommand->func();

    return result;
}

void StringCommand::RunCommandVoid(char * order, int argc, char *argv[])
{
    #ifdef Debug_StringCommand
    Serial.println("RunCommandVoid");
    #endif

    CommandVoid * ptrCommand = NULL;

    int orderPoz = 0;
    for(orderPoz = 0; orderPoz < countCommandsVoid; orderPoz++)
    {
        if(strcmp(order, CommandsVoid[orderPoz].Order) == 0)
        {
            ptrCommand = &CommandsVoid[orderPoz];
            break;
        }
    }

    if(ptrCommand == NULL) return ;

    ptrCommand->func(argc, argv);
}

void StringCommand::RunCommandVoid(char * order)
{
    #ifdef Debug_StringCommand
    Serial.println("RunCommandVoid no param");
    #endif

    CommandVoidNoParam * ptrCommand = NULL;

    int orderPoz = 0;
    for(orderPoz = 0; orderPoz < countCommandsVoidNoParam; orderPoz++)
    {
        if(strcmp(order, CommandsVoidNoParam[orderPoz].Order) == 0)
        {
            ptrCommand = &CommandsVoidNoParam[orderPoz];
            break;
        }
    }

    if(ptrCommand == NULL) return ;

    ptrCommand->func();
}


char * StringCommand::Run(char * order, int argc, char *argv[])
{
    int position = -1;

    if(ExistCommand(order, 0, position))
    {
        return Commands[position].Run(argc, argv);
    }

    if(ExistCommand(order, 2, position))
    {
        CommandsVoid[position].Run(argc, argv);
        return nullptr;
    }

    return nullptr;
}

char * StringCommand::Run(char * order)
{
    int position = -1;

    if(ExistCommand(order, 1, position))
    {
        return CommandsNoParam[position].Run();
    }

    if(ExistCommand(order, 3, position))
    {
        CommandsVoidNoParam[position].Run();
        return nullptr;
    }

    return nullptr;
}

bool StringCommand::ExistCommand(char * order, int mode)
{
    int position;
    return ExistCommand(order, mode, position);
}

bool StringCommand::ExistCommand(char * order, int mode, int & position)
{
    int orderPoz = 0;
    position = -1;

    if(mode == 0)
    {
        for(orderPoz = 0; orderPoz < countCommands; orderPoz++)
        {
            if(strcmp(order, Commands[orderPoz].Order) == 0)
            {
                position = orderPoz;
                return true;
            }
        }
    }
    else if(mode == 1)
    {
        for(orderPoz = 0; orderPoz < countCommandsNoParam; orderPoz++)
        {
            if(strcmp(order, CommandsNoParam[orderPoz].Order) == 0)
            {
                position = orderPoz;
                return true;
            }
        }
    }
    else if(mode == 2)
    {
        for(orderPoz = 0; orderPoz < countCommandsVoid; orderPoz++)
        {
            if(strcmp(order, CommandsVoid[orderPoz].Order) == 0)
            {
                position = orderPoz;
                return true;
            }
        }
    }
    else if(mode == 3)
    {
        for(orderPoz = 0; orderPoz < countCommandsVoidNoParam; orderPoz++)
        {
            if(strcmp(order, CommandsVoidNoParam[orderPoz].Order) == 0)
            {
                position = orderPoz;
                return true;
            }
        }
    }

    return false;
}

char ** StringCommand::GetOrders(int & argc)
{
    argc = countCommands + countCommandsNoParam + countCommandsVoid + countCommandsVoidNoParam;

    if(argc == 0)
        return NULL;

    char ** argv = (char **)malloc(sizeof(char *) * (argc));

    int nr=0;

    for (int i = 0; i < countCommands; i++)
    {
        argv[nr] = Commands[i].Order;
        nr++;
    }
    
    for (int i = 0; i < countCommandsNoParam; i++)
    {
        argv[nr] = CommandsNoParam[i].Order;
        nr++;
    }

    for (int i = 0; i < countCommandsVoid; i++)
    {
        argv[nr] = CommandsVoid[i].Order;
        nr++;
    }

    for (int i = 0; i < countCommandsVoidNoParam; i++)
    {
        argv[nr] = CommandsVoidNoParam[i].Order;
        nr++;
    }

    return argv;
}