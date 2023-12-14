# pthread_detach
--> [compaer with join](join_detach.md)

### header 
`#include <pthread.h>`

### Syntax
```c 
int pthread_detach(pthread_t thread);
```

### Parameter
- `pthread_t`: - Datentyp von der POSIX-Thread-Bibliothek (Pthreads) bereitgestellt zur Identifizierung des Threads. 

### Particularities
- Geignet für Hintergrundtasks die keine Syncronisation benötigen
- Kein `pthread_join` erforderlich
- Resourcen werden nach Beendigung wieder frei gegeben!  

### Return value
- **0** if success



---
< [back to funtion overview](../function.md)