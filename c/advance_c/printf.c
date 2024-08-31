#include <stdio.h>

int	main(void)
{
	int		a;
	size_t	size;
	FILE	*f;
	char	buff[256] = {0};

	a = 1;
	printf("%d\n", -32);
	printf("%u\n", 32);
	printf("%f\n", 42.42);
	printf("%p\n", &a);
	printf("%c\n", 'a');
	printf("%s\n", "Hello");
	printf("%%\n");
	printf("%e\n", 1234554433.23123534534);
	printf("%g\n", 1.2);
	printf("###%5d###\n", 32);
	printf("###% d###\n", 32);
	printf("###% d###\n", -32);
	printf("###%-5d###\n", 32);
	printf("%.2f\n", 42.4223232435433);
	printf("###%*d###\n", 10, -32);
	printf("###%*.*f###\n", 10, 2, -32.1243233434);
	size = 123412;
	printf("%zu\n", size);
	f = fopen("foo", "w");
	fprintf(f, "%d, %d\n", 3, 2);
	fclose(f);
	sprintf(buff, "%d, %d", 3, 2);
	// snprintf we declare the size also so no buffer overflow problem. ( trim the extra part )
	printf("size of buff is %zu\n", sizeof buff);
	printf("%c\n", buff[0]);
	printf("%c\n", buff[1]);
	printf("%c\n", buff[2]);
	printf("%c\n", buff[3]);
	printf("#%s#\n", buff);
	return (0);
}

// %ld -> for long int
// %lld -> for long long int
// %hd -> for short int
