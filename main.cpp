#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Validation {
public:
    static bool isAlphabetic(string str) {
        for (char c : str) {
            if (!isalpha(c)) {
                return false;
            }
        }
        return true;
    }

    static bool isValidName(string name) {
        return name.length() >= 5 && name.length() <= 20 && isAlphabetic(name);
    }

    static bool isValidPassword(string password) {
        return password.length() >= 8 && password.length() <= 20;
    }
};

class Person {
protected:
    int id;
    string name;
    string password;
public:
    Person(int id, string name, string password)
        : id(id), name(name), password(password) {}

    virtual ~Person() {} // Virtual destructor

    // setter functions
    void setId(int id) {
        this->id = id;
    }

    void setName(string newName) {
        if (Validation::isValidName(newName) && Validation::isAlphabetic(newName)) {
            name = newName;
        } else {
            cout << "Invalid name! The name must be alphabetic chars and min size 5 and max size 20" << endl;
        }
    }

    void setPassword(string newPassword) {
        if (Validation::isValidPassword(newPassword)) {
            password = newPassword;
        } else {
            cout << "Invalid password! The password must be min size 8 and max size 20" << endl;
        }
    }

    // Getter functions
    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    string getPassword() const {
        return password;
    }
};

class Client : public Person {
private:
    double balance;
public:
    Client(int id, string name, string password, double balance)
        : Person(id, name, password), balance(balance) {}

    // setter function
    void setBalance(double amount) {
        if (amount >= 1500) {
            balance = amount;
        } else {
            cout << "Balance must be >= 1500" << endl;
        }
    }

    // Getter function
    double getBalance() const {
        return balance;
    }

    // Deposit
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit of $" << amount << " successful. New balance: $" << balance << endl;
        } else {
            cout << "Error: Invalid amount for deposit." << endl;
        }
    }

    // Withdraw
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawal of $" << amount << " successful. New balance: $" << balance << endl;
        } else {
            cout << "Error: Insufficient balance for withdrawal." << endl;
        }
    }

    // Transfer function
    void transferTo(double amount, Client& receiver) {
        if (amount > 0) {
            if (balance >= amount) {
                balance -= amount;
                receiver.balance += amount;
                cout << "Transfer successful. New balance: $" << balance << endl;
            } else {
                cout << "Error: Insufficient balance for transfer." << endl;
            }
        } else {
            cout << "Error: Invalid amount for transfer." << endl;
        }
    }

    // Check balance
    void checkBalance() const {
        cout << "Current balance: $" << balance << endl;
    }

    // Display function
    void display() const {
        cout << "Client Information:" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: $" << balance << endl;
        cout << "----------------------------------------------" << endl;
    }
};

class Employee : public Person {
protected:
    double salary;
public:
    Employee(int id, string name, string password, double salary)
        : Person(id, name, password), salary(salary) {}

    // Setter function
    void setSalary(double salary) {
        if (salary >= 5000) {
            this->salary = salary;
        } else {
            cout << "Salary must be >= 5000" << endl;
        }
    }

    // Getter function
    double getSalary() const {
        return salary;
    }

    // Display function
    void display() const {
        cout << "Employee Information:" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Password: " << password << endl;
        cout << "Salary: $" << salary << endl;
        cout << "----------------------------------------------" << endl;
    }
};

class Admin : public Employee {
public:
    Admin(int id, string name, string password, double salary)
        : Employee(id, name, password, salary) {}

    // Display function
    void display() const {
        cout << "Admin Information:" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Password: " << password << endl;
        cout << "Salary: $" << salary << endl;
        cout << "----------------------------------------------" << endl;
    }
};

class DataSourceInterface {
public:
    virtual void addClient(Client) = 0;
    virtual void addEmployee(Employee) = 0;
    virtual void addAdmin(Admin) = 0;
    virtual void getAllClients() = 0;
    virtual void getAllEmployees() = 0;
    virtual void getAllAdmins() = 0;
    virtual void removeAllClients() = 0;
    virtual void removeAllEmployees() = 0;
    virtual void removeAllAdmins() = 0;
};
class Parser {
private:
    static vector<string> split(string line) {
        stringstream stream(line);
        string token;
        vector<string> info;
        while (getline(stream, token, '&')) {
            info.push_back(token);
        }
        return info;
    }

public:
    static Client parseToClient(string line) {
        vector<string> info = split(line);
        Client client(stoi(info[0]), info[1], info[2], stod(info[3]));
        return client;
    }

    static Employee parseToEmployee(string line) {
        vector<string> info = split(line);
        Employee employee(stoi(info[0]), info[1], info[2], stod(info[3]));
        return employee;
    }

    static Admin parseToAdmin(string line) {
        vector<string> info = split(line);
        Admin admin(stoi(info[0]), info[1], info[2], stod(info[3]));
        return admin;
    }
};

class FilesHelper : public DataSourceInterface {
private:
    static vector<Client> allClients;
    static vector<Employee> allEmployees;
    static vector<Admin> allAdmins;

    static void saveLast(string fileName, int id) {
        ofstream file;
        file.open(fileName);
        file << id;
        file.close();
    }
   friend class ClientManager;

public:
    static int getLast(string fileName) {
        ifstream file;
        file.open(fileName);
        int id;
        file >> id;
        file.close();
        return id;
    }

    void addClient(Client c) {
        int id = getLast("ClientId.txt");
        fstream file;
        file.open("Clients.txt", ios::app);
        file << id + 1 << '&' << c.getName() << '&' << c.getPassword() << '&' << c.getBalance() << "\n";
        file.close();
        saveLast("ClientId.txt", id + 1);
        allClients.push_back(c);
    }

