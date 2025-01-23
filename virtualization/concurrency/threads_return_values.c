#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include "common_threads.h"


typedef struct {
    int x;
    int y;
} myarg_t;

typedef struct {
    int a;
    int b;
} myret_t;

void *myThread(void *args)
{
    myret_t *rvals = malloc(sizeof(myret_t));
    rvals->a = 1;
    rvals->b = 2;
    return (void *) rvals;
}

int main(int argc, char *argv[]){
    pthread_t p;
    myret_t *rvals;
    myarg_t args = {10, 20};
    Pthread_create(&p, NULL, myThread, &args);
    Pthread_join(p, (void **) &rvals);

    printf("returned %d %d\n", rvals->a, rvals->b);
    free(rvals);
    return 0;
}
