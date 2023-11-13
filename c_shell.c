#include "c_shell.h"

int main (void)
{
    char *commands = NULL, *cpy_commands = NULL, *commands_token = NULL;
    char *delimiter = " \n";
    int num_arg = 0, counter = 0;
    char **list_args = NULL;
    size_t buff_size = 0;

    printf("$ ");
    if (getline(&commands, &buff_size, stdin) == -1)
        return (-1);

    /*Make a copy of commands since strtok modifies original string*/
    cpy_commands = strdup(commands);

    commands_token =strtok(commands, delimiter);

    while (commands_token)
    {
        commands_token = strtok(NULL, delimiter);
        num_arg++;
    }

    list_args = malloc(sizeof(char *) * num_arg);

    commands_token = strtok(cpy_commands, delimiter);

    while (commands_token)
    {
        list_args[counter] = commands_token;
        commands_token = strtok(NULL, delimiter);
        counter++;
    }
    list_args[counter] = NULL;

    counter = 0;
    while (list_args[counter])
    {
        printf("%s\n", list_args[counter]);
        counter++;
    }
    return (0);
}
