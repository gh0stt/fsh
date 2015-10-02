#include <stdio.h>
#include <stdlib.h>

int fsh_exit(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        printf("Exit run with: %s", argv[i]);
    }
    printf("Well... Fuckin'... Bye then...\n");
    exit(EXIT_SUCCESS);
    return 0;
}
