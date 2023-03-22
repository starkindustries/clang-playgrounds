#include <stdio.h>

int main()
{
    void * start = (void*) 0x10000000;
    void * end = (void*) 0x20000000;
    size_t len = ((int) *end) - ((int) *start);
    printf("len %ld\n", len);
}