#include <stdio.h>

float multiply(float x, float y) {  
    return x * y;  
}

int main() {
    float result = multiply(2.5, 4.0);
    printf("Multiplication: %.2f\n", result);
    return 0;
}
