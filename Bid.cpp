#include "Bid.h"

// Static variable initialization (requirement: static data member)
int Bid::totalBids = 0;

// Constructor
Bid::Bid(int id, double amt, int uid, int iid) {
    bidId  = id;
    amount = amt;
    userId = uid;
    itemId = iid;

    totalBids++;
}

// Getters
double Bid::getAmount() const {
    return amount;
}

int Bid::getItemId() const {
    return itemId;
}

// Operator overloading (requirement: operator overloading)
bool Bid::operator>(const Bid& b) const {
    return amount > b.amount;
}

// Friend function (requirement: friend function)
bool compareBids(const Bid& b1, const Bid& b2) {
    return b1.amount > b2.amount;
}
