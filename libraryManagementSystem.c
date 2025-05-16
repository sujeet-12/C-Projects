#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[100];
    int available; // 1 for available, 0 for issued
};

void addBook() {
    FILE *fp = fopen("library.dat", "ab");
    struct Book b;

    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    printf("Enter Book Title: ");
    scanf(" %[^\n]", b.title);
    printf("Enter Author Name: ");
    scanf(" %[^\n]", b.author);
    b.available = 1;

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);
    printf("Book added successfully.\n");
}

void listBooks() {
    FILE *fp = fopen("library.dat", "rb");
    struct Book b;

    printf("\n--- List of Books ---\n");
    while (fread(&b, sizeof(b), 1, fp)) {
        printf("ID: %d | Title: %s | Author: %s | %s\n", b.id, b.title, b.author, b.available ? "Available" : "Issued");
    }

    fclose(fp);
}

void searchBook() {
    FILE *fp = fopen("library.dat", "rb");
    struct Book b;
    int id, found = 0;

    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            printf("Book Found:\nID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n",
                   b.id, b.title, b.author, b.available ? "Available" : "Issued");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Book not found.\n");

    fclose(fp);
}

void issueBook() {
    FILE *fp = fopen("library.dat", "rb+");
    struct Book b;
    int id, found = 0;

    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            found = 1;
            if (b.available) {
                b.available = 0;
                fseek(fp, -sizeof(b), SEEK_CUR);
                fwrite(&b, sizeof(b), 1, fp);
                printf("Book issued successfully.\n");
            } else {
                printf("Book already issued.\n");
            }
            break;
        }
    }

    if (!found)
        printf("Book not found.\n");

    fclose(fp);
}

void returnBook() {
    FILE *fp = fopen("library.dat", "rb+");
    struct Book b;
    int id, found = 0;

    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            found = 1;
            if (!b.available) {
                b.available = 1;
                fseek(fp, -sizeof(b), SEEK_CUR);
                fwrite(&b, sizeof(b), 1, fp);
                printf("Book returned successfully.\n");
            } else {
                printf("Book is already available.\n");
            }
            break;
        }
    }

    if (!found)
        printf("Book not found.\n");

    fclose(fp);
}

int main() {
    int choice;

    do {
        printf("\n--- Library Management Menu ---\n");
        printf("1. Add Book\n2. List Books\n3. Search Book\n4. Issue Book\n5. Return Book\n6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: listBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: printf("Exiting Library System.\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}
