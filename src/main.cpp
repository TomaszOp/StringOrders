#include <Arduino.h>

#include "src/core/StringCommand.h"
#include "src/core/Command.h"


StringCommand cmd;


char order[20] ="order";
char orderNoParam[20] ="orderNoParam";
char orderVoid[20] ="orderVoid";
char orderVoidNoParam[20] ="orderVoidNoParam";

char help[20] ="help";

void setup() {

Serial.begin(115200);

// method
/*
cmd.AddCommand;
cmd.AddCommandNoParam;
cmd.AddCommandVoid;
cmd.AddCommandVoidNoParam
or
cmd.Add
*/


cmd.Add(order, [](int argc, char **argv) -> char * {
                  Serial.println("aaa");
                  return argv[0];
                  }
                  ,help);

/*
cmd.AddCommand(order, [](int argc, char **argv) -> char * {
                  Serial.println("aaa");
                  return argv[0];
                  }
                  ,help);
*/

cmd.Add(orderNoParam, 
                []() -> char * {
                        Serial.println("aaa no param");
                        return orderNoParam;;
                    },
                help
                );

/*
cmd.AddCommandNoParam(orderNoParam, 
                []() -> char * {
                        Serial.println("aaa no param");
                        return orderNoParam;;
                    },
                help
                );
*/

cmd.Add(orderVoid, 
                [](int argc, char **argv) -> void {
                        Serial.println("aaa void");
                    },
                help
                );


cmd.Add(orderVoidNoParam, 
                []() -> void {
                        Serial.println("aaa void no param");
                    },
                help
                );


}

void loop() {
  
  Serial.println("loop");
  
  char *argv[3];
  char arg1[10] = "arg1";
  char arg2[10] = "arg2";
  char arg3[10] = "arg3";

  argv[0] = arg1;
  argv[1] = arg2;
  argv[2] = arg3;


  /* execute function
  cmd.RunCommand;
  cmd.RunCommandVoid;
  cmd.Run
  */

  char * ret = cmd.Run(order, 3, argv);
  Serial.println(ret);

  //char * ret = cmd.RunCommand(order, 3, argv);
  //Serial.println(ret);
  //char * ret2 = cmd.RunCommand(orderNoParam);
  //Serial.println(ret2);
  //cmd.RunCommandVoid(orderVoid, 3, argv);
  //cmd.RunCommandVoid(orderVoidNoParam);

  delay(3000);
}

