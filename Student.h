#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "User.h"
using namespace std;

class Student : public User {
private:
    int studentID;

public:
    Student() : User() {
        studentID = 0;
    }

    Student(string u, string p, int id) : User(u, p) {
        studentID = id;
    }

    void setStudentID(int id) {
        studentID = id;
    }

    int getStudentID() {
        return studentID;
    }

    // Overriding virtual function
    void menu() override {
    int choice;

    do {
        cout << "\nStudent Menu:\n";
        cout << "1. View Items\n";
        cout << "2. Place Bid\n";
        cout << "0. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Showing items...\n";
                break;

            case 2:
                cout << "Placing bid...\n";
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