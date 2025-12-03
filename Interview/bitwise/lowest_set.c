#include <stdio.h>
#include<stdint.h>

int highestSetBit(int n) {
    if (n == 0) return -1;
    int pos = 0;

    while (n>>=1)
        pos++;

    return pos;
}

int main() {
    uint8_t n;
    scanf("%hhd", &n);
    printf("Highest set bit: %d\n", highestSetBit(n));
    return 0;
}

