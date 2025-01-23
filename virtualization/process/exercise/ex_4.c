#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

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
		printf("I am child with PID: %d\n", (int)getpid());
		fflush(stdout);
		char *myargs[2];
		myargs[0] = strdup("ls");
		myargs[1] = NULL;
		execvp(myargs[0], myargs); //without using p in function call, have to pass absolute or relative path of executable but with p, will find executable by itself
		printf("this shouldn't print out");
	}
	else
	{
		int rc_wait = wait(NULL);
		printf("I am parent process with PID: %d and child PID: %d and rc_wait: %d\n", (int)getpid(), rc, rc_wait);
	}
	return 0;
}

// Write a program that calls fork() and then calls some form of exec() to run the program /bin/ls. See if you can try all of the variants of exec(), including (on Linux) execl(), execle(), execlp(), execv(), execvp(), and execvpe(). Why do you think there are so many variants of the same basic call?
