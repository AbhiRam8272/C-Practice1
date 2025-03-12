// C program to calculate the factorial of a given non-negative integer using bitwise operations
#include<stdio.h>
/*int main(){
    printf("Enter 2 numbers:");
    scanf("%d%d",&a,&b);

}*/

// Function to multiply two numbers using bitwise operations
unsigned int bitwiseMultiply(unsigned int a, unsigned int b) {
    unsigned int result = 0;
    while (b > 0) {
        if (b & 1) {
            result += a;
        }
        a <<= 1;
        b >>= 1;
    }
    return result;
}

// Function to calculate factorial using bitwise operations
unsigned int factorial(unsigned int n) {
    int a;
    if (n == 0) {
        return 1;
    }
    unsigned int result = 1;
    for (unsigned int i = 1; i <= n; ++i) {
        result = bitwiseMultiply(result, i);
        //a+=result;
        //printf("%d\n",a);
    }
    return result;
}

int main() {
    unsigned int number = 4; // Example number
    printf("Factorial of %u is %u\n", number, factorial(number));
    return 0;
}
