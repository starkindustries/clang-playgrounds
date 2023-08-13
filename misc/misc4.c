#include <stdio.h>
#include <arpa/inet.h>  // for ntohl
#include <string.h>  // for memcpy

int main() {
    // Simulated data, as if it was received from somewhere else
    unsigned char pData[] = {0x00, 0x00, 0x00, 0xFF, 0x65, 0x72, 0x6F, 0x4C};

    unsigned int index;
    memcpy(&index, pData, sizeof(index));
    index = ntohl(index);   // convert from network byte order to host byte order

    // Print out the integer value
    printf("Index: %u\n", index);

    return 0;
}
