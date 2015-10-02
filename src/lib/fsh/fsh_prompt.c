#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <string.h>
#include <unistd.h>
#include <fsh/fsh_prompt.h>

void set_prompt(char *prompt) {
    char *user = getenv("USER");
    if (!user) {
        printf("$USER NOT SET! Retard...\n");
        user = "Retard";
    }
    char *host = getenv("HOSTNAME");
    if (!host) {
        printf("$HOSTNAME NOT SET! Dafuq?!\n");
        host = "Some_weird_ass_machine";
    }
    if ((strcmp(getenv("USER"), "root") != 0) || !user) {
        printf("Well... Welcome to the fucking shell, %s!\n", user);
        snprintf(prompt, 1024, "[%s@%s n' shit]~$ ",
                 user, host);
        chdir("~");
    } else {
        printf("Woah! We've got a badass over here... Running with root n' shit...\n");
        snprintf(prompt, 1024, "[%s@%s n' shit]# ",
                 user, host);
        chdir("/root");
    }
}
