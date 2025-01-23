#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
	int x = 200;
	int rc = fork();
	if(rc < 0)
	{
		fprintf(stderr, "Fork call failed");
		exit(1);
	}
	else if(rc == 0)
	{
		printf("value of x in child: %d\n", x);
		x = 100;
	}
	else
	{
		// int rc_wait = wait(NULL);
		x = 300;
	}
	printf("Final value of x: %d\n",x);
	return 0;
}


// Write a program that calls fork(). Before calling fork(), have the main process access a variable (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process? What happens to the variable when both the child and parent change the value of x?

