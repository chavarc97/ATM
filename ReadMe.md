# Bank Management System
## Project description:
The objective of this project is to develop a banking system inspired by the Harry Potter universe, where users can exchange real-world currencies such as Mexican Pesos, US Dollars, Euros, and British Pounds using a friendly and fun interface.

#### Scope:

The system will allow users to:

-   Register bank accounts associated with their names and Hogwarts houses.
-   Make deposits and withdrawals in supported currencies.
-   Convert between different currencies using up-to-date exchange rates.

## Project Structure
The project will be divided into the following main modules and functions:

1.  **Registration and Authentication Module:**
    
    -   `create_account()`: Function to create a new bank account associated with a username and Hogwarts house.
    -   `login()`: Function to log in to an existing account.
2.  **Banking Operations Module:**
    
    -   `deposit()`: Function to deposit a specified amount of money into the specified account in the indicated currency.
    -   `withdraw()`: Function to withdraw a specified amount of money from the specified account in the indicated currency.
    -   `check_balance()`: Function to check the current balance of an account in all supported currencies.
3.  **Currency Conversion Module:**
    
    -   `get_exchange_rate()`: Function to retrieve the exchange rate between two currencies.
    -   `convert_currency()`: Function to convert a specified amount of money from one currency to another.


## Function Details

#### Registration and Authentication Module

-   `create_account(name, house)`
    
    -   Description: This function allows the creation of a new bank account associated with the specified username and Hogwarts house.
    -   Parameters:
        -   `name`: Username of the user.
        -   `house`: Hogwarts house to which the user belongs.
    -   Return Value: Unique account ID for the newly created account.
-   `login(name)`
    
    -   Description: This function allows logging into an existing account.
    -   Parameters:
        -   `name`: Username of the user.
    -   Return Value: Valid session ID upon successful login.

#### Banking Operations Module

-   `deposit(account_id, amount, currency)`
    
    -   Description: Allows depositing a specified amount of money into the specified account in the indicated currency.
    -   Parameters:
        -   `account_id`: ID of the account to deposit into.
        -   `amount`: Amount of money to deposit.
        -   `currency`: Currency of the deposit (MXN, USD, EUR, GBP).
-   `withdraw(account_id, amount, currency)`
    
    -   Description: Allows withdrawing a specified amount of money from the specified account in the indicated currency.
    -   Parameters:
        -   `account_id`: ID of the account to withdraw from.
        -   `amount`: Amount of money to withdraw.
        -   `currency`: Currency of the withdrawal (MXN, USD, EUR, GBP).
-   `check_balance(account_id)`
    
    -   Description: Allows checking the current balance of an account in all supported currencies.
    -   Parameters:
        -   `account_id`: ID of the account to check.
    -   Return Value: Current balance in all supported currencies.

#### Currency Conversion Module

-   `get_exchange_rate(from_currency, to_currency)`
    
    -   Description: Retrieves the exchange rate between two currencies.
    -   Parameters:
        -   `from_currency`: Source currency.
        -   `to_currency`: Target currency.
    -   Return Value: Exchange rate from `from_currency` to `to_currency`.
-   `convert_currency(amount, from_currency, to_currency)`
    
    -   Description: Converts a specified amount of money from one currency to another using the current exchange rate.
    -   Parameters:
        -   `amount`: Amount of money to convert.
        -   `from_currency`: Source currency.
        -   `to_currency`: Target currency.
    -   Return Value: Converted amount in the `to_currency`.

