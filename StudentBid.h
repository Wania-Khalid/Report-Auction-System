#ifndef STUDENTBID_H
#define STUDENTBID_H

// ============================================================
// StudentBid.h
// Member 6 — Concrete Bid Implementation
//
// OOP Concepts:
//   - Inheritance     (StudentBid extends abstract Bid)
//   - Polymorphism    (overrides pure virtual display())
//   - Encapsulation   (adds bidderName field with getter)
//   - Dynamic Memory  (static factory uses new/delete)
// ============================================================

#include <iostream>
#include <string>
#include "Bid.h"
using namespace std;

class StudentBid : public Bid {
private:
    string bidderName;

public:
    // Constructor — passes base fields to Bid, stores bidderName
    StudentBid(int id, double amt, int uid, int iid, string name)
        : Bid(id, amt, uid, iid), bidderName(name) {}

    // POLYMORPHISM: overrides pure virtual from Bid
    void display() const override {
        cout << "  [BID #"     << bidId
             << "] Bidder: "   << bidderName
             << " | Amount: $" << amount
             << " | Item ID: " << itemId
             << " | User ID: " << userId
             << endl;
    }

    // Getters
    int    getBidId()      const { return bidId;      }
    string getBidderName() const { return bidderName;  }

    // -------------------------------------------------------
    // Static factory: creates a StudentBid on the heap,
    // displays it, then deletes it.
    // (requirement: dynamic memory allocation with new/delete)
    // -------------------------------------------------------
    static void createAndDisplay(int id, double amt, int uid,
                                 int iid, string name) {
        StudentBid* sb = new StudentBid(id, amt, uid, iid, name);
        sb->display();
        delete sb;   // destructor prints "[Bid #x] destroyed."
    }
};

#endif // STUDENTBID_H
