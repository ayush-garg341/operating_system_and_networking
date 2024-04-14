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
        ;
}

void unlock(lock_t *lock){
    lock->flag = 0;
}

// Simplest type of lock to build and simply spins, using CPU cycles.
// Sequence of operation is performed atomically with help of hardware support.
// To work correctly, requires a pre-emptive scheduler as thread spinning on a CPU, will never relinquish it.
