#include <stdio.h>

int main() {
    int num = 1;
    char *c = (char*)&num;

    if (*c) {
        printf("Little endian\n");
    } else {
        printf("Big endian\n");
    }
    return 0;
}

// little-endian systems, the least significant byte is stored at the lowest memory address

// num = 1 will be 0x00 00 00 01
// Little endian repr will be:- 01 00 00 00 -> LSB will be first in memory

// while in big-endian systems, the most significant byte is stored first
