#include <iostream>
using namespace std;

// Function Prototypes
void showMenu();
void checkBalance(double balance);
double depositMoney(double balance);
double withdrawMoney(double balance);

int main() {
    int pin = 1234;
    int enteredPin;
    double balance = 10000;
    int choice;
    bool running = true;

    cout << "===== SIMPLE ATM MACHINE =====\n";
    cout << "Enter your PIN: ";
    cin >> enteredPin;

    // PIN Verification
    if (enteredPin != pin) {
        cout << "Invalid PIN! Access Denied.\n";
        return 0;
    }

    cout << "\nLogin Successful!\n";

    // Menu Loop
    while (running) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            checkBalance(balance);
            break;

        case 2:
            balance = depositMoney(balance);
            break;

        case 3:
            balance = withdrawMoney(balance);
            break;

        case 4:
            cout << "Thank you for using ATM. Goodbye!\n";
            running = false;
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

// Function to display ATM menu
void showMenu() {
    cout << "\n----- ATM MENU -----\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Exit\n";
}

// Function to check balance
void checkBalance(double balance) {
    cout << "Your current balance is: Rs. " << balance << endl;
}

// Function to deposit money
double depositMoney(double balance) {
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;

    if (amount > 0) {
        balance += amount;
        cout << "Deposit successful!\n";
    }
    else {
        cout << "Invalid amount!\n";
    }

    return balance;
}

// Function to withdraw money
double withdrawMoney(double balance) {
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Please collect your cash.\n";
    }
    else {
        cout << "Insufficient balance or invalid amount!\n";
    }

    return balance;
}
