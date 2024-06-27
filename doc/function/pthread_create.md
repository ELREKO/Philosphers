# pthread_create
## header 
`#include <pthread.h>`

## Syntax
```c 
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
```

## Parameters

- `pthread_t`: Data type provided by the POSIX Threads (Pthreads) library for identifying the thread.
- `const pthread_attr_t *`: If **NULL**, default attributes are used. Otherwise, specify attributes using `pthread_attr_t`, but this is not allowed as an external function!
- `void *(*start_routine)(void *)`: A pointer to the function that the thread should execute. This function must take a pointer to void as an argument and return a pointer to void.
- `void *arg`: A pointer to arguments to be passed to the start function. This can be NULL if no arguments are needed.

## Rückgabewert 
- **0** bei success

---
< [back to funtion overview](../function.md)

< [back to main](/)