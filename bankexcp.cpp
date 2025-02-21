#include <iostream>
#include <stdexcept>
using namespace std;

class InsufficientFundsException : public exception {
public:
    const char* what() const noexcept override {
        return "Insufficient funds in your account!";
    }
};

class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    BankAccount(const string& name, double initialBalance) {
        if (initialBalance < 0) {
            throw invalid_argument("Initial balance cannot be negative!");
        }
        accountHolder = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Deposit amount must be positive!");
        }
        balance += amount;
        cout << "Successfully deposited $" << amount << ". New balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Withdrawal amount must be positive!");
        }
        if (amount > balance) {
            throw InsufficientFundsException();
        }
        balance -= amount;
        cout << "Successfully withdrew $" << amount << ". New balance: $" << balance << endl;
    }

    void displayBalance() const {
        cout << "Account Holder: " << accountHolder << ", Balance: $" << balance << endl;
    }
};

int main() {
    try {
        cout << "Creating a new bank account..." << endl;
        BankAccount account("John Doe", 500.0); // Initial balance of $500
        account.displayBalance();

        // Depositing money
        cout << "\nDepositing $200..." << endl;
        account.deposit(200);

        // Attempting to withdraw a valid amount
        cout << "\nWithdrawing $300..." << endl;
        account.withdraw(300);

        // Attempting to withdraw more than the balance
        cout << "\nWithdrawing $500..." << endl;
        account.withdraw(500); // This will throw the user-defined exception

    } catch (const invalid_argument& e) {
        cout << "Standard Exception: " << e.what() << endl;
    } catch (const InsufficientFundsException& e) {
        cout << "User-Defined Exception: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "General Exception: " << e.what() << endl;
    }

    cout << "\nProgram ended gracefully." << endl;
    return 0;
}
