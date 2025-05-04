#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int accountNo;
    char name[50];
    float balance;
} Account;

Account accounts[MAX];
int totalAccounts = 0;

void createAccount() {
    if (totalAccounts >= MAX) {
        printf("Maximum account limit reached.\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &accounts[totalAccounts].accountNo);
    printf("Enter Name: ");
    scanf("%s", accounts[totalAccounts].name);
    printf("Enter Initial Balance: ");
    scanf("%f", &accounts[totalAccounts].balance);

    totalAccounts++;
    printf("Account created successfully.\n");
}

void depositMoney() {
    int accNo;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNo == accNo) {
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Amount Deposited. New Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdrawMoney() {
    int accNo;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNo == accNo) {
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);
            if (amount > accounts[i].balance) {
                printf("Insufficient balance.\n");
            } else {
                accounts[i].balance -= amount;
                printf("Withdrawal successful. New Balance: %.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void displayAccounts() {
    if (totalAccounts == 0) {
        printf("No accounts to display.\n");
        return;
    }

    printf("\n--- All Accounts ---\n");
    for (int i = 0; i < totalAccounts; i++) {
        printf("Account No: %d, Name: %s, Balance: %.2f\n",
               accounts[i].accountNo, accounts[i].name, accounts[i].balance);
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Bank Menu ---\n");
        printf("1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Display All Accounts\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: displayAccounts(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
