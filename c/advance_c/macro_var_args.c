#include<stdio.h>

#define PRINTF_LOOP(iterations, ...){ \
	for(int i = 0; i < iterations; i++) \
		printf(__VA_ARGS__); \
}

int main(void)
{
	PRINTF_LOOP(3, "Hello %d %s\n", 32, "bar");
	printf("============\n");
	printf("Hello %d %s\n", 32, "bar");

	return 0;
}
