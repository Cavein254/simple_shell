#include "c_shell.h"
/**
 * main - a function to find the parent ppid
 * Return: 0 for successful PPID
 */

int main(void)
{
	pid_t ppid;

	ppid = getppid();
	printf("%d\n", ppid);

	return (0);
}
