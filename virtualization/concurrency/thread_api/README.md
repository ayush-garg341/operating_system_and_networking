### Thread API guidelines
- **Keep it simple** - Above all else, any code to lock or signal between threads should be as simple as possible.
- **Minimize thread interactions** - Try to keep the number of ways in which threads interact to a minimum.
- **Initialize locks and condition variables** - Failure to do so will lead to code that sometimes works and sometimes fails in very strange ways.
- **Check your return codes** - Of course, in any C and UNIX programming you do, you should be checking each and every return code, and it’s true here as well.
- **Be careful with how you pass arguments to, and return values from, threads** - Any time you are passing a reference to a variable allocated on the stack, you are probably doing something wrong.
- **Each thread has its own stack** - Each thread has its own stack. Thus, if you have a locally-allocated variable inside of some function a thread is executing, it is essentially private to that thread; no other thread can (easily) access it. To share data between threads, the values must be in the heap or otherwise some locale that is globally accessible.
- **Always use condition variables to signal between threads** - While it is often tempting to use a simple flag, don’t do it.
- **Use manual pages** - In case of any doubt, do refer the man pages, highly informative.
