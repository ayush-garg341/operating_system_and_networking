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
	}
	else
	{
		int rc_wait = wait(NULL);
		printf("goodbye\n");
	}
	return 0;
}

// Write another program using fork(). The child process should print “hello”; the parent process should print “goodbye”. You should try to ensure that the child process always prints first; can you do this without calling wait() in the parent?
