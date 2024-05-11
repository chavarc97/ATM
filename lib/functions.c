#include "../includes/functions.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
/* User *logIn(ATM *atm)
{
    char username[50];
    char pin[50];

    printf("\nEnter username: ");
    scanf("%s", username);

    printf("Enter PIN: ");
    scanf("%s", pin);

    // Buscar el usuario en la lista de usuarios
    for (int i = 0; i < atm->num_users; i++)
    {
        if (strcmp(atm->users[i].username, username) == 0 && strcmp(atm->users[i].pin, pin) == 0)
        {
            // Credenciales válidas, devolver el usuario
            return &atm->users[i];
        }
    }

    // Si no se encuentra el usuario o las credenciales son incorrectas
    printf("\nInvalid username or PIN. Please try again.\n");
    return NULL;
} */

// Register user function
void registerUser(ATM *atm)
{
  char username[50], pin[50], name[50], house[20], seal[25], bloodType[25];
  int ret;
  double balance;

  if (atm->num_users > MAX_USERS) {
    printf("\n\tThe bank is full, we cannot register more users.\n");
    return;
  }

  // if the bank is not full proceed to register the user
  User newUser;
  printf("\n====================WIZARD BANK====================\n");
  printf("\n\tRegister a new user\n");
  // Enter the username
  printf("\n\n\tEnter your name: ");
  ret = fscanf(stdin, "%s", username);
  strcpy(newUser.username, username);
  // Enter the pin
  printf("\n\tEnter your pin: ");
  ret = fscanf(stdin, "%s", pin);
  strcpy(newUser.pin, pin);
  // Enter the name
  printf("\n\tEnter your full name: ");
  ret = fscanf(stdin, "%s", name);
  strcpy(newUser.name, name);
  // Enter the house
  printf("\n\tEnter your house: ");
  ret = fscanf(stdin, "%s", house);
  strcpy(newUser.house, house);
  // Enter the seal
  printf("\n\tEnter your seal: ");
  ret = fscanf(stdin, "%s", seal);
  strcpy(newUser.seal, seal);
  // Enter the blood type
  printf("\n\tEnter your blood type: ");
  ret = fscanf(stdin, "%s", bloodType);
  strcpy(newUser.bloodType, bloodType);
  // Enter the balance
  printf("\n\tEnter your balance: ");
  ret = scanf("%lf", &balance);
  newUser.balance = balance;

  atm->users[atm->num_users++] = newUser;
  printf("\n\tUser registered successfully!\n");
  getchar();
  userScreen();
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

void userScreen(User *loggedInUser)
{
 clearScreen();
  // This is the user view once the user is logged in
  while (1) 
  {
    int option, ret;
    printf("\n==================WELCOME BACK==================\n");
    printf("\n\n\tPlease select an option\n");
    printf("\n\t1. Deposit\n");
    printf("\n\t2. Withdraw\n");
    printf("\n\t3. Transfer\n");
    printf("\n\t4. Check Balance\n");
    printf("\n\t5. Bet in a magic game!!!!\n");
    printf("\n\t6. Log out\n");
    printf("\n\n=================================================\n");
    printf("Your option: ");
    ret = scanf("%d", &option);

    switch (option) {
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
      magicGame();
      break;
    case 6:
      // Log out
      logOut();
    default:
      printf("Invalid option");
      continue;
    }
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
        
        break;
    default:
        printf("\n\tInvalid selection\n");
        break;
    }

    // Record the transaction
    Transaction newTransaction = {.amount = amount, .transactionId = account->num_transactions};
    strcpy(newTransaction.transactionType, "deposit");
    account->transactions[account->num_transactions++] = newTransaction;

    printf("You have deposited %d units of the selected currency.\n", amount);
}