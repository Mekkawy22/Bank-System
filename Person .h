// Person.h

#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    int id;
    std::string name;
    std::string password;

public:
    // Constructors
       Person(int id,string name,string password);

    // Getters and Setters
    void setId(int id);
    void setName(std::string name);
    void setPassword(std::string password);
    int getId() const;
    std::string getName() const;
    std::string getPassword() const;
};

#endif // PERSON_H
