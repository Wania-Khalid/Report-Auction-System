#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include "User.h"
#include "Item.h"
using namespace std;

class Admin : public User {
public:
    Admin(string u = "admin", string p = "admin") : User(u, p) {}

    void menu(Item items[], int &itemCount) override {
        int choice;

        do {
            cout << "\n--- ADMIN MENU ---\n";
            cout << "1. Add Item\n";
            cout << "2. View Items\n";
            cout << "0. Logout\n";
            cout << "Enter choice: ";
            cin >> choice;

            if (choice == 1) {
                int id;
                string name;
                float price;

                cout << "Enter Item ID: ";
                cin >> id;
                cout << "Enter Item Name: ";
                cin >> name;
                cout << "Enter Base Price: ";
                cin >> price;

                items[itemCount] = Item(id, name, price);
                itemCount++;

                cout << "Item added successfully!\n";
            }
            else if (choice == 2) {
                for (int i = 0; i < itemCount; i++) {
                    cout << "\nItem " << i + 1 << ":\n";
                    items[i].displayItem();
                }
            }

        } while (choice != 0);
    }
};

#endif