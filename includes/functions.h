#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_USERS 20
#define MAX_TRANSACTIONS 50
#define MAX_STRING 50

// Definición de la estructura Transaction
typedef struct
{
    double amount;
    int transactionId;
    char transactionType[MAX_STRING];
} Transaction;

// Definición de la estructura Account
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
  int num_transactions;          // Number of transactions        // Array of receipts
} Account;

// Definición de la estructura User
typedef struct
{
    int id;
    Account account;
    char username[50];
    int pin;
    char name[50];
    char house[50];
    char seal[50];
    char bloodType[50];
} User;

// Definición de la estructura ATM
typedef struct
{
    User users[MAX_USERS];
    int num_users;
    Transaction transactions[MAX_TRANSACTIONS];
    int num_transactions;
    int activeUser;
} ATM;

void clearInputBuffer();
void registerUser(ATM *atm);
void deposit(ATM *atm);
void transfer(ATM *atm);
void checkBalance(ATM *atm);
void login(ATM *atm);
void userScreen(ATM *atm);
void clearScreen();
void magicGame(ATM *atm);
void withdraw(ATM *atm);
void invest(ATM *atm);
double calculateCompoundInterest(double principal, double rate, int years);
void generateLeaderboard(ATM *atm);
int main();

#endif