#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"

typedef struct __counter_t {
    int value;
} counter_t;

void init(counter_t *c) {
    c->value = 0;
}

void increment(counter_t *c) {
    c->value++;
}

void decrement(counter_t *c) {
    c->value--;
}

int get(counter_t *c) {
    return c->value;
}

int main(int argc, char *argv[])
{
    counter_t *counter = malloc(sizeof(counter_t));
	double t = GetTime();
    init(counter);
    int max_count = 40000000;
    for(int i = 1; i <= max_count; i++)
    {
        increment(counter);
    }
    printf("Final value is %d\n", get(counter));
    printf("Time taken is %f\n", GetTime() - t);
    free(counter);
    return 0;
}

