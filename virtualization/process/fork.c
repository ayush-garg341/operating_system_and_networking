#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	printf("Hello world PID: %d\n", (int)getpid());
	fflush(stdout);

	int rc = fork();
	if (rc < 0)
	{
		fprintf(stderr, "Can not create child process\n");
		exit(1);
	}
	else if (rc == 0)
	{
		printf("I am child process with PID: %d\n", (int)getpid());
	}
	else {
		printf("I am parent PID: %d with child %d\n", (int)getpid(), rc);
	}

	return 0;
}
