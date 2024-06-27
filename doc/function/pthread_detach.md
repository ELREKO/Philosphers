# pthread_detach
--> [compaer with join](join_detach.md)

## header 
`#include <pthread.h>`

## Syntax
```c 
int pthread_detach(pthread_t thread);
```

## Parameter

- `pthread_t`: Data type provided by the POSIX Threads (Pthreads) library for identifying the thread.

## Particularities

- Suitable for background tasks that do not require synchronization.
- No need for `pthread_join`.
- Resources are automatically released after completion.


## Return value
- **0** if success

---
< [back to funtion overview](../function.md)

< [back to main](/)