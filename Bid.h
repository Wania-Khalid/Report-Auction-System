#ifndef BID_H
#define BID_H

#include <iostream>
using namespace std;

// ABSTRACT CLASS (base for all bids)
class Bid {
protected:
    int bidId;
    double amount;
    int userId;
    int itemId; 

public:
    static int totalBids;

    // Constructor
    Bid(int id, double amt, int uid, int iid); // ADDED itemId parameter

    // POLYMORPHISM (pure virtual → makes class abstract)
    virtual void display() const = 0;

    // Getters
    double getAmount() const;
    int getItemId() const;

    // OPERATOR OVERLOADING (comparison rule)
    bool operator>(const Bid &b) const;

    // FRIEND FUNCTION
    friend bool compareBids(const Bid &b1, const Bid &b2);

    virtual ~Bid() {}
};

#endif