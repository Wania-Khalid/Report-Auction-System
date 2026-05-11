#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class Item; // forward declaration

class User {
protected:
    string username;
    string password;

public:
    User() {}

    User(string u, string p) : username(u), password(p) {}

    // Getters
    string getUsername() const { return username; }
    string getPassword() const { return password; }

    virtual void menu(Item items[], int& itemCount) = 0;

    // Destructor
    virtual ~User() {
        cout << "[User] '" << username << "' destroyed.\n";
    }
};

#endif