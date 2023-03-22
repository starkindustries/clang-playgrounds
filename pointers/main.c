#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_string(char ** mystr) {
    char * uuid = "hello_world";
    *mystr = uuid;
    printf("uuid:[%s], mystr:[%s]\n", uuid, *mystr);
}

int main() {
    char * temp;
    get_string(&temp);
    printf("temp: [%s]\n", temp);

    int x = 1;
    x =+ 2;
    printf("%d\n", x);
    return 0;
}