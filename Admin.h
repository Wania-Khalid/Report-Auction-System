#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include "User.h"
using namespace std;

class Admin : public User {
public:
    Admin() : User() {}

    Admin(string u, string p) : User(u, p) {}

    // Overriding menu function
   void menu() override {
    int choice;

    do {
        cout << "\nAdmin Menu:\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "0. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Adding item...\n";
                break;

            case 2:
                cout << "Removing item...\n";
                break;

            case 0:
                cout << "Logging out...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 0);
}
};

#endif