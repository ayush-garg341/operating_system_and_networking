#include<stdio.h>
#include<stdlib.h>
#include "../common.h"
#include "../common_threads.h"

#define NUMCPUS 4

typedef struct __counter_t {
  int global;                     // global count
  pthread_mutex_t glock;          // global lock
  int local[NUMCPUS];             // per-CPU count
  pthread_mutex_t llock[NUMCPUS]; // ... and locks
  int threshold;                  // update frequency
} counter_t;

void init(counter_t *c, int threshold) {
  c->threshold = threshold;
  c->global = 0;
  pthread_mutex_init(&c->glock, NULL);
  int i;
  for (i = 0;i < NUMCPUS; i++){
    c->local[i] = 0;
    pthread_mutex_init(&c->llock[i], NULL);
 }
}

void update(counter_t *c, int threadID, int amt) {
  int cpu = threadID % NUMCPUS;
  c->local[cpu] += amt;
  if (c->local[cpu] >= c->threshold) {
    pthread_mutex_lock(&c->glock);
    c->global += c->local[cpu];
    pthread_mutex_unlock(&c->glock);
    c->local[cpu] = 0;
  }
}

int get(counter_t *c) {
  pthread_mutex_lock(&c->glock);
  int val = c->global;
  pthread_mutex_unlock(&c->glock);
  return val;
}

struct argument {
    counter_t *counter;
    int count;
    int idx;
};


void *increment_thread(void *arguments)
{
    struct argument* args = (struct argument *) arguments;
    counter_t *counter = args->counter;
    int max_count = args->count;
    int idx = args->idx;
    for(int i = 1; i <= max_count; i++)
    {
        update(counter, idx, 1);
    }
    return NULL;
}


int main(int argc, char *argv[])
{
    struct argument args[NUMCPUS];
    counter_t *counter = malloc(sizeof(counter_t));
    init(counter, 10000);
    for(int i = 0; i < NUMCPUS; i++)
    {
        args[i].counter = counter;
        args[i].count = 10000000;
        args[i].idx = i;
    }
	double t = GetTime();
    pthread_t threads[NUMCPUS];
    for (int i = 0; i < NUMCPUS; i++) {
        pthread_create(&threads[i], NULL, increment_thread, (void *) &args[i]);
    }
    for (int i = 0; i < NUMCPUS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Final value is %d\n", get(counter));
    printf("Time taken is %f\n", GetTime() - t);
    free(counter);
    return 0;
}
