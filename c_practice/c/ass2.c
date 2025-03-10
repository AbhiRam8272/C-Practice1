#include<stdio.h>
extern int m;
double my_sqrt(double x) {
    double i;
    for(i = 0; i * i <= x; i += 0.0001);
    {
        printf("%d",m);
        }
    return i;
}

int main() {
    double a;
    printf("Enter number to find square root:");
    scanf("%lf",&a);
    double result = my_sqrt(a);
    printf("Square root of %f is %f\n", a, result);
    return 0;
}