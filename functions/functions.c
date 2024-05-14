#include "../includes/functions.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Función para limpiar el buffer de entrada
void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

// Función para registrar un nuevo usuario
void registerUser(ATM *atm) {
  int ret;
  if (atm->num_users >= MAX_USERS) {
    printf("You have reached the maximum number of users.\n");
    return;
  }

  clearScreen();
  User newUser;
  printf("\n==================== WIZARD BANK ====================\n");
  printf("\nRegister a new user\n");
  printf("Name: ");
  fgets(newUser.name, sizeof(newUser.name), stdin);
  newUser.name[strcspn(newUser.name, "\n")] =
      '\0'; // Eliminar el salto de línea

  printf("Username: ");
  fgets(newUser.username, sizeof(newUser.username), stdin);
  newUser.username[strcspn(newUser.username, "\n")] =
      '\0'; // Eliminar el salto de línea

  printf("PIN: ");
  ret = scanf("%d", &newUser.pin);
  clearInputBuffer(); // Limpiar el buffer de entrada después de leer el PIN

  printf("House: ");
  fgets(newUser.house, sizeof(newUser.house), stdin);
  newUser.house[strcspn(newUser.house, "\n")] =
      '\0'; // Eliminar el salto de línea

  printf("Seal: ");
  fgets(newUser.seal, sizeof(newUser.seal), stdin);
  newUser.seal[strcspn(newUser.seal, "\n")] =
      '\0'; // Eliminar el salto de línea

  printf("Blood Type: ");
  fgets(newUser.bloodType, sizeof(newUser.bloodType), stdin);
  newUser.bloodType[strcspn(newUser.bloodType, "\n")] =
      '\0'; // Eliminar el salto de línea

  newUser.id = atm->num_users;
  newUser.account.galleons = 10;
  newUser.account.sickles = 10;
  newUser.account.knuts = 10;
  newUser.account.pesosMXN = 100;
  newUser.account.usd = 100;

  atm->users[atm->num_users] = newUser;
  atm->num_users++;

  printf("Usuario registrado exitosamente.\n");
}

void deposit(ATM *atm) {
  clearScreen();
  int amount, currency, ret;

  if (atm->activeUser == -1) {
    printf("You must be logged in to access this function\n");
    return;
  }

  while (1) {
    printf("\n=====================DEPOSIT======================\n");

    printf("\tSelect the type of currency you want to deposit into your "
           "account \n");
    printf("\t\t1. Galleons\n");
    printf("\t\t2. Sickles\n");
    printf("\t\t3. Knuts\n");
    printf("\t\t4. USD\n");
    printf("\t\t5. Pesos MXN\n");
    printf("\t\t6. Cancel\n");
    printf("\n\tEnter your choice: ");
    ret = scanf("%d", &currency);
    clearInputBuffer();

    printf("\n\tEnter the amount you want to deposit: ");
    ret = scanf("%d", &amount);
    clearInputBuffer();

    switch (currency) {
    case 1:
      atm->users[atm->activeUser].account.galleons += amount;
      break;
    case 2:
      atm->users[atm->activeUser].account.sickles += amount;
      break;
    case 3:
      atm->users[atm->activeUser].account.knuts += amount;
      break;
    case 4:
      atm->users[atm->activeUser].account.usd += amount;
      break;
    case 5:
      atm->users[atm->activeUser].account.pesosMXN += amount;
      break;
    case 6:
      userScreen(atm);
      break;
    default:
      printf("\n\tInvalid selection\n");
      continue;
    }
    break; // Exit loop if a valid option is selected
  }
  printf("\n\tDepósito realizado con éxito.\n");
  printf("Press enter to return to the main menu.\n");
  getchar();
  clearScreen();
  userScreen(atm);
}

int check_amount(int amount, int currency, ATM *atm) {
  if (currency == 1 && amount >= atm->users[atm->activeUser].account.galleons) {
    return 1;
  }
  if (currency == 2 && amount >= atm->users[atm->activeUser].account.sickles) {
    return 1;
  }
  if (currency == 3 && amount >= atm->users[atm->activeUser].account.knuts) {
    return 1;
  }
  if (currency == 4 && amount >= atm->users[atm->activeUser].account.usd) {
    return 1;
  }
  if (currency == 5 && amount >= atm->users[atm->activeUser].account.pesosMXN) {
    return 1;
  } else {
    printf("You do not have the available amount of this currency to carry out "
           "the operation");
    return -1;
  }
}

