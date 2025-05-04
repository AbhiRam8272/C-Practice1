//reversing of bits
#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; i++) {
        res <<= 1;
        res |= n & 1;
        n >>= 1;
    }
    return res;
}

int main() {
    uint32_t n = 43261596;
    printf("%u\n", reverseBits(n));
    return 0;
}
