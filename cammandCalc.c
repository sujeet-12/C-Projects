#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ./calc <number1> <operator> <number2>\n");
        printf("Example: ./calc 10 + 5\n");
        return 1;
    }

    int num1 = atoi(argv[1]);
    char op = argv[2][0];
    int num2 = atoi(argv[3]);
    int result;

    switch(op) {
        case '+': result = num1 + num2;
                  break;
        case '-': result = num1 - num2;
                  break;
        case '*': result = num1 * num2;
                  break;
        case '/': 
                  if (num2 == 0) {
                      printf("Error: Division by zero!\n");
                      return 1;
                  }
                  result = num1 / num2;
                  break;
        case '%':
                  if (num2 == 0) {
                      printf("Error: Modulus by zero!\n");
                      return 1;
                  }
                  result = num1 % num2;
                  break;
        default:
                  printf("Error: Invalid operator. Use +, -, *, /, or %%\n");
                  return 1;
    }

    printf("Result: %d\n", result);
    return 0;
}
