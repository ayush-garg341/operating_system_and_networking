#include<stdio.h>
#include<stdlib.h>
#include<alloca.h>

int main(void)
{
	int length = 12;
	int xs[length]; // This memory gets allocated on stack, harmful when taking user input for lenght and might give seg error.
	for(int i = 0; i < length; i++)
	{
		xs[i] = i * i;
	}

	for(int i = 0; i < length; i++)
	{
		printf("%d\n", xs[i]);
	}

	printf("\n");

	int *xy = malloc(length * sizeof(int)); // Allocates on heap which is much bigger than stack.
	for(int i = 0; i < length; i++)
	{
		xy[i] = i * i;
	}

	for(int i = 0; i < length; i++)
	{
		printf("%d\n", xy[i]);
	}

	free(xy);

	printf("\n");

	int *xz = alloca(length * sizeof(int)); // Allocates on stack and does not need to be freed manually unlike malloc, it's memory address can not be returned from function call unlike malloc. It can only be used in a function but can not be returned.
	for(int i = 0; i < length; i++)
	{
		xz[i] = i * i;
	}

	for(int i = 0; i < length; i++)
	{
		printf("%d\n", xz[i]);
	}


	return 0;
}
