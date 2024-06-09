#include <iostream>
#include <string>
using namespace std;

class BankManager; // Forward declaration

class BankAccount {
private:
    int accountNumber;
    string accountHolder;
    double balance;
    static int totalAccount;
    
public:
    // Constructor
    BankAccount(int ac = 1, string aH = "N/A", double b = 0.0)
        : accountNumber(ac), accountHolder(aH), balance(b) {
        totalAccount++;
    }
    
    // Member functions
    void deposit(double amount) {
        balance += amount;
        cout << "Deposit of " << amount << " successful. Current balance: " << balance << endl;
    }
    
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawal of " << amount << " successful. Current balance: " << balance << endl;
        } else {
            cout << "Insufficient funds for withdrawal." << endl;
        }
    }
    
    double getBalance() {
        return balance;
    }
    
    int getAccountNumber() {
        return accountNumber;
    }
    
    static int getTotalAccounts() {
        return totalAccount;
    }

    string getHolderName() { // Added getter function for account holder name
        return accountHolder;
    }

    void transferFunds(BankAccount& receiver, double amount) {
        if (balance >= amount) {
            withdraw(amount);
            receiver.deposit(amount);
            cout << "Transfer of " << amount << " to account " << receiver.getAccountNumber() << " successful." << endl;
        } else {
            cout << "Insufficient funds for transfer." << endl;
        }
    }
};

int BankAccount::totalAccount = 0;

class BankManager {
private:
    BankAccount* accounts[100];
    int numAccounts;

public:
    // Constructor
    BankManager() : numAccounts(0) {}

    // Destructor to deallocate memory
    ~BankManager() {
        for (int i = 0; i < numAccounts; ++i) {
            delete accounts[i];
        }
    }

    // Member functions
    BankAccount* createAccount(string accountHolderName, double initialBalance) {
        BankAccount* newAccount = new BankAccount(BankAccount::getTotalAccounts() + 1, accountHolderName, initialBalance);
        accounts[numAccounts++] = newAccount;
        cout << "Account created with account number " << newAccount->getAccountNumber() << endl;
        return newAccount;
    }

    void deleteAccount(int accountNumber) {
        for (int i = 0; i < numAccounts; ++i) {
            if (accounts[i]->getAccountNumber() == accountNumber) {
                delete accounts[i];
                for (int j = i; j < numAccounts - 1; ++j) {
                    accounts[j] = accounts[j + 1];
                }
                --numAccounts;
                cout << "Account with account number " << accountNumber << " deleted successfully." << endl;
                return;
            }
        }
        cout << "Account with account number " << accountNumber << " not found." << endl;
    }

    BankAccount* findAccount(int accountNumber) {
        for (int i = 0; i < numAccounts; ++i) {
            if (accounts[i]->getAccountNumber() == accountNumber) {
                return accounts[i];
            }
        }
        return nullptr;
    }

    void displayAllAccounts() {
        cout << "Total number of accounts: " << numAccounts << endl;
        for (int i = 0; i < numAccounts; ++i) {
            cout << "Account Number: " << accounts[i]->getAccountNumber() << ", Holder Name: " << accounts[i]->getHolderName() << ", Balance: " << accounts[i]->getBalance() << endl;
        }
    }
};

int main() {
    BankManager manager;
    char choice = 'Y';
    
    while (choice == 'Y') {
        int option;
        cout << "1. Create Account\n2. Delete Account\n3. Find Account\n4. Display All Accounts\nEnter your choice: ";
        cin >> option;

        switch (option) {
            case 1: {
                string name;
                double initialBalance;
                cout << "Enter account holder name: ";
                cin >> name;
                cout << "Enter initial balance: ";
                cin >> initialBalance;
                manager.createAccount(name, initialBalance);
                break;
            }
            case 2: {
                int accountNumber;
                cout << "Enter account number to delete: ";
                cin >> accountNumber;
                manager.deleteAccount(accountNumber);
                break;
            }
            case 3: {
                int accountNumber;
                cout << "Enter account number to find: ";
                cin >> accountNumber;
                BankAccount* account = manager.findAccount(accountNumber);
                if (account != nullptr) {
                    cout << "Account found. Account Holder: " << account->getHolderName() << ", Balance: " << account->getBalance() << endl;
                } else {
                    cout << "Account not found." << endl;
                }
                break;
            }
            case 4:
                manager.displayAllAccounts();
                break;
            default:
                cout << "Invalid option selected." << endl;
        }

        cout << "Do you want to continue (Y/N): ";
        cin >> choice;
    }

    return 0;
}
