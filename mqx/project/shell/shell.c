#include <mqx.h>
#include <shell.h>


void task_shell(uint_32);
const TASK_TEMPLATE_STRUCT  MQX_template_list[] = 
{
  /* Task Index, Function,     Stack,    Priority,  Name,     Attributes,          Param, Time Slice */
   { 1,          task_shell,   4000,     8,         "shell",  MQX_AUTO_START_TASK, 0,     0 },
   { 0 }
};


int_32 atmode(int_32 argc, char_ptr argv[]);
int_32 atlogin(int_32 argc, char_ptr argv[]);
int_32 atexit(int_32 argc, char_ptr argv[]);

const SHELL_COMMAND_STRUCT Shell_commands[] = 
{
    { "atmode", atmode },
    { "atlogin", atlogin },
    { "atexit", atexit },
    { NULL, NULL }
};

int_32 atmode(int_32 argc, char_ptr argv[])
{
		printf(" 0 \n");
    return 0;
}

int_32 atlogin(int_32 argc, char_ptr argv[])
{
		printf(" 1 \n");
    return 0;
}

int_32 atexit(int_32 argc, char_ptr argv[])
{
		printf(" 2 \n");
    return 0;
}
void task_shell(uint_32 p)
{
    for (;;)
    {
        Shell(Shell_commands, NULL);
    }
}
