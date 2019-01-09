#include <stdio.h>
#include "dbg.h"
#include <dlfcn.h>
typedef int(*lib_function)(const char *msg);

int main (int argc, char *argv[])
{int rc=0;
check(argc=4, "Usage: ex29 libex29.so function data");
char *lib_file=argv[1]; // file name
char *func_to_run=argv[2];
char *data=argv[3];

void *lib=dlopen(lib_file, RTLD_NOW);
check(lib!=NULL, "FAIL to open lib %s, %s", lib_file, dlerror());
lib_function func=dlsym(lib, func_to_run);
check(func!=NULL, "FAIL to find %s function in the lib %s: %s", func_to_run, lib_file, dlerror());

rc=func(data);
check(rc==0, "Function %s retun %d for data: %s", func_to_run, rc, data);
rc=dlclose(lib);
check(rc==0, "FAIL to close %s", lib_file);

return 0;
error:
    return 1;

}
