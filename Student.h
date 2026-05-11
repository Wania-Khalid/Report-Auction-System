#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "User.h"
#include "Item.h"
using namespace std;

class Student : public User {
private:
    string studentID;

public:
    // Default / parameterized constructor 
    Student(string u = "", string p = "", string id = "")
        : User(u, p), studentID(id) {}

    // Copy constructor
    Student(const Student& other)
        : User(other.username, other.password), studentID(other.studentID) {
        cout << "[Student] Copy constructor called for '" << username << "'.\n";
    }

    // Getter
    string getStudentID() const { return studentID; }

    // Setter using 'this' pointer 
    void setStudentID(string studentID) { this->studentID = studentID; }

    void menu(Item items[], int& itemCount) override {
        int choice;
        do {
            cout << "\n--- STUDENT MENU ---\n";
            cout << "1. View Items\n";
            cout << "2. Place Bid\n";
            cout << "0. Logout\n";
            cout << "Enter choice: ";
            cin >> choice;

            if (choice == 1) {
                for (int i = 0; i < itemCount; i++) {
                    cout << "\nItem " << i + 1 << ":\n";
                    items[i].displayItem();
                }
            }
            else if (choice == 2) {
                int itemIndex;
                cout << "\nAvailable Items:\n";
                for (int i = 0; i < itemCount; i++) {
                    cout << i + 1 << ". ";
                    items[i].displayItem();
                    cout << endl;
                }
                cout << "Select item number: ";
                cin >> itemIndex;
                if (itemIndex < 1 || itemIndex > itemCount) {
                    cout << "Invalid item!\n";
                    continue;
                }
                float bid;
                cout << "Enter your bid: ";
                cin >> bid;
                items[itemIndex - 1].placeBid(username, bid);
            }

        } while (choice != 0);
    }
};

#endif