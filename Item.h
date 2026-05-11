#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

class Item {
private:
    int itemID;
    string name;
    double basePrice;
    double highestBid;
    string highestBidder;

public:
    // Constructor
    Item(int id, string n, double price) {
        itemID = id;
        name = n;
        basePrice = price;
        highestBid = price;
        highestBidder = "None";
    }

    // Display item
    void displayItem() {
        cout << "\nItem ID: " << itemID << endl;
        cout << "Name: " << name << endl;
        cout << "Base Price: " << basePrice << endl;
        cout << "Highest Bid: " << highestBid << endl;
        cout << "Highest Bidder: " << highestBidder << endl;
    }

    // Place bid
    void placeBid(string bidder, double amount) {
        if (amount > highestBid) {
            highestBid = amount;
            highestBidder = bidder;
            cout << "Bid successful!\n";
        } else {
            cout << "Bid too low!\n";
        }
    }
};

#endif