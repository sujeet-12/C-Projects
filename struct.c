#include <stdio.h>

// Define a struct
struct Student {
    int roll;
    char name[50];
    float marks;
};

// Function that takes struct as parameter
void displayStudent(struct Student s) {
    printf("Roll No: %d\n", s.roll);
    printf("Name: %s\n", s.name);
    printf("Marks: %.2f\n", s.marks);
}

int main() {
    struct Student s1;

    // Input values
    printf("Enter Roll No: ");
    scanf("%d", &s1.roll);

    printf("Enter Name: ");
    scanf("%s", s1.name);

    printf("Enter Marks: ");
    scanf("%f", &s1.marks);

    // Call function
    printf("\nStudent Details:\n");
    displayStudent(s1);

    return 0;
}
