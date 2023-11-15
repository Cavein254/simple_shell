#include "c_shell.h"

int main() {
  char *argv[] = {"ls", "-l", NULL};
  char *path = "/usr/bin/ls";

  printf("Before execve\n");

  if (execve(path, argv, NULL) == -1)
    perror("Error:");
  printf("After execve\n");
  return (0);
}
