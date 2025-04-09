#include <stdio.h>

struct Date {
    int day, month, year;
};

struct Person {
    char name[50];
    struct Date dob;
};

void showPerson(struct Person p) {
    printf("Name: %s\n", p.name);
    printf("DOB: %02d/%02d/%d\n", p.dob.day, p.dob.month, p.dob.year);
}

int main() {
    struct Person p1 = {"Rahul", {12, 3, 2000}};
    showPerson(p1);
    return 0;
}
