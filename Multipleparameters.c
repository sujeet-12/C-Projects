#include <stdio.h>

void greeting(char name[], int age) {
    printf("Hello, %s! \n", name);
    printf("You are %d years old. \n\n", age);
}

int main() {
    greeting("James", 42);
    greeting("Amy", 21);

    return 0;
}
