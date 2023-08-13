#include <stdint.h>
#include <stdio.h>

static const uint8_t baz[] = "helloworld";
void foo(unsigned char ** bar)
{
    *bar= (unsigned char *) baz;
}

int main()
{
    unsigned char * mybar = NULL;
    foo(&mybar);
    printf("mybar: %s\n", mybar);
}