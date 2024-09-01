#include<stdio.h>

struct vec2 {
	int x;
	int y;
};

int scale_sum(int scalar, struct vec2 v)
{
	return scalar * v.x + scalar * v.y;
}

int sum(int xs[], int len)
{
	int sum = 0;
	for(int i=0; i < len; i++)
	{
		sum += xs[i];
	}

	return sum;
}

int main(void)
{
	struct vec2 v;
	v.x = 2;
	v.y = 3;
	int result = scale_sum(4, v);
	printf("%d\n", result);

	int r = scale_sum(4, (struct vec2){2, 3});
	printf("%d\n", r);

	int s = sum((int []){1, 2, 3, 4, 5, 6, 7}, 7);
	printf("%d\n", s);

	int *xs = (int []){1, 2, 3, 4, 5, 6, 7};
	struct vec2 t = (struct vec2){2, 3};
	return 0;
}
