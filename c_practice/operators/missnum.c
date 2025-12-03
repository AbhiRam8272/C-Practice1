//find the missing number
#include <stdio.h>

int missingNumber(int* nums, int numsSize) {
    int res = numsSize;
    for (int i = 0; i < numsSize; i++) res ^= i ^ nums[i];
    return res;
}

int main() {
    int nums[] = {3, 0, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", missingNumber(nums, n));
    return 0;
}