// Función para realizar una transferencia entre cuentas
void transfer(ATM *atm) {
  int ret;
  if (atm->activeUser == -1) {
    printf("You must be logged in to check your balance\n");

    return;
  }

  User *sender = &atm->users[atm->activeUser];
  int recipientId;
  double amount;

  printf("\n=====================TRANSFER======================\n");

  printf("Write the account ID of the person receiving the transfer: ");
  ret = scanf("%d", &recipientId);
  clearInputBuffer(); // Limpiar el buffer de entrada después de leer el ID

  if (recipientId < 0 || recipientId >= atm->num_users) {
    printf("\nInvalid ID.\n");
    return;
  }
  printf("\n=========================================================\n");
  printf("choose   the type of currency you want to send");
  printf("\t\t1. Galleons\n");
  printf("\t\t2. Sickles\n");
  printf("\t\t3. Knuts\n");
  printf("\t\t4. USD\n");
  printf("\t\t5. Pesos MXN\n");
  printf("\t\t6. Cancel\n");
  int currency;
  printf("\n\tEnter your choice: ");
  ret = scanf("%d", &currency);
  clearInputBuffer();
  printf("\n\tEnter the amount you want to transfer: ");
  ret = scanf("%lf", &amount);

  // check ammount
  int flag_amount = check_amount(amount, currency, atm);

  switch (currency) {
  case 1: {
    if (flag_amount == 1) {
      atm->users[atm->activeUser].account.galleons -= amount;
      atm->users[recipientId].account.galleons += amount;
    }
    break;
  }
  case 2: {
    if (flag_amount == 1) {
      atm->users[atm->activeUser].account.sickles -= amount;
      atm->users[recipientId].account.sickles += amount;
    }
    break;
  }
  case 3: {
    if (flag_amount == 1) {
      atm->users[atm->activeUser].account.knuts -= amount;
      atm->users[recipientId].account.knuts += amount;
    }
    break;
  }
  case 4: {
    if (flag_amount == 1) {
      atm->users[atm->activeUser].account.usd -= amount;
      atm->users[recipientId].account.usd += amount;
    }
    break;
  }
  case 5: {
    if (flag_amount == 1) {
      atm->users[atm->activeUser].account.pesosMXN -= amount;
      atm->users[recipientId].account.pesosMXN += amount;
    }
    break;
  }
  }

  printf("E-Transfer successful.\n");

  printf("Press enter to return to the main menu.\n");
  getchar();
  clearScreen();
  userScreen(atm);
}

// Función para verificar el saldo de la cuenta activa
void checkBalance(ATM *atm) {
  clearScreen();
  if (atm->activeUser == -1) {
    printf("You must be logged in to check your balance\n");
    return;
  }

  User *user = &atm->users[atm->activeUser];

  printf("\n=====================BALANCE======================\n");

  printf("Name: %s\n", user->name);
  printf("USD: %.2f\n", user->account.usd);
  printf("Pesos MXN: %.2f\n", user->account.pesosMXN);
  printf("Galleons: %d\n", user->account.galleons);
  printf("Sickles: %d\n", user->account.sickles);
  printf("Knuts: %d\n", user->account.knuts);
  printf("\n");
  printf("Press enter to return to the main menu...\n");
  getchar();
  clearScreen();
  userScreen(atm);
}

// login function
void login(ATM *atm) {
  clearScreen();
  int ret;

  char username[MAX_STRING];
  int pin;

  printf("\n=====================LOGIN======================\n");
  printf("Username: ");
  fgets(username, sizeof(username), stdin);
  username[strcspn(username, "\n")] = '\0'; // Eliminar el salto de línea

  printf("PIN: ");
  ret = scanf("%d", &pin);
  clearInputBuffer(); // Limpiar el buffer de entrada después de leer el PIN

  for (int i = 0; i < atm->num_users; i++) {
    if (strcmp(atm->users[i].username, username) == 0 &&
        atm->users[i].pin == pin) {
      atm->activeUser = i;
      printf("login successful.\n");
      clearScreen();
      userScreen(atm);
      return;
    }
  }

  printf("Wrong credentials.\n");
  printf("Press enter to return to the main menu.\n");
  getchar();
  clearScreen();
  main();
}

void withdraw(ATM *atm) {
  clearScreen();
  int amount, currency, ret;

  if (atm->activeUser == -1) {
    printf("You need to log in first.\n");
    return;
  }

  while (1) {
    printf("\tSelect the type of currency you want to withdraw from your "
           "account \n");
    printf("\t\t1. Galleons\n");
    printf("\t\t2. Sickles\n");
    printf("\t\t3. Knuts\n");
    printf("\t\t4. USD\n");
    printf("\t\t5. Pesos MXN\n");
    printf("\t\t6. Cancel\n");
    printf("\n\tEnter your choice: ");
    ret = scanf("%d", &currency);
    clearInputBuffer();

    printf("\n\tEnter the amount you want to withdraw: ");
    ret = scanf("%d", &amount);
    clearInputBuffer();
    int flag_amount = check_amount(amount, currency, atm);

    switch (currency) {
    case 1:
      if (flag_amount == 1) {
        atm->users[atm->activeUser].account.galleons -= amount;
      }
      break;
    case 2:
      if (flag_amount == 1) {
        atm->users[atm->activeUser].account.sickles -= amount;
      }
      break;
    case 3:
      if (flag_amount == 1) {
        atm->users[atm->activeUser].account.knuts -= amount;
      }
      break;
    case 4:
      if (flag_amount == 1) {
        atm->users[atm->activeUser].account.usd -= amount;
      }
      break;
    case 5:
      if (flag_amount == 1) {
        atm->users[atm->activeUser].account.pesosMXN -= amount;
      }
      break;
    case 6:
      userScreen(atm);
      break;
    default:
      printf("\n\tInvalid selection\n");
      continue;
    }
    break; // Exit loop if a valid option is selected
  }
  printf("\n\tWithdraw successful.\n");
  printf("Press enter to return to the main menu.\n");
  getchar();
  clearScreen();
  userScreen(atm);
}

