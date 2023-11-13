#include <stdio.h>
#include <unistd.h>

int print_id()
{
	pid_t pid;
	printf("Function with the process id %d begins\n",getpid());
	pid = fork();
	if (pid == -1)
	{
		printf("Error\n");
		return (1);
	}
	printf("The parent is  %d begins\n", getppid());
	return (0);
}
int main ()
{
	int x;

	x = 2;

	while (x > 0)
	{
		print_id();
		x--;
	}
	return (0);
}
