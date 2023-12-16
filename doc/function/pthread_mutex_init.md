# pthread_mutex_init.md

### header 
`#include <pthread.h>`

### Syntax
```c 
int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
```

### Parameter
- `pthread_mutex_t`: - Datentyp von der POSIX-Thread-Bibliothek (Pthreads) bereitgestellt zur Identifizierung des Mutex.
- `pthread_mutexattr_t`: Struckturattributte bei `NULL` werden die Standardtattribute geladen.  

### Return value
- **0** if success

---
< [back to funtion overview](../function.md)