#include "c_shell.h"

int main(void) {
  char *input_addr;
  size_t buf_size;
  char *prompt;

  input_addr = NULL;
  buf_size = 0;
  prompt = "#cisfun$";
  write(1, prompt, sizeof(prompt));
  getline(&input_addr, &buf_size, stdin);
  return (0);
}
