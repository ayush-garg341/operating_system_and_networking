typedef struct __lock_t {
    int flag;
} lock_t;

void init(lock_t *mutext){
    mutext->flag = 0;
}

void lock(lock_t *mutex){
    while(mutex->flag == 1)
        ;
    mutex->flag = 1;
}

void unlock(lock_t *mutex){
    mutex->flag = 0;
}

// Two issues
// - Correctness problem ( two threads can enter in critical section )
// - Performance problem ( waiting in while loop, waste cpu cycles )