    void addEmployee(Employee e) {
        int id = getLast("EmployeeId.txt");
        fstream file;
        file.open("Employees.txt", ios::app);
        file << id + 1 << '&' << e.getName() << '&' << e.getPassword() << '&' << e.getSalary() << "\n";
        file.close();
        saveLast("EmployeeId.txt", id + 1);
        allEmployees.push_back(e);
    }

    void addAdmin(Admin a) {
        int id = getLast("AdminId.txt");
        fstream file;
        file.open("Admins.txt", ios::app);
        file << id + 1 << '&' << a.getName() << '&' << a.getPassword() << '&' << a.getSalary() << "\n";
        file.close();
        saveLast("AdminId.txt", id + 1);
        allAdmins.push_back(a);
    }

    void getAllClients() {
        string line;
        ifstream file;
        file.open("Clients.txt");
        while (getline(file, line)) {
            Client c = Parser::parseToClient(line);
            allClients.push_back(c);
        }
        file.close();
    }

    void getAllEmployees() {
        string line;
        ifstream file;
        file.open("Employees.txt");
        while (getline(file, line)) {
            Employee e = Parser::parseToEmployee(line);
            allEmployees.push_back(e);
        }
        file.close();
    }

    void getAllAdmins() {
        string line;
        ifstream file;
        file.open("Admins.txt");
        while (getline(file, line)) {
            Admin a = Parser::parseToAdmin(line);
            allAdmins.push_back(a);
        }
        file.close();
    }

    void removeAllClients() {
        allClients.clear();
        clearFile("Clients.txt", "ClientId.txt");
    }

    void removeAllEmployees() {
        allEmployees.clear();
        clearFile("Employees.txt", "EmployeeId.txt");
    }

    void removeAllAdmins() {
        allAdmins.clear();
        clearFile("Admins.txt", "AdminId.txt");
    }

    // Other utility functions (not shown in this code snippet)

private:
    static void clearFile(string fileName, string lastIdFile) {
        fstream file1, file2;
        file1.open(fileName, ios::out | ios::trunc);
        file1.close();
        file2.open(lastIdFile, ios::out);
        file2 << 0;
        file2.close();
    }
};
vector<Client> FilesHelper::allClients;
vector<Employee> FilesHelper::allEmployees;
vector<Admin> FilesHelper::allAdmins;

class ClientManager {
public:
    // Print Client Menu
    static void printClientMenu() {
        cout << "===== Client Menu =====" << endl;
        cout << "1. Update Password" << endl;
        cout << "2. Check Balance" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Transfer Money" << endl;
        cout << "6. Logout" << endl;
        cout << "=======================" << endl;
    }

    // Update Password
    static void updatePassword(Person* person) {
        string newPassword;
        cout << "Enter new password: ";
        cin >> newPassword;
        person->setPassword(newPassword);
        cout << "Password updated successfully!" << endl;
    }

    // Login
    // Client Options
    static Client* login(int id, string password) {
    for (Client& client : FilesHelper::allClients) {
        if (client.getId() == id && client.getPassword() == password) {
            cout << "Login successful. Welcome, " << client.getName() << "!" << endl;
            return &client;
        }
    }

    cout << "Login failed. Invalid ID or password." << endl;
    return nullptr;
   }


    // Client Options
    static bool clientOptions(Client* client) {
        int choice;
        cout << "Welcome, " << client->getName() << "!" << endl;
        while (true) {
            printClientMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    updatePassword(client);
                    break;
                case 2:
                    client->checkBalance();
                    break;
                case 3: {
                    double amount;
                    cout << "Enter the amount to deposit: ";
                    cin >> amount;
                    client->deposit(amount);
                    break;
                }
                case 4: {
                    double amount;
                    cout << "Enter the amount to withdraw: ";
                    cin >> amount;
                    client->withdraw(amount);
                    break;
                }
                case 5: {
                    int receiverId;
                    double amount;
                    cout << "Enter the receiver's ID: ";
                    cin >> receiverId;
                    cout << "Enter the amount to transfer: ";
                    cin >> amount;
                    // Find the receiver client using the receiverId from the data source
                    Client* receiver = findClientById(receiverId);
                    if (receiver != nullptr) {
                        client->transferTo(amount, *receiver);
                    } else {
                        cout << "Receiver with ID " << receiverId << " not found." << endl;
                    }
                    break;
                }
                case 6:
                    cout << "Logging out. Goodbye, " << client->getName() << "!" << endl;
                    return true; // Indicates the client has logged out
                default:
                    cout << "Invalid choice. Try again." << endl;
            }
        }
    }

    // Helper function to find a client by ID
    static Client* findClientById(int id) {
        for (Client& client : FilesHelper::allClients) {
            if (client.getId() == id) {
                return &client;
            }
        }
        return nullptr;
    }
};

// ... (rest of the classes and main function from the previous code)
int main() {
    // Creating DataSource instance
    FilesHelper dataSource;

    // Clients
    Client c1(1, "Mahmoud Mekkawy", "12345678", 1000);
    Client c2(2, "Mostafa Mohamed", "12345678", 3000);
    c1.display();
    c2.display();
    c1.setBalance(4000);
    c1.display();
    c1.withdraw(1000);
    c1.transferTo(2000, c2);
    cout << "----------------------------------------------" << endl;
    c2.display();

    // Employee
    Employee emp(1, "Mustafa Nasser", "12345678", 5000);
    emp.setSalary(5000);
    emp.display();

    // Admin
    Admin admin(1, "Mekkawy", "12345678", 10000);
    admin.display();

    // Adding clients, employees, and admins to the data source
    dataSource.addClient(c1);
    dataSource.addClient(c2);
    dataSource.addEmployee(emp);
    dataSource.addAdmin(admin);

    return 0;
}
