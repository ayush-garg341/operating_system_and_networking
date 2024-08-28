#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = 32;
	b = 0xffaa33;
	c = 0755;
	d = 0b01010101010;
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%x\n", b);
	printf("%o\n", c);
	printf("%d\n", d);
	printf("%b\n", d);
	return (0);
}
