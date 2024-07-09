#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include "Client.h"

#include <vector>
#include<string>
using namespace std;


class Employee : public Person {
protected:
    double salary;
    vector<Client> clients;

public:
    Employee(int id,string name,string password, double salary);
    void setSalary(double salary);
    double getSalary();
    void addClient(Client& client);
    Client* searchClient(int id);
    void listClients();
    void editClient(int id,string name, string password, double balance);
    void display();
};

#endif // EMPLOYEE_H
