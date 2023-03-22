#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool contains(char *haystack, char *needle, size_t haystack_len, size_t needle_len) {
    if (needle_len > haystack_len)
        return false;
    for (size_t i = 0; i <= haystack_len - needle_len; i++) {
        if (memcmp(haystack + i, needle, needle_len) == 0)
            return true;
    }
    return false;
}

int main() {
    char *haystack = "\x01\x02\x03\x04\x05";
    char *needle = "\x03\x04";
    size_t haystack_len = 5;
    size_t needle_len = 2;

    if (contains(haystack, needle, haystack_len, needle_len)) {
        printf("'%s' contains '%s'\n", haystack, needle);
    } else {
        printf("'%s' does not contain '%s'\n", haystack, needle);
    }
    return 0;
}
