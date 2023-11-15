#include "c_shell.h"

int main(void) {
  char *input_addr;
  size_t buf_size;
  char prompt[] = "#cisfun$ ";

  input_addr = NULL;
  buf_size = 0;

  while (true) {
    write(1, prompt, sizeof(prompt) - 1);
    getline(&input_addr, &buf_size, stdin);
  }
  return (0);
}
