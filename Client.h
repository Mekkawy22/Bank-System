// Client.h

#ifndef CLIENT_H
#define CLIENT_H
#include<iostream>

#include "Person.h" // Make sure to include the Person header

class Client : public Person {
private:
    double balance;

public:
    // Constructor
    Client(int id, std::string name, std::string password, double balance);

    // Member functions
    void setBalance(double amount);
    double getBalance();
    void deposit(double amount);
    void withdraw(double amount);
    void transferTo(double amount, Client& receiver);
    void checkBalance();
    void display();
};

#endif // CLIENT_H
