#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(int argc, char *argv[])
{
	if(argc != 2){
		fprintf(stderr, "usage: mem <value>\n");
		exit(1);
	}
	int *p;
	p = malloc(sizeof(int));
	assert(p != NULL);
	*p = atoi(argv[1]);
	while(1) {
		Spin(1);
		*p = *p + 1;
		printf("(%d) value of p: %d\n", getpid(), *p);
	}
	return 0;
}

//  gcc -o mem mem.c -Wall
//  ./mem 0 & ./mem 0 &
//  For the above example to work, you need to make sure address-space randomization is disabled;
//  randomization, as it turns out, can be a good defense against certain kinds of security flaws.
//  you can configure ASLR in Linux using the /proc/sys/kernel/randomize_va_space interface:-
//  https://askubuntu.com/questions/318315/how-can-i-temporarily-disable-aslr-address-space-layout-randomization
//  		0 – No randomization. Everything is static.
//  		1 – Conservative randomization. Shared libraries, stack, mmap(), VDSO and heap are randomized.
//  		2 - Full randomization. In addition to elements listed in the previous point, memory managed through brk() is also randomized.
//  echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
//  echo 2 | sudo tee /proc/sys/kernel/randomize_va_space
