#include "c_shell.h"

int main(void) {
  char *commands, *commands_token, *delimiter;
  size_t buff_size;
  char **list_args;
  char prompt[] = "#cisfun$ ";
  int counter, status;
  pid_t pid_child;

  buff_size = 0;
  delimiter = " \n";
  counter = 0;

  while (true) {
    write(1, prompt, sizeof(prompt) - 1);
    if (getline(&commands, &buff_size, stdin) == -1)
      return (-1);
    commands_token = strtok(commands, delimiter);
    /*allocate space in heap*/
    list_args = malloc(sizeof(char *) * BLOCK_SIZE);
    while (commands_token) {
      list_args[counter] = commands_token;
      commands_token = strtok(NULL, delimiter);
      counter++;
    }
    /*Args must end in NULL*/
    list_args[counter] = NULL;
    pid_child = fork();
    if (pid_child == -1)
      perror("Error : child creation failed");
    if (pid_child == 0) {
      if ((execve(list_args[0], list_args, NULL)) == -1)
        perror("Error: execve failed");
    } else
      wait(&status);
    /*reset counter*/
    counter = 0;
    /*free resources*/
    free(list_args);
  }
  return (0);
}
