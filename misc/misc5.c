#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>  // for ntohl

int main() {
    uint8_t* pData = (uint8_t*)malloc(sizeof(uint8_t) * 4);  // Allocate memory on the heap
    pData[0] = 0x00;
    pData[1] = 0x00;
    pData[2] = 0x00;
    pData[3] = 0xFF;
    pData[4] = 0x65;
    pData[5] = 0x72;
    pData[6] = 0x6F;
    pData[7] = 0x4C;

    unsigned int index = *(unsigned int*)pData;
    index = ntohl(index);   // convert from network byte order to host byte order

    // Print the integer value
    printf("Index: %u\n", index);

    free(pData);  // Remember to free the allocated memory

    return 0;
}
