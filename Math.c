#include <stdio.h>

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    printf("Addition: %d\n", a + b);
    printf("Subtraction: %d\n", a - b);
    printf("Multiplication: %d\n", a * b);
    
    if (b != 0) {
        printf("Division: %d\n", a / b);
        printf("Remainder: %d\n", a % b);
    } else {
        printf("Division and Remainder not possible (division by zero).\n");
    }
    
    return 0;
}
