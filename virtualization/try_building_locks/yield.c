// Hardware support got us pretty far: working locks, and even (as with the case of the ticket lock) fairness in lock acquisition.
// what to do when a context switch occurs in a critical section,
// and threads start to spin endlessly, waiting for the interrupted (lock-holding) thread to be run again?

#include <stdio.h>

void yield(){
    printf("Giving up the CPU");
}
int TestAndSet(int *old_ptr, int new){
    int old = *old_ptr;
    *old_ptr = new;
    return old;
}


typedef struct __lock_t{
    int flag;
} lock_t;

void init(lock_t *lock){
    lock->flag = 0;
}

void lock(lock_t *lock){
    while(TestAndSet(&lock->flag, 1) == 1)
        yield(); // give up the CPU. Assumeing yield gives up the CPU
}

void unlock(lock_t *lock){
    lock->flag = 0;
}

