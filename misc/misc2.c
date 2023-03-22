#include <stdio.h>

// Pointer Arithmetic
int main() {
    void *ptr1 = (void*) 0x00001000;
    void *ptr2 = (void*) 0x00002000;

    printf("p2:%p - p1:%p = %zu\n", (int*) ptr2, (int*) ptr1, (int*) ptr2 - (int*) ptr1);
    printf("p2:%p - p1:%p = %zu\n", (char*) ptr2, (char*) ptr1, (char*) ptr2 - (char*) ptr1);
    
    
    size_t distance = (int*) ptr2 - (int*) ptr1;
    printf("Distance between pointers: %zu bytes\n", distance);

    size_t dist2 = (char*) ptr2 - (char*) ptr1;
    printf("Distance char *: %zu\n", dist2);

    return 0;
}
