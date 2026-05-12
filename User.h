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

<<<<<<< HEAD
    // Destructor
    virtual ~User() {
        cout << "[User] '" << username << "' destroyed.\n";
    }
};

#endif
=======
   // Destructor with visible output - Only prints for valid users
    virtual ~User() {
        if (!username.empty()) {
            cout << "[User] '" << username << "' destroyed.\n";
        }
    }
};

#endif
>>>>>>> dd683dcfd25b287630a973268b86dfd21b895154
