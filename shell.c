#include "c_shell.h"

int main(void) {
  char *commands = NULL, *delimiter = NULL, *commands_token = NULL;
  char *cpy_commands = NULL;
  char **list_args = NULL;
  size_t buf_size;
  int counter = 0;
  char prompt[] = "#cisfun$ ";

  delimiter = " \n";
  buf_size = 0;

  while (true) {
    write(1, prompt, sizeof(prompt) - 1);
    if (getline(&commands, &buf_size, stdin) == -1)
      return (-1);

    /*Make a copy of commands since strtok modifies original string*/
    cpy_commands = strdup(commands);
    commands_token = strtok(commands, delimiter);

    while (commands_token != '\n') {
      list_args[counter] = commands_token;
      commands_token = strtok(NULL, delimiter);
      counter++;
    }
    /*All args end with a NULL*/
    list_args[counter] = NULL;
  }
  return (0);
}
