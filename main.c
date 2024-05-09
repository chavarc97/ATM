#include "./includes/functions.h" // Includes the functions.h file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * compile tests:
 * gcc atm.c ./functions/functions.c -o ejec.exe
 * once we have all functions defined:
 * create an object file and execute the command

TODO:
  * Define necessary structures to handle the ATM
      * User
      * Account
      * Transaction (Deposit / Transfer / Withdraw)
      * Receipt
          * Receipt function executes right after a transaction is done.

  * Define the functions to handle the ATM
      (use the functions.h file to define the functions)
      * Login function.
      * Register user function.
      * Deposit function.
      * Withdraw function.
      * Transfer function.
      * Check balance function.
      * Convert currency function.
      * Print receipt function.
      * log out function.

  * Once we login or create a user the UserScreen shows up
      * In the user screen we can:
          * Deposit.
          * Withdraw.
          * Transfer.
          * Check balance.
          * Get the receipt.
          * Log out.
*/



int main() {
  int option, ret; // option and return value

mainMenu: // selection main menu

  clearScreen();
  printf("\n====================WIZARD BANK====================\n");

  printf("\n\n\t1.Log-In to a Existing Account.\t");
  printf("\n\n\t2.Create a New Account.\t");
  printf("\n\n\t3.Exit.\t\n");
  printf("\n\n=================================================");

  // Select an option
  printf("\n\n\tEnter your choice: ");
  ret = scanf("%d", &option);

  // Switch statement for the main menu
  switch (option) {
  case 1:
    // log in to an existing account
    break;
  case 2:
    // create a new account
    break;
  case 3:
    // exit
    clearScreen();
    exitProgram();
    break;
  default:
    printf("\nInvalid Selection\n\n");
    goto mainMenu;
  }

  return 0;
}
