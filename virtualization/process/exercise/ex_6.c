#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
	int rc = fork();
	int status;

	if(rc < 0)
	{
		fprintf(stderr, "Can not fork");
		exit(1);
	}
	if (rc == 0)
	{
		printf("hello\n");
		sleep(2);
		exit(2);
	}
	else
	{
		waitpid(rc, &status, 0);
		printf("Value of exit status is %d\n", status);
		if (WIFSIGNALED(status)){
			printf("Error\n");
		}
		else if (WEXITSTATUS(status)){
			printf("Exited Normally\n");
		}
		printf("goodbye\n");
	}
	return 0;
}

// Write a slight modification of the previous program, this time using waitpid() instead of wait(). When would waitpid() be useful?

// < -1: Wait for any child process whose process group ID is equal to the absolute value of pid.
// -1: Wait for any child process.
// 0: Wait for any child process whose process group ID is equal to that of the calling process.
// > 0: Wait for the child whose process ID is equal to the value of pid.
