#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_USERS 20
#define MAX_TRANSACTIONS 20

// struct to define user
typedef struct {
  double balance;
  char username[50];
  char pin[50];
  char name[50];
  char house[20];
  char seal[25];
  char bloodType[25];
} User;

// struct to define transactions
typedef struct {
  double amount;
  int transactionId;
  char transactionType[20]; // deposit transfer or withdraw
} Transaction;

// store the ATM state
typedef struct {
  User users[MAX_USERS];                      // Array to store user accounts
  int num_users;                              // Number of registered users
  Transaction transactions[MAX_TRANSACTIONS]; // Array to store transactions
  int num_transactions;                       // Number of transactions
} ATM;

// receipt struct

typedef struct {
  double amount;
  int receiptId;
  char date[20];
  Transaction type[20];
} Receipt;

// Account struct
typedef struct {
  char accountType[50];
  int galleons;
  int sickles;
  int knuts;
  double pesosMXN;
  double usd;
  int activeDuration;
  double loanInterest;
  double transactionFee;
  Transaction transactions[100]; // Array of transactions
  int num_transactions;         // Number of transactions
  Receipt receipts[100];         // Array of receipts
} Account;

void exitProgram();
void clearScreen();
User *logIn(ATM *atm);
void logOut();
void userScreen(User *user);
void magicGame();
int main();
void registerUser(ATM *atm);
#endif