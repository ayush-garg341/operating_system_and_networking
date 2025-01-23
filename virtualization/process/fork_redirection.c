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
		int fd = open("output.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
		printf("FD returned by open: %d\n", fd);
		printf("I am child with PID: %d\n", (int)getpid());
		char *myargs[3];
		myargs[0] = strdup("wc");   // program: "wc" (word count)
		myargs[1] = strdup("fork_wait_exec.c"); // argument: file to count
		myargs[2] = NULL;           // marks end of array
		execvp(myargs[0], myargs);  // runs word count
		printf("this shouldn't print out");
	}
	else
	{
		int rc_wait = wait(NULL);
		printf("I am parent process with PID: %d and child PID: %d and rc_wait: %d\n", (int)getpid(), rc, rc_wait);
	}
	return 0;
}

// char *strdup(const char *s);
// This function returns a pointer to a null-terminated byte string, which is a duplicate of the string pointed to by s.
// It returns a pointer to the duplicated string s.
