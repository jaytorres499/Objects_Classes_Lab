#include <iostream>
using namespace std;
#include <vector>

class BankAccount {
    public:
        BankAccount();
        BankAccount(string name, string number, double money) {
            accountName = name;
            accountNumber = number;
            balance = money;;
        }
        //Setters
        void SetName(string name) {
            accountName = name;
        }
        //Getters
        string GetName() {
            return accountName;
        }
        string GetNumber() {
            return accountNumber;
        }
        double GetBalance() {
            return balance;
        }
        //Deposit/Withdraw Functions
        void Deposit(double amount) {
            balance += amount;
        }
        void Withdraw(double amount) {
            balance -= amount;
        }

    private:
        string accountNumber;
        string accountName;
        double balance;

};


int main() {
    vector<BankAccount> accounts;
    int choice;
    int viewAccount;
    int accountChoice;
    double amountChange;
    string accountNameInput;
    double accountBalanceInput;
    string accountNumberInput;

    do {
        cout << "Bank Account Manager" << endl;
        cout << "1. Create Account" << endl << "2. View Accounts" << endl << "3. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account name:" << endl;
                cin >> accountNameInput;
                cout << "Enter account number:" << endl;
                cin >> accountNumberInput;
                cout << "Enter account balance:" << endl;
                cin >> accountBalanceInput;
                accounts.push_back(BankAccount(accountNameInput, accountNumberInput, accountBalanceInput));
                cout << "Created Account " << accountNameInput << " with account number " << accountNumberInput << endl;
                break;
            case 2:
                cout << "Choose account to view:" << endl;
                for (int i = 0; i < accounts.size(); i++) {
                    cout << i + 1 << ". " << accounts[i].GetName() << endl;
                }
                cin >> viewAccount;
                if (viewAccount > accounts.size()) {
                    cout << "Invalid account number" << endl;
                    break;
                }
                accountChoice = 0;
                while (accountChoice != -1) {
                    cout << "Account Name: " << accounts[viewAccount - 1].GetName() << endl;
                    cout << "Account Number: " << accounts[viewAccount - 1].GetNumber() << endl;
                    cout << "Account Balance: " << accounts[viewAccount - 1].GetBalance() << endl << endl;
                    cout << "1. Change Name" << endl << "2. Deposit" << endl << "3. Withdraw" << endl << "-1. Exit" << endl;
                    cin >> accountChoice;
                    if (accountChoice > 3 || accountChoice < -1) {
                        cout << "Invalid Choice" << endl;
                    }
                    else if (accountChoice == 1) {
                        cout << "Enter new account name:" << endl;
                        cin >> accountNameInput;
                        accounts[viewAccount - 1].SetName(accountNameInput);
                    }
                    else if (accountChoice == 2) {
                        cout << "Enter amount to deposit:" << endl;
                        cin >> amountChange;
                        accounts[viewAccount - 1].Deposit(amountChange);
                    }
                    else if (accountChoice == 3) {
                        cout << "Enter amount to withdraw:" << endl;
                        cin >> amountChange;
                        if (accounts[viewAccount - 1].GetBalance() < amountChange) {
                            cout << "Insufficient Funds" << endl;
                        }
                        else {
                            accounts[viewAccount - 1].Withdraw(amountChange);
                            cout << "New Balance: " << accounts[viewAccount - 1].GetBalance() << endl;
                        }
                    }
                }
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
        }
    }while (choice != 3); {
        return 0;
    }
}