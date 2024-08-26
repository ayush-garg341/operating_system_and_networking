#include <stdio.h>
#include <string.h>

union		Data
{
	int		i;
	float	f;
	char	str[20];
};

int	main(void)
{
	union Data	data;

	data.i = 10;
	printf("data.i : %d\n", data.i);
	data.f = 220.5;
	printf("data.f : %f\n", data.f);
	strcpy(data.str, "C Programming");
	printf("data.str : %s\n", data.str);
	return (0);
}

// In a union, all members share the same memory location.
// This means that a union can store different types of data in the same memory space,
// but only one type at a time.

// Unions are useful when you need to work with different types of data,
// but only one type at a time, such as in low-level programming,
// embedded systems, or when dealing with hardware registers.
