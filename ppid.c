#include "c_shell.h"
/**
 * main - a function to find the parent process identifier of a running process
 * Return - 0 for successful PPID
 */

int main(void) {
  pid_t ppid;
  ppid = getppid();
  printf("%d\n", ppid);

  return (0);
}
