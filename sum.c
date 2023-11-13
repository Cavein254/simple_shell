#include <stdio.h>
#include <unistd.h>

int main ()
{
	pid_t pid;
	pid = fork();
	if (pid == -1)
	{
		printf("Error occured initializing the child \n");
	}
	if (pid == 0)
	{
		printf("Running the child process \n");
	} else
	{
		sleep(40);
		printf("The parent process running \n");
	}
	return (0);
}
