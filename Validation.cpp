#include "Validation.h"

#include <cctype>

bool Validation::isAlphabetic(string str) {
    for (char c : str) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

bool Validation::isValidName(string name) {
    return name.length() >= 5 && name.length() <= 20 && isAlphabetic(name);
}

bool Validation::isValidPassword(string password) {
    return password.length() >= 8 && password.length() <= 20;
}
