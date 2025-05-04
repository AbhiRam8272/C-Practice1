//find hamming distance
#include <stdio.h>

int totalHammingDistance(int* nums, int numsSize) {
    int total = 0;
    for (int i = 0; i < 32; i++) {
        int count = 0;
        for (int j = 0; j < numsSize; j++) count += (nums[j] >> i) & 1;
        total += count * (numsSize - count);
    }
    return total;
}

int main() {
    int nums[] = {4, 14, 2};
    int n = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", totalHammingDistance(nums, n));
    return 0;
}
