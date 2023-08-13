#include <stdio.h>

// To compile with FOO defined:
// gcc -DFOO -o foo foo.c
// 
// Or compile with FOO not defined:
// gcc -o foo foo.c
//
// Sample output:
// $ gcc -DFOO -o foo foo.c
// $ ./foo 
// FOO is defined
// 
// $ gcc -o foo foo.c
// $ ./foo 
// FOO is not defined

int main() {
#ifdef FOO
    printf("FOO is defined\n");
#elif defined(BAR)
    printf("BAR is defined!\n");
#else
    // #error "Both FOO and BAR are not defined"
    printf("FOO and BAR are not defined\n");
#endif
    return 0;
}
