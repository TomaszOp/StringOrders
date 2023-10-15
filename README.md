# StringOrders

Simple library for execute function

You can build a list of commands of the string + function type that is associated with a given command

<br>
StringCommand cmd;
<br>
cmd.Add(order1, [](int argc, char **argv) -> char * {
                  ;;;
                  return char *;
                  }
                  ,help);
<br>
cmd.Add(order2, 
                [](int argc, char **argv) -> void {
                    ;;;
                    },
                help
                );
<br>
cmd.Add(order3, 
                []() -> void {
                    ;;;
                    return char *;
                    },
                help
                );
<br>
cmd.Add(order4, 
                []() -> void {
                    ;;;
                    },
                help
                );
<br>
char * ret= cmd.Run(order1, argc, argv);
<br>
cmd.Run(order2, argc, argv);
<br>
char * ret= cmd.Run(order3);
<br>
cmd.Run(order4);
<br>
