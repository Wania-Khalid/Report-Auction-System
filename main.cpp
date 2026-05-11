#include <iostream>
#include "User.h"
#include "Student.h"
#include "Admin.h"
#include "Item.h"
using namespace std;

int main() {
    User* user;   // base class pointer

    Student s1("aqsa", "123", 101);
    Admin a1("admin", "admin123");
    Item item1(1, "Laptop", 50000);
    int choice;

    cout << "Login as:\n";
    cout << "1.Student , 2.Admin : ";
    cin >> choice;

    if (choice == 1) {
        user = &s1;
    } else {
        user = &a1;
    }

    user->menu();   // polymorphism happens here
    item1.displayItem();
item1.placeBid("Aqsa", 60000);
item1.displayItem();

    return 0;
}