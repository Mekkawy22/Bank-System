#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>
using namespace std;


class Validation {
public:
    static bool isAlphabetic(string str);
    static bool isValidName(string name);
    static bool isValidPassword(string password);
};

#endif // VALIDATION_H
