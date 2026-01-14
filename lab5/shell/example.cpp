#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char program_name[10] = "/bin/echo";
    const char* arg1 = "hello";
    const char* arg2 = "world";
    const char* newargv[] = { program_name, arg1, arg2, NULL };
    // this will replace the process image with the image of
    // executable `/bin/echo`and arguments newargv
    execv("/bin/hello", (char* const*)newargv);

    // should only get past here if execv() returns an error
    perror("execv failed");
    exit(EXIT_FAILURE);
}
