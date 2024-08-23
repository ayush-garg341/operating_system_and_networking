#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

void	*my_memset(void *data, uint8_t c, size_t n)
{
	uint8_t	*data_as_bytes;

	printf("total size of array is: %zu bytes\n", n);
	data_as_bytes = (uint8_t *)data;
	printf("Setting each byte value to c: %u\n", c);
	for (size_t i = 0; i < n; i++)
	{
		data_as_bytes[i] = c;
	}
	return (data);
}

void	*map(void *xs, size_t n, size_t size, void (*f)(void *))
{
	uint8_t	*xs_as_bytes;

	// xs - an array of ints ( 4 bytes ),
	flatten as individual pieces of 1 byte each.xs_as_bytes = (uint8_t *)xs;
	for (size_t i = 0; i < n; i++)
	{
		printf("i*size is %zu\n", i * size);
		f(&xs_as_bytes[i * size]);
	}
	return (xs);
}

void	square(void *x)
{
	int	*p;

	// Reading as an int of 4 bytes.
	p = x;
	printf("decoded integer %d\n", *p);
	*p = *p * *p;
}

int	main(void)
{
	int		a;
	void	*p;
	int		xs[5] = {1, 2, 3, 4, 5};

	a = 3;
	p = &a;
	printf("%p\n", p);
	printf("%d\n", *(int *)p);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", xs[i]);
	}
	printf("\n");
	map(xs, 5, sizeof(int), square);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", xs[i]);
	}
	printf("\n");
	my_memset(xs, 2, sizeof(xs));
	for (int i = 0; i < 5; i++)
	{
		// Reading modified array values as an integer ( 4 bytes at a time )
		printf("%d ", xs[i]);
	}
	printf("\n");
}

// A byte value is an unsigned or signed integer value that fits in an 8-bit byte.
// Integer Interpretation:
// Suppose your system uses 4 bytes (32 bits) for an int.
// When you fill the memory with the byte 0x02,
// each 4-byte integer in xs will be composed of four 0x02 bytes.
// The value of such a 4-byte integer will be:
// 0x02020202 (in hexadecimal)
// This converts to 33686018 in decimal.

// Void pointers allows us to decode large blob of memory as anything ( ints,
// uint8_t, char ) during runtime without the need of plymorphism.
