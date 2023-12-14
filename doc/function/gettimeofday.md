# gettimeofday
### header
- `#include <sys/time.h>`

### Syntax
```c 
int gettimeofday(struct timeval *tv, struct timezone *tz);
```
### Prameter

 - `struct timeval` -> enthält secunden und Millisekunden
### Example time messering z.b. von Programmen
[soucecode](../../src_exaamples/gettimeofday.c)

---
< [back to funtion overview](../function.md)