
# Wizard Bank ATM System

Welcome to the Wizard Bank ATM system, a project inspired by the magical world of Harry Potter. This program allows users to perform banking operations and enjoy additional magical features.

## Project Overview

The Wizard Bank ATM system is designed to emulate the functionality of a real-world ATM with a magical twist. It enables users to register accounts, log in, deposit money, withdraw funds, check balances, and even play a magical minigame.

## Modules and Functions

### 1. Registration and Authentication Module

-   **registerUser():** Function to create a new bank account associated with a username, Hogwarts house, blood type, house seal, and PIN for account access.
    
-   **logIn():** Function to log in to an existing account by entering the username and PIN.
    

### 2. Banking Operations Module

-   **deposit():** Function to deposit a specified amount of money into the user's account in the chosen currency.
    
-   **withdraw():** Function to withdraw a specified amount of money from the user's account in the chosen currency.
    
-   **checkBalance():** Function to view the current balance of the user's account in all supported currencies.
    

### Additional Features

-   **Magical Minigame:** Users can play a magical minigame where they guess a number between 1 and 10. A correct guess earns $10 USD, while an incorrect guess results in a $10 USD deduction per attempt.

## Project Structure

### Structures for ATM Functionality

1.  **Transaction Structure:**
    
    -   Represents an individual financial transaction.
    -   Properties:
        -   `amount`: Transaction amount (double).
        -   `transactionId`: Unique transaction identifier (int).
        -   `transactionType`: Transaction type (string).
2.  **Account Structure:**
    
    -   Stores user account information.
    -   Properties:
        -   `accountType`: Account type (string).
        -   `galleons`, `sickles`, `knuts`: Balances in magical currency units (int).
        -   `pesosMXN`, `usd`: Balances in real-world currencies (double).
        -   `activeDuration`: Account active duration (int).
        -   `loanInterest`, `transactionFee`: Interest rate and transaction fee (double).
        -   `transactions`: Array to store transaction history (up to 100 transactions).
        -   `num_transactions`: Number of transactions stored.
3.  **User Structure:**
    
    -   Represents a user of the ATM system.
    -   Properties:
        -   `id`: Unique user identifier (int).
        -   `account`: User account information (Account).
        -   `username`, `pin`, `name`: User details (strings).
        -   `house`, `seal`, `bloodType`: Hogwarts house, seal, and blood type (strings).
4.  **ATM Structure:**
    
    -   Represents the entire ATM system.
    -   Properties:
        -   `users`: Array to store registered users (up to MAX_USERS).
        -   `num_users`: Number of registered users.
        -   `transactions`: Array to store transaction records (up to MAX_TRANSACTIONS).
        -   `num_transactions`: Number of recorded transactions.
        -   `activeUser`: Identifier of the currently logged-in user.

## Contributors

-   **Salvador Rodriguez Ceballos**
-   **Jose Emmanuel Pulido Tinajero**
-   **Rubén Erik Cepeda Barra**