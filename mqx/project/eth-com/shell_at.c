#include "shell_at.h"
#include "shell.h"

const SHELL_COMMAND_STRUCT Shell_commands[]=
{
    { NULL, NULL }
};
void shell_server_task(uint_32 initial_data)
{
    for (;;)
    {
        //Shell(Shell_commands, NULL);
    }
}
