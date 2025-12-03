//subset of xor sum
#include <stdio.h>

int subsetXORSum(int* nums, int numsSize) {
    int orAll = 0;
    for (int i = 0; i < numsSize; i++) 
        orAll |= nums[i];
    return orAll * (1 << (numsSize - 1));
}

int main() {
    int nums[] = {1, 3};
    int n = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", subsetXORSum(nums, n));
    return 0;
}
