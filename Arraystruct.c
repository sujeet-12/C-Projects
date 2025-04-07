#include <stdio.h>

struct Employee {
    int id;
    char name[50];
};

void printEmployees(struct Employee e[], int n) {
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s\n", e[i].id, e[i].name);
    }
}

int main() {
    struct Employee e[2] = {
        {101, "Alice"},
        {102, "Bob"}
    };
    printEmployees(e, 2);
    return 0;
}
