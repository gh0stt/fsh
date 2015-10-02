#ifndef FSH_BUILTINS_H
#define FSH_BUILTINS_H

typedef int (*fsh_builtin_function)(int, char **);
fsh_builtin_function lookup_fsh_builtin_func(char *name);

#endif
