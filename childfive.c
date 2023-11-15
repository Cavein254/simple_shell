#include "c_shell.h"

int main(void) {
  pid_t child;
  int count;
  char *argv[] = {"ls", "-l", "/tmp", NULL};
  int status;

  count = 0;
  while (count < 5) {
    child = fork();
    if (child == -1) {
      perror("Error");
      return (1);
    }
    ++count;
  }
  if (child == 0) {
    execve("/usr/bin/ls", argv, NULL);
  } else
    wait(&status);
  return (0);
}
