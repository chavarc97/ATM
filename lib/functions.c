#include "../includes/functions.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Exit function
void exitProgram()
{
    printf("\033[2J\033[1;1H");
    printf("\n====================WIZARD BANK====================\n");
    printf("\n\n\tThank you for using Wizard Bank!😁\n");
    printf("\n\n=================================================\n");
}

// Clear screen function
void clearScreen() { printf("\033[2J\033[1;1H"); }

// Login function
// add the necesary params
void login()
{
    // add logic here!
}

// LogOut function
void logOut()
{
    int option, ret;
// add logic here!
logOutMenu: // selection log out menu
    clearScreen();
    printf("\n====================WIZARD BANK====================\n");
    printf("\n\n\tAbandoning Wizard's Bank\n");
    printf("\n\n\tAre you sure?.\n");
    printf("\n\n\t1.Yes.\n");
    printf("\n\t2.No.\n");
    printf("\n\n=================================================\n");
    printf("Enter your option: ");
    ret = scanf("%d", &option);

    switch (option)
    {
    case 1:
        // return to the main function
        main();
        break;
    case 2:
        // User Screen
        break;
    default:
        goto logOutMenu;
    }
}

void userScreen()
{
    clearScreen();
    // This is the user view once the user is logged in
    int option, ret;
userMenu: // selection user menu
    printf("\n==================WELCOME BACK==================\n");
    printf("\n\n\tPlease select an option\n");
    printf("\n\t1. Deposit\n");
    printf("\n\t2. Withdraw\n");
    printf("\n\t3. Transfer\n");
    printf("\n\t4. Check Balance\n");
    printf("\n\t5. Bet in a magic game!!!!\n");

    switch (option)
    {
    case 1:
        // Deposit
        break;
    case 2:
        // Withdraw
        break;
    case 3:
        // Transfer
        break;
    case 4:
        // Check Balance
        break;
    case 5:
        // Magic Game
        break;
    default:
        printf("Invalid option");
        goto userMenu;
        break;
    }
}

void magicGame()
{
    clearScreen();
    // add logic here!
    int number, userNumber, ret;

    // random number from 1 to 10
    srand(time(NULL));
    number = rand() % 10 + 1;

    printf("\n==================MAGIC GAME==================\n");
    printf("\n\n\tGuess a number from 1 to 10");
    printf("\n\tFor a chance to win $100,000 USD");
    printf("\n\n\tEnter your number: ");
    ret = scanf("%d", &userNumber);

    printf("\n\n\tThe magic number is: %d", number);
    if (userNumber == number)
    {
        printf("\n\tCongratulations! You won $100,000 USD");
    }
    else
    {
        printf("\n\tSorry, you lost🙃");
        printf("\n\t$10 USD will be deducted from your account");
    }
    // deduct 10 usd from aacount or add 100,000 usd to account
}

// deposit
User deposit(Account *account)
{
    int ret, amount, currency;
    printf(
        "\tSelect the type of currency you want to deposit into your account \n");
    printf("\t\t1. Galleons\n");
    printf("\t\t2. Sickles\n");
    printf("\t\t3. Knuts\n");
    printf("\t\t4. USD\n");
    printf("\t\t5. Pesos MXN\n");
    printf("\t\t6. Cancel\n");
    printf("\n\tEnter your choice: ");
    ret = scanf("%d", &currency);

    printf("\n\tEnter the amount you want to deposit: ");
    ret = scanf("%d", &amount);

    switch (currency)
    {
    case 1:
        account->galleons += amount;
        break;
    case 2:
        account->sickles += amount;
        break;
    case 3:
        account->knuts += amount;
        break;
    case 4:
        account->usd += amount;
        break;
    case 5:
        account->pesosMXN += amount;
        break;
    case 6:
        userScreen();
        break;
    default:
        printf("\n\tInvalid selection\n");
        return;
    }

    // Record the transaction
    Transaction newTransaction = {.amount = amount, .transactionId = account->num_transactions};
    strcpy(newTransaction.transactionType, "deposit");
    account->transactions[account->num_transactions++] = newTransaction;
    
    printf("You have deposited %d units of the selected currency.\n", amount);
}