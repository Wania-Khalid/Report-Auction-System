#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User {
protected:
    string username;
    string password;

public:
    User() {}

    User(string u, string p) {
        username = u;
        password = p;
    }

    // Setters
    void setUsername(string u) {
        username = u;
    }
    void setPassword(string p) {
        password = p;
    }

    // Getters
    string getUsername() {
        return username;
    }

    string getPassword() {
        return password;
    }

    // Pure virtual function 
    virtual void menu() = 0;
};

#endif