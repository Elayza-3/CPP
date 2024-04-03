#include <iostream>

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accNum, double initBalance) : accountNumber(accNum), balance(initBalance), interestRate(0.0) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
        else {
            std::cout << "Error: Invalid deposit amount" << std::endl;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            return true;
        }
        else {
            std::cout << "Error: Insufficient funds or invalid withdrawal amount" << std::endl;
            return false;
        }
    }
    void setInterestRate(double newRate) {
        interestRate = newRate;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    double getInterest() const {
        return balance * interestRate * (1.0 / 12.0);
    }

   

    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};

bool transfer(BankAccount& from, BankAccount& to, double amount)
{
    if (from.withdraw(amount)) {
        to.deposit(amount);
        return true;
    }
    else {
        return false;
    }
}

int main() {
    BankAccount acc1(5634536574, 1700.0);
    BankAccount acc2(6545645787, 800.0);

    acc1.deposit(900.0);
    acc1.withdraw(10.0);

    acc2.setInterestRate(0.01);
    double interestEarned = acc2.getInterest();

    bool success = transfer(acc1, acc2, 500.0);

    std::cout << "Account 1: " << acc1.getBalance() << std::endl;
    std::cout << "Account 2: " << acc2.getBalance() << std::endl;
    std::cout << "Interest Account 2: " << interestEarned << std::endl;

    if (success) {
        std::cout << "Transfer well" << std::endl;
    }
    else {
        std::cout << "Transfer bad" << std::endl;
    }

    return 0;
}
