# BankAccount Class 

A C++ class for multiple bank accounts and management.

## Data Dictionary

| Attribute      | Data Type     | Description                    |
|--------------- |---------------|--------------------------------|
| `accountNumber`| `std::string` | The bank accounts number.      |
| `accountName`  | `std::string` | The bank account holder name.  |
| `balance`      | `double`      | The bank account's balance.    |

## Methods List

| Method Signature                    | Return Type   | Description                              |
|-------------------------------------|---------------|------------------------------------------|
| `BankAccount()`                     | (Constructor) | Default constructor.                     |
| `BankAccount(name, number, money)`  | (Constructor) | Parameterized constructor.               |
| `SetName(name)`                     | `void`       | Changes the selected accounts name.      |
| `GetName()`                         | `std::string` | Returns the selected account's name.      |
| `GetNumber()`                       | `std::string` | Returns the selected account's number.   |
| `GetBalance()`                      | `double`      | Returns the selected account's balance.  |
| `Deposit(amount)`                   | `void`        | Adds to account balance by amount.       |
| `Withdraw(amount)`                  | `void`        | Subtracts the account balance by amount. |