void userScreen(ATM *atm) {
  clearScreen();
  User *user = &atm->users[atm->activeUser];
  printf("\n==================WELCOME BACK==================\n");
  printf("Welcome, %s\n", user->name);
  printf("\n\t1. Deposit\n");
  printf("\n\t2. Transfer\n");
  printf("\n\t3. Check Balance\n");
  printf("\n\t4. MiniGame\n");
  printf("\n\t5. Withdraw\n");
  printf("\n\t6. invest\n");
  printf("\n\t7. Log Out\n");
  printf("\n\tSelect an option: ");

  int option, ret;
  ret = scanf("%d", &option);
  clearInputBuffer();
  while (1) {
    switch (option) {
    case 1:
      /* code */
      deposit(atm);
      break;
    case 2:
      transfer(atm);
      break;
    case 3:
      checkBalance(atm);
      break;
    case 4:
      magicGame(atm);
      break;
    case 5:
      withdraw(atm);
      break;
    case 6:
      invest(atm);
      break;
    case 7:
      atm->activeUser = -1;
      printf("Logged out successful.\n");
      printf("Press enter to redirect to the main menu\n");
      getchar();
      clearScreen();
      main();
      return;
    default:
      break;
    }
  }
}

void clearScreen() { printf("\033[2J\033[1;1H"); }

void magicGame(ATM *atm) {
  clearScreen();

  int number, userNumber, ret;

  // Generate a random number from 1 to 10
  srand(time(NULL));
  number = rand() % 10 + 1;

  printf("\n==================MAGIC GAME==================\n");
  printf("\n\n\tGuess a number from 1 to 10");
  printf("\n\tFor a chance to win $100,000 USD");
  printf("\n\n\tEnter your number: ");

  // Use %d for integer input
  ret = scanf("%d", &userNumber);
  clearInputBuffer();

  printf("\n\n\tThe magic number is: %d", number);

  if (userNumber == number) {
    printf("\n\tCongratulations! You won $10 USD");
    atm->users[atm->activeUser].account.usd += 10;
  } else {
    printf("\n\tSorry, you lost🙃");
    printf("\n\t$10 USD will be deducted from your account");
    if (atm->users[atm->activeUser].account.usd >= 10.0) {
      atm->users[atm->activeUser].account.usd -= 10.0;
    } else {
      printf("\n\tYou do not have enough money to play this game");
    }
  }

  printf("\n\n\tYour current balance is: $%.2f USD",
         atm->users[atm->activeUser].account.usd);
  printf("\n\n\tPress Enter to return to the main menu");
  getchar();
  clearScreen();
  userScreen(atm);
}

double calculateCompoundInterest(double principal, double rate, int years) {
  // Caso base: si la inversión dura 0 años, devuelve el principal
  if (years == 0) {
    return principal;
  }

  // Cálculo del interés compuesto para un año
  double amount = principal * pow(1 + rate, years);
  // No es necesario llamar a la función recursivamente, se calcula directamente
  return amount;
}

void invest(ATM *atm) {
  clearScreen();
  double principal;
  int years, ret;

  if (atm->activeUser == -1) {
    printf("You must be logged in to access this function\n");
    return;
  }

  printf("\n=====================INVESTMENT======================\n");
  printf("Enter the amount you want to invest: ");
  ret = scanf("%lf", &principal);
  clearInputBuffer();

  printf("Enter the number of years for the investment: ");
  ret = scanf("%d", &years);
  clearInputBuffer();

  // Cálculo del interés compuesto de forma recursiva
  double finalAmount = calculateCompoundInterest(principal, 0.05, years);

  // Agregar el monto final a los galeones del usuario
  atm->users[atm->activeUser].account.galleons += (int)finalAmount;

  printf("\n\tInvestment successful.\n");
  printf("Your final amount after %d years is: %.2f\n", years, finalAmount);

  printf("Press enter to return to the main menu.\n");
  getchar();
  clearScreen();
  userScreen(atm);
}
