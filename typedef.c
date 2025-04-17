#include <stdio.h>

// Using typedef to rename the struct type
typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

void display(Employee e) {
    printf("ID: %d\n", e.id);
    printf("Name: %s\n", e.name);
    printf("Salary: %.2f\n", e.salary);
}

int main() {
    Employee emp1;

    printf("Enter ID: ");
    scanf("%d", &emp1.id);

    printf("Enter Name: ");
    scanf("%s", emp1.name);

    printf("Enter Salary: ");
    scanf("%f", &emp1.salary);

    printf("\nEmployee Details:\n");
    display(emp1);

    return 0;
}
