#include <stdio.h>

int main() {
    int a, b;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    if (a > 0 && b > 0) {
        printf("Both numbers are positive.\n");
    } else {
        printf("At least one number is not positive.\n");
    }

    if (a % 2 == 0 || b % 2 == 0) {
        printf("At least one number is even.\n");
    } else {
        printf("Both numbers are odd.\n");
    }

    return 0;
}
