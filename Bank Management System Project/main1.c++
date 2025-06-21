#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int accNum, double initialBalance) {
        accountHolder = name;
        accountNumber = accNum;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "₹" << amount << " deposited successfully.\n";
        } else {
            cout << "❌ Invalid deposit amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "❌ Invalid withdrawal amount!\n";
        } else if (amount > balance) {
            cout << "❌ Insufficient balance!\n";
        } else {
            balance -= amount;
            cout << "₹" << amount << " withdrawn successfully.\n";
        }
    }

    void displayAccount() {
        cout << "\n🔎 Account Details:\n";
        cout << "Account Holder: " << accountHolder << "\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Balance: ₹" << balance << "\n";
    }

    int getAccountNumber() const {
        return accountNumber;
    }
};

// Function to find account by account number
BankAccount* findAccount(vector<BankAccount>& accounts, int accNum) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accNum) {
            return &acc;
        }
    }
    return nullptr;
}

int main() {
    vector<BankAccount> accounts;
    int choice;

    while (true) {
        cout << "\n=== 🏦 Bank Management System ===\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Display Account Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int accNum;
            double initialBalance;
            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Initial Balance: ";
            cin >> initialBalance;

            // Check for duplicate account number
            if (findAccount(accounts, accNum) != nullptr) {
                cout << "❌ Account number already exists!\n";
            } else {
                accounts.push_back(BankAccount(name, accNum, initialBalance));
                cout << "✅ Account created successfully!\n";
            }
        }

        else if (choice == 2) {
            int accNum;
            double amount;
            cout << "Enter Account Number: ";
            cin >> accNum;
            BankAccount* acc = findAccount(accounts, accNum);

            if (acc != nullptr) {
                cout << "Enter Deposit Amount: ";
                cin >> amount;
                acc->deposit(amount);
            } else {
                cout << "❌ Account not found!\n";
            }
        }

        else if (choice == 3) {
            int accNum;
            double amount;
            cout << "Enter Account Number: ";
            cin >> accNum;
            BankAccount* acc = findAccount(accounts, accNum);

            if (acc != nullptr) {
                cout << "Enter Withdrawal Amount: ";
                cin >> amount;
                acc->withdraw(amount);
            } else {
                cout << "❌ Account not found!\n";
            }
        }

        else if (choice == 4) {
            int accNum;
            cout << "Enter Account Number: ";
            cin >> accNum;
            BankAccount* acc = findAccount(accounts, accNum);

            if (acc != nullptr) {
                acc->displayAccount();
            } else {
                cout << "❌ Account not found!\n";
            }
        }

        else if (choice == 5) {
            cout << "👋 Thank you for using the Bank Management System.\n";
            break;
        }

        else {
            cout << "❌ Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
