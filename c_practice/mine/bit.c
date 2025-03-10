#include <stdio.h>
#include"binary.h"

int main() {
    unsigned int num = 0x1234;
    unsigned int swapped;
    pb(num);
    pb((num & 0xF000));
    pb((num & 0x0F00));
    pb((num & 0x0F00) >> 4);
    pb((num & 0x00F0));
    pb((num & 0x00F0) << 4);
    pb((num & 0x000F));
    swapped=((num & 0xF000) >> 4) | ((num & 0x0F00) >> 8)  |  ((num & 0x00F0) << 8)  |  ((num & 0x000F)<<4);   
    printf("Original: 0x%04X\n", num);
    printf("Swapped:  0x%04X\n", swapped);

    return 0;
}
