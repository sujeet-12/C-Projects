#include <stdio.h>

char getGrade(int marks) {  
    if (marks >= 90) return 'A';
    else if (marks >= 75) return 'B';
    else if (marks >= 60) return 'C';
    else return 'F';
}

int main() {
    int marks;
    printf("Enter marks: ");
    scanf("%d", &marks);
    
    char grade = getGrade(marks);
    printf("Grade: %c\n", grade);
    return 0;
}
