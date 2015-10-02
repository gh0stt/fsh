#include <stdlib.h>
#include <string.h>
#include <fsh/fsh_builtins.h>
#include <fsh/builtins/fsh_exit.h>
struct fsh_builtins {
    char *name;
    fsh_builtin_function function;
};

struct fsh_builtins fsh_builtin_all[] = {
    {
        .name = "exit",
        .function = fsh_exit
    }
};


fsh_builtin_function lookup_fsh_builtin_func(char *name)
{
    if (!name) {
        return NULL;
    }
    if (name[0] == '/') {
        return NULL;
    }
    for(int i = 0; i < (int) (sizeof(fsh_builtin_all)/sizeof(fsh_builtin_all[0])); i++) {
        if (strcmp(name, fsh_builtin_all[i].name) == 0) {
            return fsh_builtin_all[i].function;
        }
    }
    return NULL;
}

