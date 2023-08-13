#include <unistd.h>
#include <stdio.h>

int main() {
    char *args[] = {"/bin/sh", "-c", "whoami; uname -a", NULL};

    if (execvp(args[0], args) == -1) {
        perror("execvp failed: ");
        return 1;
    }
    
    return 0;
}
