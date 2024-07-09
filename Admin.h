#ifndef ADMIN_H
#define ADMIN_H

#include "Employee.h"

#include <vector>

class Admin : public Employee {
private:
    vector<Employee> employees;

public:
    Admin(int id, string name, string password, double salary);
    void addEmployee(Employee& employee);
    Employee* searchEmployee(int id);
    void editEmployee(int id, string name, string password, double salary);
    void listEmployees();
    void display();
};

#endif // ADMIN_H
