### What are locks and why do we need them ?
- Let's say we would like to execute a series of instructions **atomically**, but due to presence of interrupts on single processor we couldn't.
- We solve the above problem with the help of primitive known as **LOCK**.
- We annotate source code with locks, putting them around critical section and make sure any such critical section executes atomically.

### Basic Idea
- Assume some critical section like
    ```
    balance = balance + 1
    ```
- To use a lock around this
    ```
    lock_t mutex; // some globally-allocated lock ’mutex’
    ...
    lock(&mutex);
    balance = balance + 1;
    unlock(&mutex);
    ```
- This lock variable (or just “lock” for short) holds the state of the lock at any instant in time.
    - Either **available** ( or free or unlocked ) or **acquired** ( or locked or held )
    - We could store other information in the data type as well, such as which thread holds the lock, or a queue for ordering lock acquisition, but information like that is hidden from the user of the lock.
- Threads are entities created by programmers but scheduled by OS.
- Locks yield some of that control back to the programmer; by putting a lock around a section of code, the programmer can guarantee that no more than a single thread can ever be active within that code.

### Pthread Locks
- Pthread library uses **mutex** ( mutual exclusion ) for lock.
- If one thread is in the critical section, it excludes the others from entering until it has completed the section.
    ```
    pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&lock);
    balance = balance + 1;
    pthread_mutex_unlock(&lock);
    ```

### How do we build a lock ?
- What hardware support is needed ?
- What OS support is needed ?

### Evaluating Locks
- Mututal Exclusion
    - Only one thread at a time in critical section
- Fairness
    - Each thread contending for lock gets a fair shot at acquiring it once it is free.
- Performance
    - Time overheads added by using the lock.
        - Single thread single cpu
        - Multiple thread single cpu
        - Multiple thread multiple cpu

### Controlling Interrupts
- One of the earliest solution to provide mutex was to disable interrupts for critical sections, this was invented for **single processor** systems.
    ```
    void lock() {
      DisableInterrupts();
    }
    void unlock() {
      EnableInterrupts();
    }
    ```
- Turning off interrupts ( via special hardware instruction ) before entering a critical section, ensures that code inside it will not be interrupted and thus will execute as if it were atomic. When finished enable the interrupts and program proceeds as usual.
- Dealing with such interrupts requires previliged action. ( can be abused by calling threads i.e neven calls unlock and hence monopolize the cpu and os never regains control )

### Failed attempt: Just using loads/stores
