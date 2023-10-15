# StringOrders

Simple library for execute function

You can build a list of commands of the string + function type that is associated with a given command

<br>
StringCommand cmd;
<br>
cmd.Add(order, [](int argc, char **argv) -> char * {
                  return ???;
                  }
                  ,help);
<br>
cmd.Add(orderVoid, 
                [](int argc, char **argv) -> void {
                       ;
                    },
                help
                );
<br>
cmd.Run(order, argc, argv);
<br>
