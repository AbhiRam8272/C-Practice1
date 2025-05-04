//Find the SingleII
#include<stdio.h>
int singleNumber(int* nums, int numsSize) {
    int ones = 0, twos = 0;
    for (int i = 0; i < numsSize; i++) {
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
    }
    return ones;
}

int main(){
    int a[]={3,3,3,2,4,6,6,6,5,5,4,5,4};
    int size=sizeof(a)/sizeof(a[1]);
    printf("Non reapting element is %d",singleNumber(a,size));
    return 0;
}