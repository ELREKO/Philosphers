# pthread_join
--> [compaer with detach](join_detach.md)

### header 
`#include <pthread.h>`

### Syntax
```c 
int pthread_join(pthread_t thread, void **retval);
```

### Parameter
- `pthread_t`: - Datentyp von der POSIX-Thread-Bibliothek (Pthreads) bereitgestellt zur Identifizierung des Threads. 
- `void **retval` Zeiger auf Rückgabewert --> sieh Bsp.

### Rückgabewert 
- **0** bei success

### Example
[soucecode](../../src_exaamples/pthhread_join.c)


---
< [back to funtion overview](../function.md)