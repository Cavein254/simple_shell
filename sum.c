#include <stdio.h>
#include <unistd.h>

void print_id()
{
	printf("Function with the process id %d begins\n",getpid());
	printf("The parent is  %d begins\n",getppid());
}
int main ()
{
	int x;
	x = 10;
	while (x > 0)
	{
		print_id();
		x--;
	}
	return (0);
}
