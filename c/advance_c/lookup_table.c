#include <stdio.h>

enum		foo
{
	foo_2 = 0,
	foo_3,
	foo_4,
};

static int	squares[] = {
	9,
	4,
	16,
};

#define FLAG_FOO 1 << 10

static char	case_convert[] = {['a'] = 'A', ['b'] = 'B', ['c'] = 'C',
		[FLAG_FOO] = 234};

int	main(void)
{
	printf("%d\n", squares[foo_2]);
	printf("%d\n", squares[foo_3]);
	printf("%d\n", squares[foo_4]);
	printf("%c\n", case_convert['a']);
	printf("%c\n", case_convert['b']);
	printf("%c\n", case_convert['c']);
	printf("%zu\n", sizeof case_convert);
	return (0);
}

// How to calculate the size of case convert??
// The largest index used in this array is FLAG_FOO, which is 1024.
// The array needs to have at least 1025 elements (indices 0 through 1024).
// The size of the array will be 1025 bytes since char is 1 byte and the array must accommodate all elements from index 0 to 1024.

// How the char array case_convert store integer value 234?
// the char data type is typically 1 byte in size,
// and it can hold integer values from 0 to 255 if it's an unsigned char
// or from -128 to 127 if it's a signed char.
// The value 234 is within the range that a char can hold as an unsigned value,
// which is why it can be stored in a char array.

// It is also useful in cases where we want to map each character to some function and then take character from stdin or some other input.
