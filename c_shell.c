#include "c_shell.h"


int main (void)
{
    char *commands = NULL, *cpy_commands = NULL, *commands_token = NULL;
    char *delimiter = " \n";
    int num_arg = 0, counter = 0;
    char *list_args = NULL;
    size_t buff_size = 0;

    printf("$ ");
    if (getline(&commands, &buff_size, stdin) == -1)
        return (-1);

    cpy_commands = strdup(commands);
    commands_token =strtok(commands, delimiter);

    while (commands_token)
    {
        commands_token = strtok(NULL, delimiter);
        num_arg++;
    }
    printf("%d\n", num_arg);

    return (0);
}
