int CompareAndSwap(int *ptr, int expected, int new){
    int orignal = *ptr;
    if (orignal == expected){
        *ptr = new;
    }

    return orignal;
}

typedef struct __lock_t{
    int flag;
} lock_t;

void init(lock_t *lock){
    lock->flag = 0;
}

void lock(lock_t *lock) {
    while (CompareAndSwap(&lock->flag, 0, 1) == 1)
        ; // spin
}

void unlock(lock_t *lock){
    lock->flag = 0;
}


