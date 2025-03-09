#include <stdio.h>

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num > 0) {
        printf("The number is positive.\n");
    } else if (num < 0) {
        printf("The number is negative.\n");
    } else {
        printf("The number is zero.\n");
    }

    switch (num % 2) {
        case 0:
            printf("The number is even.\n");
            break;
        default:
            printf("The number is odd.\n");
    }

    return 0;
}
