// Client.cpp

#include "Client.h"
#include "Person.h"


#include <iostream>
using namespace std;


void Client::setBalance(double amount) {
    while (true) {
        if (balance >= 1500) {
            balance = amount;
            return;
        } else {
            std::cout << "Balance must be >= 1500" << std::endl;
            std::cout << "Enter balance: ";
            std::cin >> balance;
        }
    }
}

double Client::getBalance() {
    return balance;
}

void Client::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Deposit of $" << amount << " successful. New balance: $" << balance << std::endl;
    } else {
        std::cout << "Error: Invalid amount for deposit." << std::endl;
    }
}

void Client::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        std::cout << "Withdrawal of $" << amount << " successful. New balance: $" << balance << std::endl;
    } else {
        std::cout << "Error: Insufficient balance for withdrawal." << std::endl;
    }
}

void Client::transferTo(double amount, Client& receiver) {
    if (amount > 0) {
        if (balance >= amount) {
            balance -= amount;
            receiver.balance += amount;
            std::cout << "Transfer successful. New balance: $" << balance << std::endl;
        } else {
            std::cout << "Error: Insufficient balance for transfer." << std::endl;
        }
    } else {
        std::cout << "Error: Invalid amount for transfer." << std::endl;
    }
}

void Client::checkBalance() {
    std::cout << "Current balance: $" << balance << std::endl;
}

void Client::display() {
    cout << "Client Information:" << endl;
    cout << "ID: " << getId() << endl; // Using the getId() method from the base class
    cout << "Name: " << getName() << endl; // Using the getName() method from the base class
    cout << "Balance: $" << balance << endl;
    cout << "----------------------------------------------" << endl;
}

