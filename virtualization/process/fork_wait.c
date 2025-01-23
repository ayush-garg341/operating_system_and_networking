#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	printf("Hello world %d\n", (int)getpid());
	fflush(stdout);

	int rc = fork();
	if(rc < 0)
	{
		fprintf(stderr, "Can not create child process");
		exit(1);
	}
	else if(rc == 0)
	{
		printf("I am child with PID: %d\n", (int)getpid());
	}
	else{
		int rc_wait = wait(NULL);
		printf("I am parent process with PID: %d and child PID: %d and rc_wait: %d\n", (int)getpid(), rc, rc_wait);
	}
	return 0;
}
