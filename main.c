#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
This project is an ATM machine simulation.
The user can create an account, deposit money, withdraw money, check balance, and exit the program.

    * The user can create an account by entering their name, age, and initial deposit amount.
    * The user can deposit money by entering the amount they want to deposit.
    * The user can withdraw money by entering the amount they want to withdraw.
    * The user can check their balance.
    * The user can see the transaction history.
    * The user can exit the program.

    * We'll use a structure to store the user's information.
    * We'll use a linked list to store the transaction history.
    * We'll use a switch statement to handle the user's input.
    * We'll use a while loop to keep the program running until the user exits.
    * We'll use functions to handle the user's input.
    * We'll use our own library to handle the linked list.
    * We'll use a file to store the user's information.
    * We'll use a file to store the transaction history.
    * We'll use a file to store the user's account balance.

 */
typedef struct
{
    char name[50];
    int age;
    float balance;
} Account;

typedef struct
{
    char date[50];
    char time[50];
    char type[50];
    float amount;
} Transaction;

typedef struct Node
{
    Transaction transaction;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
} LinkedList;

typedef struct
{
    Account account;
    LinkedList transactions;
} User;

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