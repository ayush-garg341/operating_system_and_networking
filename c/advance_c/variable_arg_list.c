#include <stdarg.h>
#include <stdio.h>

int	sum_all(int count, ...)
{
	va_list	ap;
	int		sum;

	va_start(ap, count);
	sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum += va_arg(ap, int);
	}
	return (sum);
}

int	main(void)
{
	printf("%d, %d\n", 1, 2);
	printf("%d\n", sum_all(3, 4, 5, 6));
	return (0);
}
