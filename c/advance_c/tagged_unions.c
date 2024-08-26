#include <stdbool.h>
#include <stdio.h>

enum			tag
{
	TAG_BOOL,
	TAG_INT,
	TAG_FLOAT,
};

struct			dynamic
{
	enum tag	tag;
	union
	{
		bool	b;
		int		i;
		float	f;
	} value;
};

int	main(void)
{
	struct dynamic	d;

	printf("%zu\n", sizeof d);
	d.tag = TAG_INT;
	d.value.i = 42;
	switch (d.tag)
	{
	case TAG_BOOL:
		printf("bool: %d\n", d.value.b);
		break ;
	case TAG_INT:
		printf("int: %d\n", d.value.i);
		break ;
	case TAG_FLOAT:
		printf("float: %f\n", d.value.f);
		break ;
	}
	return (0);
}

// Way to have dynamic typing in C.
// Size of struct dynamic with union inside it.
// The size of an enum in C is typically the size of an int which is usually 4 bytes.
// Size of enum tag: 4 bytes
// Size of union value: 4 bytes (since the largest member is 4 bytes)

// The C compiler may add padding to ensure that the structure's members are aligned correctly in memory.
// This is often done to match the natural alignment of the system which can vary between platforms.

// Size changes when replacing union with struct.
/*struct dynamic {*/
/*enum tag tag; // Typically 4 bytes*/
/*struct {*/
/*bool b;   // Typically 1 byte*/
/*int i;    // Typically 4 bytes*/
/*float f;  // Typically 4 bytes*/
/*} value;*/
/*};*/

// enum tag tag: Typically 4 bytes.
// struct value:
// bool b: Typically 1 byte.
// Padding after bool: 3 bytes of padding are likely added after bool to align the int to a 4-byte boundary.
// int i: Typically 4 bytes.
// float f: Typically 4 bytes.
// Total size of the inner struct: 1 byte (b) + 3 bytes (padding) + 4 bytes (i)
// + 4 bytes (f) = 12 bytes.
// Total Size of struct dynamic: 4 bytes (enum tag)
// + 12 bytes (struct value) = 16 bytes.
