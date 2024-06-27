# pthread_mutex_init.md

## header 
`#include <pthread.h>`

## Syntax
```c 
int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
```

## Parameter
- `pthread_mutex_t`: Data type provided by the POSIX Threads (Pthreads) library for identifying the mutex.
- `pthread_mutexattr_t`: Structure attributes. If `NULL`, default attributes are used.


### Return value
- **0** if success

---
< [back to funtion overview](../function.md)

< [back to main](/)