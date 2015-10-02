#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fsh/fsh_builtins.h>
#include <fsh/fsh_prompt.h>

int main()
{
    char *command_line;
    char prompt[1024];
    fsh_builtin_function fsh_builtin_func;
    set_prompt(prompt);
    while((command_line = readline(prompt)) != NULL) {
        if (command_line[0] != 0) {
            add_history(command_line);
        }
        /* Need to parse the command_line into commands, pipes, etc */
        fsh_builtin_func = lookup_fsh_builtin_func(command_line);
        fsh_builtin_func(0, NULL);
    }
    return 1;
}
