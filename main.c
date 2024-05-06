#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defines
#define MAX_USERS 100
#define USERNAME_LENGTH 50
#define PASSWORD_LENGTH 50

// Define structures
typedef struct {
  int account_id; // Unique account identifier
  char username[USERNAME_LENGTH];
  char house[20];
  char password[PASSWORD_LENGTH];
  // Other account-related information can be added here
} User;

typedef struct {
  User users[MAX_USERS];
  float balance_galleon; // Balance in ʛ
  float balance_usd;     // Balance in USD
} Account;
int num_users = 0;

typedef struct {
  char currency_code[4];
  float exchange_rate; // Exchange rate to USD
} Currency;

typedef struct {
  int transaction_id;        // Unique transaction identifier
  User account_id;           // Account identifier
  char transaction_type[10]; // Deposit or Withdraw
  float amount;              // Amount in ʛ
  Currency currency_code[4]; // Currency code
  Currency exchange_rate;    // Exchange rate to USD
  float amount_usd;          // Amount in USD
} Transaction;

// Function prototypes
int login();
void signUp(char *username, char *house, char *password);
void createAccount(Account *account, char *username, char *house,
                   char *password);
void clearScreen();

int main() {
  Account wizardBank;
  wizardBank.balance_galleon = 100.0; // Initial balance in wizarding currency
  wizardBank.balance_usd = 50.0;      // Initial balance in USD

  while (1) {
    
    printf(
        "====================================================================="
        "================================\n");

    printf("\t\t\t\tWelcome to the wizard ATM\n\n");
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

    char username[USERNAME_LENGTH];
    char house[20];
    char password[PASSWORD_LENGTH];

    switch (option) {
    case 1:

      printf("Create an account\n");
      signUp(username, house, password);
      createAccount(&wizardBank, username, house, password);
      // clearScreen();
      break;
    case 2:
      printf("Deposit money\n");
      clearScreen();
      break;
    case 3:
      printf("Withdraw money\n");
      // clearScreen();
      break;
    case 4:
      printf("Check balance\n");
      // clearScreen();
      break;
    case 5:
      printf("Transaction history\n");
      // nclearScreen();
      break;
    case 6:
      printf("Exit\n");
      break;

    default:
      printf("Invalid option\n");
    }
  }

  return 0;
}

void createAccount(Account *account, char *username, char *house,
                   char *password) {
  // Check if the maximum limit of users has been reached
  if (num_users >= MAX_USERS) {
    printf("Cannot create more accounts. Maximum limit reached.\n");
    return;
  }

  User newUser;
  newUser.account_id = num_users + 1;
  strncpy(newUser.username, username, USERNAME_LENGTH - 1);
  strncpy(newUser.house, house, sizeof(newUser.house) - 1);
  strncpy(newUser.password, password, PASSWORD_LENGTH - 1);

  account->users[num_users++] = newUser;
  printf("Account created successfully for %s.\n", username);
}

void signUp(char *username, char *house, char *password) {
  int ret;
  printf("Lets get you signed up!\n");
  printf("Please enter your username: ");

  ret = scanf("%s", username);
  printf("Please enter your house: ");
  ret = scanf("%s", house);
  printf("Please enter your password: ");
  ret = scanf("%s", password);
}

void clearScreen()
{
  printf("\033[2J\033[H");
}