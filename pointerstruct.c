#include <stdio.h>

struct Book {
    char title[50];
    int pages;
};

void printBook(struct Book *b) {
    printf("Title: %s\n", b->title);
    printf("Pages: %d\n", b->pages);
}

int main() {
    struct Book b1 = {"C Programming", 250};
    printBook(&b1);  // Pass address of struct
    return 0;
}
