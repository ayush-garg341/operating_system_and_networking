#include<stdio.h>
#include<stdlib.h>
#include "../common.h"
#include "../common_threads.h"

typedef struct __counter_t {
  int             value;
  pthread_mutex_t lock;
} counter_t;

void init(counter_t *c) {
  c->value = 0;
  Pthread_mutex_init(&c->lock);
}

void increment(counter_t *c) {
  Pthread_mutex_lock(&c->lock);
  c->value++;
  Pthread_mutex_unlock(&c->lock);
}

void decrement(counter_t *c) {
  Pthread_mutex_lock(&c->lock);
  c->value--;
  Pthread_mutex_unlock(&c->lock);
}

int get(counter_t *c) {
  Pthread_mutex_lock(&c->lock);
  int rc = c->value;
  Pthread_mutex_unlock(&c->lock);
  return rc;
}

struct argument {
    counter_t *counter;
    int count;
};

void *increment_thread(void* arguments)
{
    struct argument* args = (struct argument *) arguments;
    counter_t *counter = args->counter;
    int max_count = args->count;
    for(int i = 1; i <= max_count; i++)
    {
        increment(counter);
    }
    return NULL;
}


int main(int argc, char *argv[])
{
    int NUM_THREADS = 4;
    counter_t *counter = malloc(sizeof(counter_t));
	double t = GetTime();
    init(counter);
    pthread_t threads[NUM_THREADS];
    struct argument args;
    args.counter = counter;
    args.count = 250000;
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment_thread, (void *) &args);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Final value is %d\n", get(counter));
    printf("Time taken is %f\n", GetTime() - t);
    free(counter);
    return 0;
}
