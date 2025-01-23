#include <stdio.h>
#include <stdlib.h>
#include "../common_threads.h"

volatile int done = 0;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c  = PTHREAD_COND_INITIALIZER;

void thr_exit() {
	Pthread_mutex_lock(&m);
  done = 1;
  Pthread_cond_signal(&c);
  Pthread_mutex_unlock(&m);
}

void *child(void *arg) {
	printf("child\n");
	thr_exit();
	return NULL;
}

void thr_join() {
	Pthread_mutex_lock(&m);
	while(done == 0)
		Pthread_cond_wait(&c, &m);
	Pthread_mutex_unlock(&m);
}

int main(int argc, char *argv[]) {
  printf("parent: begin\n");
  pthread_t p;
  Pthread_create(&p, NULL, child, NULL);
  thr_join();
  printf("parent: end\n");
  return 0; 
}

// Hold the lock when calling wait.
//  - assumes the lock is held when you call it
//  - releases said lock when putting the caller to sleep
//  - re-acquires the lock just before returning
