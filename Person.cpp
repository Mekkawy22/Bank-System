#include "Person.h"

class Person {
protected:
    int id;
    string name;
    string password;
public:
    Person(int id,string name,string password)
        : id(id), name(name), password(password) {}

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
