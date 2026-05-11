#ifndef BID_H
#define BID_H

#include <iostream>
using namespace std;

// ABSTRACT CLASS (base for all bids)
class Bid {
protected:
    int    bidId;
    double amount;
    int    userId;
    int    itemId;

public:
    // Static data member (requirement: static data member)
    static int totalBids;

    // Constructor
    Bid(int id, double amt, int uid, int iid);

    // POLYMORPHISM (pure virtual → makes class abstract)
    virtual void display() const = 0;

    // Getters
    double getAmount()  const;
    int    getItemId()  const;

    // OPERATOR OVERLOADING (requirement: operator overloading)
    bool operator>(const Bid& b) const;

    // FRIEND FUNCTION (requirement: friend function)
    friend bool compareBids(const Bid& b1, const Bid& b2);

    // Destructor with output (requirement: destructor and object cleanup)
    virtual ~Bid() {
        cout << "[Bid #" << bidId << "] destroyed.\n";
    }
};

#endif
