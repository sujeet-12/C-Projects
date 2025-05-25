#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

void addItem() {
    FILE *fp = fopen("inventory.dat", "ab");
    struct Item it;

    printf("Enter Item ID: ");
    scanf("%d", &it.id);
    printf("Enter Item Name: ");
    scanf(" %[^\n]", it.name);
    printf("Enter Quantity: ");
    scanf("%d", &it.quantity);
    printf("Enter Price: ");
    scanf("%f", &it.price);

    fwrite(&it, sizeof(it), 1, fp);
    fclose(fp);

    printf("Item added successfully.\n");
}

void displayItems() {
    FILE *fp = fopen("inventory.dat", "rb");
    struct Item it;

    printf("\n--- Inventory List ---\n");
    while (fread(&it, sizeof(it), 1, fp)) {
        printf("ID: %d | Name: %s | Quantity: %d | Price: %.2f\n", it.id, it.name, it.quantity, it.price);
    }

    fclose(fp);
}

void searchItem() {
    FILE *fp = fopen("inventory.dat", "rb");
    struct Item it;
    int id, found = 0;

    printf("Enter Item ID to search: ");
    scanf("%d", &id);

    while (fread(&it, sizeof(it), 1, fp)) {
        if (it.id == id) {
            printf("Item Found:\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n",
                   it.id, it.name, it.quantity, it.price);
            found = 1;
            break;
        }
    }

    if (!found) printf("Item not found.\n");

    fclose(fp);
}

void updateQuantity() {
    FILE *fp = fopen("inventory.dat", "rb+");
    struct Item it;
    int id, qty, found = 0;

    printf("Enter Item ID to update quantity: ");
    scanf("%d", &id);

    while (fread(&it, sizeof(it), 1, fp)) {
        if (it.id == id) {
            printf("Enter new quantity: ");
            scanf("%d", &qty);
            it.quantity = qty;
            fseek(fp, -sizeof(it), SEEK_CUR);
            fwrite(&it, sizeof(it), 1, fp);
            found = 1;
            printf("Quantity updated.\n");
            break;
        }
    }

    if (!found) printf("Item not found.\n");

    fclose(fp);
}

void deleteItem() {
    FILE *fp = fopen("inventory.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct Item it;
    int id, found = 0;

    printf("Enter Item ID to delete: ");
    scanf("%d", &id);

    while (fread(&it, sizeof(it), 1, fp)) {
        if (it.id != id) {
            fwrite(&it, sizeof(it), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);
    remove("inventory.dat");
    rename("temp.dat", "inventory.dat");

    if (found) printf("Item deleted successfully.\n");
    else printf("Item not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Inventory Management Menu ---\n");
        printf("1. Add Item\n2. Display Items\n3. Search Item\n4. Update Quantity\n5. Delete Item\n6. Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(); break;
            case 2: displayItems(); break;
            case 3: searchItem(); break;
            case 4: updateQuantity(); break;
            case 5: deleteItem(); break;
            case 6: printf("Exiting program.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
