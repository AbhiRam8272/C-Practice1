#include <stdio.h>
#include <stdlib.h>

// Functions for operations
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divi(int a, int b) { 
    if(b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b; 
}

// Function returning pointer (to demonstrate pointer function)
int* getResult(int result) {
    int *ptr = malloc(sizeof(int)); // dynamic memory
    *ptr = result;
    return ptr;
}

int main() {
    int choice, x, y;
    
    // Array of function pointers
    int (*operations[])(int, int) = {add, sub, mul, divi};
    char *names[] = {"Addition", "Subtraction", "Multiplication", "Division"};

    while(1) {
        printf("\n=== Calculator Menu ===\n");
        for (int i = 0; i < 4; i++) {
            printf("%d. %s\n", i+1, names[i]);
        }
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 5) break;
        if (choice < 1 || choice > 4) {
            printf("Invalid choice!\n");
            continue;
        }

        printf("Enter two numbers: ");
        scanf("%d %d", &x, &y);

        // Call using pointer to function
        int result = operations[choice-1](x, y);

        // Store result using pointer function
        int *resPtr = getResult(result);

        printf("Result = %d\n", *resPtr);

        free(resPtr); // free allocated memory
    }

    return 0;
}

