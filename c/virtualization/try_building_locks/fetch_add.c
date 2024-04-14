int FetchAndAdd(int *ptr) {
    int old = *ptr;
    *ptr = old + 1;
    return old;
}

typedef struct __lock_t {
    int ticket;
    int turn;
} lock_t;


void lock_init(lock_t *lock) {
  lock->ticket = 0; 
  lock->turn = 0;
}

void lock(lock_t *lock) {
  int myturn = FetchAndAdd(&lock->ticket);
  while (lock->turn != myturn)
    ; // spin
}

void unlock(lock_t *lock) {
    lock->turn = lock->turn + 1;
}

// it ensures progress for all threads.
// - Once a thread is assigned its ticket value, it will be scheduled at some point in the future
