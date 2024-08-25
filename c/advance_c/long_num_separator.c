#include <stdio.h>

int	main(void)
{
	int	x;

	x = 1'000'000;
	printf("%d\n", x);
}

// long number separator -> _ in languages like python, java, rust, c#
// But in c we do not use _, we use ' for number separation
// gcc -std=c2x <program_name.c>
