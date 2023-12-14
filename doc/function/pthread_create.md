# pthread_create
### header 
`#include <pthread.h>`

### Syntax
```c 
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
```

### Parameter
- `pthread_t`: - Datentyp von der POSIX-Thread-Bibliothek (Pthreads) bereitgestellt zur Identifizierung des Threads. 
- `const pthread_attr_t`: bei **NULL** verwendung der Standartatributte -> andernfalls mit `pthread_attr_t` setzen der Atribute -> hier aber als externe Funktion nicht erlaubt! 
- `void *(*start_routine)(void *)`: Ein Zeiger auf die Funktion, die der Thread ausführen soll. Diese Funktion muss einen Zeiger auf void als Argument nehmen und einen Zeiger auf void zurückgeben.
- `*void arg`: Ein Zeiger auf Argumente, die an die Startfunktion übergeben werden sollen. Dies kann NULL sein, wenn keine Argumente erforderlich sind.

### Rückgabewert 
- **0** bei success

---
< [back to funtion overview](../function.md)