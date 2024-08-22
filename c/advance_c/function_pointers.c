#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int (*t_my_func) (int, int);

int foo(int x, int y)
{
    return x + y;
}

bool predicate(int x)
{
    return x % 2 == 0;
}

void print_if(int xs[10], bool (*predicate)(int))
{
    for(int i = 0; i < 10; i++)
    {
        if(predicate(xs[i]))
        {
            printf("%d ", xs[i]);
        }
    }

    printf("\n");
}

int compare(const void *x1, const void *x2)
{
    return (*(int *)x1) - (*(int *)x2);
}

int main(void)
{
    int xs[] = {50, 1, 3, 4, 2, 5, 8, 9, 10, 7, 6};

    int (*f)( int, int ) = foo;
    printf("%d\n", f(3, 4));

    t_my_func my_func = foo;
    printf("%d\n", my_func(3, 4));

    print_if(xs, predicate);

    // Similarly we pass fun. in std lib qsort compare func.
    qsort(xs, 10, sizeof(int), compare);
    for(int i = 0; i < 10; i++){
        printf("%d ", xs[i]);
    }

    return 0;
}

// Function pointers allows generic types in c
