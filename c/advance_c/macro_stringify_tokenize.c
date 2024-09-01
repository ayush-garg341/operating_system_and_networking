#include<stdio.h>

#define FOO(x, y) printf("%s + %s = %d\n", #x, #y, (x) + (y))

// See the use of # to replace x with literal first and y with literal second.

#define PREFIX(var_name) new_##var_name

#define GENERIC_ADD_FUNC(type) \
	type add_##type(type x, type y) { \
		return x + y; \
	}

GENERIC_ADD_FUNC(int)
GENERIC_ADD_FUNC(float)
GENERIC_ADD_FUNC(long)

int main(void)
{
	int first = 123;
	int second = 3245;

	FOO(first, second);

	int PREFIX(foo) = 123;
	printf("%d\n", new_foo);

	printf("%d\n", add_int(1, 2));
	printf("%f\n", add_float(1.123, 2.234));
	printf("%ld\n", add_long(1L, 2L));

	return 0;
}
