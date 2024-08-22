#include<stdio.h>
#include<stdbool.h>

// 1 << 0 -> 1
// 1 << 1 -> 10
// 1 << 2 -> 100

/*typedef unsigned int t_flag;*/
/*#define FLAG_A (1 << 0)*/
/*#define FLAG_B (1 << 1)*/
/*#define FLAG_C (1 << 2)*/

typedef enum {
    FLAG_A = (1 << 0),
    FLAG_B = (1 << 1),
    FLAG_C = (1 << 2)
} t_flag;

int f(int x, t_flag flags)
{
    if(flags & FLAG_A)
    {
        printf("Flag A found \n");
        x += x;
        flags &= -FLAG_A;
    }
    if(flags & FLAG_B)
    {
        printf("Flag B found \n");
        x *= x;
    }
    if(flags & FLAG_C)
    {
        printf("Flag C found \n");
        x -= x;
    }

    printf("flag = %d\n", flags);

    return x;
}

int main(void)
{
    printf("%d\n", f(12, 0));
    printf("%d\n", f(12, FLAG_A));
    printf("%d\n", f(12, FLAG_B | FLAG_C));
    printf("%d\n", f(12, FLAG_B));
    return 0;
}

// This technique is used in many standard library where there are lots of options to pass as function arguments.
