#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures
typedef struct {
    char username[50];
    char house[20];
    int account_id; // Unique account identifier
    // Other account-related information can be added here
} User;

typedef struct {
    User account_id;
    float balance_galleon; // Balance in ʛ
    float balance_usd; // Balance in USD
} Account;

typedef struct {
    char currency_code[4];
    float exchange_rate; // Exchange rate to USD
} Currency;

typedef struct {
    int transaction_id; // Unique transaction identifier
    User account_id; // Account identifier
    char transaction_type[10]; // Deposit or Withdraw
    float amount; // Amount in ʛ
    Currency currency_code[4]; // Currency code
    Currency exchange_rate; // Exchange rate to USD
    float amount_usd; // Amount in USD
} Transaction;

// Function prototypes

int main()
{
    printf("=====================================================================================================\n");
    printf("\t\t\t\tWelcome to the ATM Machine Simulation\n\n");
    printf("\t\t\t\tPlease select an option:\n");
    printf("\t\t\t\t1. Create an account\n");
    printf("\t\t\t\t2. Deposit money\n");
    printf("\t\t\t\t3. Withdraw money\n");
    printf("\t\t\t\t4. Check balance\n");
    printf("\t\t\t\t5. Transaction history\n");
    printf("\t\t\t\t6. Exit\n");

    int option, ret;
    printf("\n");
    printf("\t\t\tEnter an option: ");
    ret = scanf("%d", &option);
    
        switch (option)
        {
        case 1:
            printf("Create an account\n");
            break;
        case 2:
            printf("Deposit money\n");
            break;
        case 3:
            printf("Withdraw money\n");
            break;
        case 4:
            printf("Check balance\n");
            break;
        case 5:
            printf("Transaction history\n");
            break;
        case 6:
            printf("Exit\n");
            break;

        default:
            printf("Invalid option\n");
        }
        
    return 0;
}