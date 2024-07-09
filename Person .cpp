// Person.cpp
#include <iostream>
#include<string>
using namespace std;


#include "Person.h"


// Parameterized constructor




// Getters and Setters
void Person::setId(int id) {
    id = id;
}

void Person::setName(std::string name) {
    this->name = name;
}

void Person::setPassword(std::string password) {
    this->password = password;
}

int Person::getId() const {
    return id;
}

std::string Person::getName() const {
    return name;
}

std::string Person::getPassword() const {
    return password;
}
