#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char name[30];
    int quantity;
    float price;
} Item;

Item items[MAX];
int count = 0;

void addItem() {
    if (count >= MAX) {
        printf("Item limit reached!\n");
        return;
    }

    printf("Enter Item ID: ");
    scanf("%d", &items[count].id);
    printf("Enter Item Name: ");
    scanf("%s", items[count].name);
    printf("Enter Quantity: ");
    scanf("%d", &items[count].quantity);
    printf("Enter Price per Item: ");
    scanf("%f", &items[count].price);

    count++;
    printf("Item added successfully!\n");
}

void generateBill() {
    float total = 0, tax, grandTotal;

    if (count == 0) {
        printf("No items to bill.\n");
        return;
    }

    printf("\n--- BILL RECEIPT ---\n");
    printf("ID\tName\tQty\tPrice\tTotal\n");

    for (int i = 0; i < count; i++) {
        float itemTotal = items[i].quantity * items[i].price;
        total += itemTotal;
        printf("%d\t%s\t%d\t%.2f\t%.2f\n", items[i].id, items[i].name, items[i].quantity, items[i].price, itemTotal);
    }

    tax = total * 0.18; // 18% tax
    grandTotal = total + tax;

    printf("\nSubtotal: %.2f\n", total);
    printf("Tax (18%%): %.2f\n", tax);
    printf("Grand Total: %.2f\n", grandTotal);
}

int main() {
    int choice;

    do {
        printf("\n--- Billing Menu ---\n");
        printf("1. Add Item\n2. Generate Bill\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(); break;
            case 2: generateBill(); break;
            case 3: printf("Thank you for using Billing System.\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
