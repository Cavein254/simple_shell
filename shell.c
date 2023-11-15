#include "c_shell.h"

int main(void) {
  char *commands;
  size_t buff_size;
  char prompt[] = "#cisfun$ ";

  buff_size = 0;

  while (true) {
    write(1, prompt, sizeof(prompt) - 1);
    if (getline(&commands, &buff_size, stdin) == -1)
      return (-1);
  }
  return (0);
}
