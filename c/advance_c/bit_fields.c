// A way to say how many bits does a field of a struct take in memory. Useful when you are trying to parse  information from a binary source. ( like IP address )
// Bit-fields are used to store data in a specific number of bits rather than the standard size of the data type.

#include <stdio.h>

// | 4 bits | 4 bits | 1 bit | 7 bits |

struct	foo
{
	int first_4 : 4;
	int next_4 : 4;
	int alone : 1;
	int rest : 7;
};

int	main(void)
{
	struct foo	f;

	printf("%zu bytes\n", sizeof(struct foo));
	f.first_4 = 2;
	f.next_4 = 4;
	f.alone = 1;
	/*int fd = open(...);*/
	/*read(fd, f, sizeof f);*/
	return (0);
}

// How to calculate the size of above struct?
// int first_4 : 4 and int next_4 : 4:
// These fields together use 4 + 4 = 8 bits, which fits within 1 byte (8 bits).
// They can be packed into a single byte.
// int alone : 1 and int rest : 7:
// These fields use 1 + 7 = 8 bits, which also fits within 1 byte (8 bits).
// They can be packed into another single byte.
// The size of struct foo will be 2 bytes.

// The reason your compiler is returning 4 bytes as the size of struct foo is likely due to memory alignment requirements. Let's explore why this happens.
// Memory Alignment and Padding
// Memory Alignment: Most compilers align data in memory according to the architecture of the machine. For example on many systems,
// int types (even if they are bit-fields) are aligned on 4-byte boundaries. This means that even if the bit-fields only need 2 bytes,
// the compiler might add padding to ensure that the structure is aligned correctly in memory.
// Padding: If the total size of the bit-fields is less than the natural alignment boundary of an int (which is 4 bytes on many systems) the compiler may pad the structure to make it 4 bytes.
