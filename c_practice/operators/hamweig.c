//no of bits (hammimg weights)
#include <stdio.h>
#include <stdint.h>

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main() {
    uint32_t n = 11;
    printf("%d\n", hammingWeight(n));
    return 0;
}
