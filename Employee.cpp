#include "Employee.h"

#include <iostream>

Employee::Employee(int id, string name, string password, double salary)
    : Person(id, name, password), salary(salary) {}

void Employee::setSalary(double salary) {
    while (true) {
        if (salary >= 5000) {
            this->salary = salary;
            return;
        } else {
            cout << "Salary must be >= 5000" << endl;
            cout << "Enter salary: ";
            cin >> salary;
        }
    }
}

double Employee::getSalary() {
    return salary;
}

void Employee::addClient(Client& client) {
    clients.push_back(client);
    cout << "Client added." << endl;
}

Client* Employee::searchClient(int id) {
    for (int i = 0; i < clients.size(); i++) {
        if (clients[i].getId() == id) {
            return &clients[i];
        }
    }
    return nullptr;
}

void Employee::listClients() {
    for (int i = 0; i < clients.size(); i++) {
        cout << "ID: " << clients[i].getId() << ", Name: " << clients[i].getName() << ", Balance: $" << clients[i].getBalance() << endl;
    }
}

void Employee::editClient(int id, string name, string password, double balance) {
    for (int i = 0; i < clients.size(); i++) {
        if (clients[i].getId() == id) {
            clients[i].setName(name);
            clients[i].setPassword(password);
            clients[i].setBalance(balance);
            cout << "Client information updated." << endl;
            return;
        }
    }
    cout << "Client not found." << endl;
}

void Employee::display() {
    cout << "Employee Information:" << endl;
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Password: " << password << endl;
    cout << "Salary: $" << salary << endl;
    cout << "----------------------------------------------" <<endl;
}
