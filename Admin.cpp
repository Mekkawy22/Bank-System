#include "Admin.h"

#include <iostream>

Admin::Admin(int id,string name, string password, double salary)
    : Employee(id, name, password, salary) {}

void Admin::addEmployee(Employee& employee) {
    employees.push_back(employee);
    cout << "Employee added." << endl;
}

Employee* Admin::searchEmployee(int id) {
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].getId() == id) {
            return &employees[i];
        }
    }
    return nullptr;
}

void Admin::editEmployee(int id,string name,string password, double salary) {
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].getId() == id) {
            employees[i].setName(name);
            employees[i].setPassword(password);
            employees[i].setSalary(salary);
            cout << "Employee information updated." << endl;
            return;
        }
    }
    cout << "Employee not found." << endl;
}

void Admin::listEmployees() {
    for (int i = 0; i < employees.size(); i++) {
        cout << "ID: " << employees[i].getId() << ", Name: " << employees[i].getName() << ", Salary: $" << employees[i].getSalary() << endl;
    }
}

void Admin::display() {
   cout << "Admin Information:" << endl;
   cout << "ID: " << id << endl;
   cout << "Name: " << name << endl;
   cout << "Password: " << password << endl;
   cout << "Salary: $" << salary << endl;
   cout << "----------------------------------------------" << endl;
}
