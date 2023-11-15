#include "c_shell.h"
/**
 * main - a function to find the process identifier of a running process
 * Return: 0 for successful PID
 */

int main(void)
{
	pid_t pid;

	pid = getpid();
	printf("%d\n", pid);

	return (0);
}
