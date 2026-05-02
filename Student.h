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
        cout << "Student Menu:\n";
        cout << "1. View Items\n";
        cout << "2. Place Bid\n";
        cout << "3. Logout\n";
    }
};

#endif