//Find the Single Number
#include<stdio.h>
int singleNumber(int* nums, int numsSize) {
    int res = 0;
    for (int i = 0; i < numsSize; i++) 
        res ^= nums[i];
    return res;
}
int main(){
    int a[]={3,4,6,6,5,4,5};
    int size=sizeof(a)/sizeof(a[1]);
    printf("Non reapting element is %d",singleNumber(a,size));
    return 0;
}