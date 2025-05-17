#include <stdio.h>

int main() {
    int score = 0, answer;

    printf("Welcome to the C Quiz Game!\n");
    printf("Each question has 1 mark. Let's begin!\n\n");

    // Question 1
    printf("Q1. What is the size of an int in C?\n");
    printf("1. 2 Bytes\n2. 4 Bytes\n3. 8 Bytes\n4. Depends on Compiler\n");
    printf("Your answer: ");
    scanf("%d", &answer);
    if (answer == 4) score++;

    // Question 2
    printf("\nQ2. Which of the following is a valid variable name?\n");
    printf("1. int\n2. 2value\n3. value_2\n4. float\n");
    printf("Your answer: ");
    scanf("%d", &answer);
    if (answer == 3) score++;

    // Question 3
    printf("\nQ3. What is the correct format specifier for float?\n");
    printf("1. %%c\n2. %%d\n3. %%f\n4. %%lf\n");
    printf("Your answer: ");
    scanf("%d", &answer);
    if (answer == 3) score++;

    // Question 4
    printf("\nQ4. What will 5 / 2 give in C?\n");
    printf("1. 2.5\n2. 2\n3. 3\n4. 0\n");
    printf("Your answer: ");
    scanf("%d", &answer);
    if (answer == 2) score++;

    // Question 5
    printf("\nQ5. What is used to define a constant in C?\n");
    printf("1. #define\n2. const\n3. static\n4. Both 1 and 2\n");
    printf("Your answer: ");
    scanf("%d", &answer);
    if (answer == 4) score++;

    printf("\nQuiz Over! Your total score is: %d/5\n", score);

    if (score == 5) printf("Excellent!\n");
    else if (score >= 3) printf("Good job!\n");
    else printf("Keep practicing.\n");

    return 0;
}
