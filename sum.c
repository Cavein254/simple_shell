#include <stdio.h>
#include <unistd.h>

int main ()
{
	printf("Function with the process id %d begins\n",getpid());
	printf("The parent is  %d begins\n",getppid());
}
