#include <string.h>
#include <stdio.h>
#include <stdbool.h>


// bool contains(const void* haystack, const void* needle, size_t haystack_len, size_t needle_len)
// {
//     const char* h = (const char*)haystack;
//     const char* n = (const char*)needle;

//     if (needle_len > haystack_len)
//         return false;
//     for (size_t i = 0; i <= haystack_len - needle_len; i++) {
//         if (memcmp(h + i, n, needle_len) == 0)
//             return true;
//     }
//     return false;
// }


int main(void) {
    unsigned char haystack[] = { 0x01, 0x02, 0x03, 0x04, 0x05 };
    unsigned char needle[] = { 0x03, 0x04 };
    
    unsigned char *ptr = (unsigned char *)memmem(haystack, sizeof(haystack), needle, sizeof(needle));
    if (ptr) {
        printf("Needle found at offset %ld\n", ptr - haystack);
    } else {
        printf("Needle not found\n");
    }
    
    return 0;
}
