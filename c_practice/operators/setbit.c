//Count Set Bits in an Integer
#include <stdio.h>

int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main() {
    int n = 29;
    printf("%d\n", countSetBits(n));
    return 0;
}
