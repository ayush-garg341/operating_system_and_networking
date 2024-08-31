#include <stdio.h>

#define FOO 2

#define ADD(x, y) x + y

// Add parenthesis to avoid literal text replacement and get correct expected result.

#define WRONG_MUL(x, y) (x * y)

#define MUL(x, y) ((x) * (y))

#define SUM_RANGE(start, end){ \
	int sum = 0; \
	for (int x = (start); x < (end); x++) \
		sum += x; \
	printf("sum: %d\n", sum); \
} \

int	main(void)
{
	int	x;
	int	y;
	int	z;
	int	a;
	int sum = 0;

	x = ADD(2, 3);
	y = 5 * ADD(2, 3);
	// expected 15 but actual 13 because literal text replacement
	printf("%d, %d\n", x, y);
	z = 5 * MUL(2, 3 + 2);
	printf("%d\n", z);
	a = 5 * WRONG_MUL(2, 3 + 2);
	// Wrong output as a result of literal text replacement
	printf("%d\n", a);
	SUM_RANGE(2, 10); // Have to scope the variables in macro otherwise will give error as we already have sum in main
	return (0);
}
