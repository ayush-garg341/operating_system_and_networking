#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include <fcntl.h>
#include <assert.h>

int main(int argc, char *argv[])
{
	printf("Hello world PID: %d\n", (int)getpid());
	fflush(stdout);

	int rc = fork();
	if(rc < 0)
	{
		printf("Can not create child process");
		exit(1);
	}
	else if(rc == 0)
	{
		printf("Stdout file descriptors: %d\n", STDOUT_FILENO);
		close(STDOUT_FILENO);
		printf("Can not print as std output fd is closed");
		printf("I am child with PID: %d\n", (int)getpid());
	}
	else
	{
		int rc_wait = wait(NULL);
		printf("I am parent process with PID: %d and child PID: %d and rc_wait: %d\n", (int)getpid(), rc, rc_wait);
	}
	return 0;
}

// Write a program that creates a child process, and then in the child closes standard output (STDOUT_FILENO). What happens if the child calls printf() to print some output after closing the descriptor?
