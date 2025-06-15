#include <iostream>
using namespace std;

class ATM {
private:
    float balance;
    const int PIN = 1234;

public:
    ATM() {
        balance = 1000.00; 
    }

    bool authenticate() {
        int enteredPIN, attempts = 0, maxAttempts = 3;

        while (attempts < maxAttempts) {
            cout << "Enter your PIN: ";
            cin >> enteredPIN;

            if (enteredPIN == PIN) {
                cout << "Authentication successful.\n";
                return true;
            } else {
                attempts++;
                cout << "Incorrect PIN. You have " << (maxAttempts - attempts) << " attempt(s) left.\n";
            }
        }
        return false;
    }

    void displayMenu() {
        cout << "\n======== ATM Menu ========\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "==========================\n";
    }

    void checkBalance() {
        cout << "\nYour current balance is: $" << balance << "\n";
    }

    void depositMoney() {
        float amount;
        cout << "\nEnter amount to deposit: $";
        cin >> amount;

        if (amount <= 0) {
            cout << "Invalid amount! Please enter a positive number.\n";
        } else {
            balance += amount;
            cout << "Deposit successful. New balance: $" << balance << "\n";
        }
    }

    void withdrawMoney() {
        float amount;
        cout << "\nEnter amount to withdraw: $";
        cin >> amount;

        if (amount <= 0) {
            cout << "Invalid amount! Please enter a positive number.\n";
        } else if (amount > balance) {
            cout << "Insufficient funds! Current balance: $" << balance << "\n";
        } else {
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << balance << "\n";
        }
    }
};

int main() {
    ATM atm;
    int choice;

    cout << "=== Welcome to the ATM System ===\n";

    if (!atm.authenticate()) {
        cout << "Too many incorrect attempts. Exiting...\n";
        return 0;
    }

    do {
        atm.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                atm.checkBalance();
                break;
            case 2:
                atm.depositMoney();
                break;
            case 3:
                atm.withdrawMoney();
                break;
            case 4:
                cout << "Thank you for using the ATM. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
