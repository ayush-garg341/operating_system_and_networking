#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
	int rc = fork();

	if(rc < 0)
	{
		fprintf(stderr, "Can not fork");
		exit(1);
	}
	if (rc == 0)
	{
		printf("hello\n");
		int pid = wait(NULL);
		printf("Wait pid in child PID: %d\n", pid);
	}
	else
	{
		int rc_wait = wait(NULL);
		printf("goodbye\n");
	}
	return 0;
}

// Now write a program that uses wait() to wait for the child process to finish in the parent. What does wait() return? What happens if you use wait() in the child?
