#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<assert.h>
#include<string.h>

int main(int argc, char *argv[])
{
	close(STDOUT_FILENO);
	int fd = open("exercise.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
  assert(fd >= 0);

	int rc = fork();
	if(rc < 0)
	{
		fprintf(stderr, "Can not fork");
		exit(1);
	}
	else if(rc == 0)
	{
		const char s[] = "Child: She was aware that things could go wrong. In fact, she had trained her entire life in anticipation that things would go wrong one day. She had quiet confidence as she started to see that this was the day that all her training would be worthwhile and useful. At this point, she had no idea just how wrong everything would go that day.\n";
		for(int i = 0; i < 100; i++){
			char buffer[350];
			sprintf(buffer, s);
			int wb = write(fd, buffer, strlen(buffer));
			assert(wb == strlen(buffer));
		}
	}
	else
	{
		// int rc_wait = wait(NULL);
		const char s[] = "Parent: She was aware that things could go wrong. In fact, she had trained her entire life in anticipation that things would go wrong one day. She had quiet confidence as she started to see that this was the day that all her training would be worthwhile and useful. At this point, she had no idea just how wrong everything would go that day.\n";
		for(int i = 0; i < 100; i++){
			char parent_buffer[350];
			sprintf(parent_buffer, s);
			int wb = write(fd, parent_buffer, strlen(parent_buffer));
			assert(wb == strlen(parent_buffer));
		}
	}
	return 0;
}


// Write a program that opens a file (with the open() system call) and then calls fork() to create a new process. Can both the child and parent access the file descriptor returned by open()? What happens when they are writing to the file concurrently, i.e., at the same time?
