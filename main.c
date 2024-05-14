#include <stdio.h>
#include <string.h>
#include "includes/functions.h"

int main()
{
  ATM bank;
  bank.num_users = 0;
  bank.num_transactions = 0;
  bank.activeUser = -1;

  int option;

  while (1)
  {
    clearScreen();
    printf("\n====================WIZARD BANK====================\n");
    printf("\n\n\t1.Log-In to a Existing Account.\t");
    printf("\n\n\t2.Create a New Account.\t");
    printf("\n\n\t3.Exit.\t\n");
    printf("\n\n=================================================");
    printf("\n\n\tEnter your choice: ");
    scanf("%d", &option);
    clearInputBuffer(); // Limpiar el buffer de entrada después de leer la opción

    switch (option)
    {
    case 1:
      // Implementar función de inicio de sesión
      login(&bank);
      break;
    case 2:
      registerUser(&bank);
      break;
    case 3:
      printf("Thank you for using Wizard Bank. Goodbye!\n");
      return 1;
    default:
      printf("Invalid option\n");
      break;
    }
  }

  return 0;
}
