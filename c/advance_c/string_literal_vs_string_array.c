#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*literal;
	char	array[] = "I am a string array";
	char	*s;

	literal = "I am a string literal";
	s = strdup(literal);
	// Will create a copy of string on heap so editable
	array[0] = '#';
	s[0] = '#';
	// literal[0] = '#';
	// won't give compile error but segmentation error on running the program. ( It's in read-only section )
	printf("%s\n", array);
	printf("%s\n", s);
	return (0);
}

// gcc <file>
// objdump -h a.out
// objdump -s -j .text a.out ( function definitions )
// objdump -s -j .data a.out ( global variable and static variable )
// objdump -s -j .rodata a.out ( read only data )
