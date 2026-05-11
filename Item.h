#ifndef ITEM_H
#define ITEM_H

// ============================================================
// Item.h  (unified version)
// Member 2 — Item Management System
//
// Unified to match item.cpp, FileHandler.h, and Auction.h.
// Supports both simple construction (id, name, price) used in
// main.cpp seeding AND full construction (id, name, cat,
// price, seller) used by FileHandler and Auction.
// ============================================================

#include <iostream>
#include <string>
using namespace std;

class Item {
private:
    int    itemId;
    string itemName;
    string category;
    double startingPrice;
    string sellerName;

public:
    // Default constructor
    Item();

    // Full constructor — used by FileHandler, Auction, admin add
    Item(int id, string name, string cat, double price, string seller);

    // Convenience constructor (backwards compat with main.cpp seeding)
    Item(int id, string name, double price)
        : itemId(id), itemName(name), category("General"),
          startingPrice(price), sellerName("Unknown") {}

    // Copy constructor (requirement: copy constructor)
    Item(const Item& other)
        : itemId(other.itemId), itemName(other.itemName),
          category(other.category), startingPrice(other.startingPrice),
          sellerName(other.sellerName) {}

    // Getters
    int    getId()            const;
    string getName()          const;
    string getCategory()      const;
    double getStartingPrice() const;
    string getSellerName()    const;

    // Setter using 'this' pointer (requirement: this pointer)
    void setName(string itemName)     { this->itemName     = itemName;     }
    void setCategory(string category) { this->category     = category;     }
    void setPrice(double startingPrice) { this->startingPrice = startingPrice; }

    // Display
    void display() const;

    // Legacy alias used by Admin.h / Student.h
    void displayItem() const { display(); }

    // Legacy bid method used by Student.h
    void placeBid(string bidder, float bid) {
        cout << "(Use the 'bid' command in the CLI to place bids.)\n";
    }
};

// ============================================================
// ItemManager — manages a collection of items
// ============================================================
const int MAX_ITEMS = 50;

class ItemManager {
private:
    Item items[MAX_ITEMS];
    int  itemCount;
    int  nextId;

public:
    ItemManager();

    void addItem();
    void addItemObject(Item item);
    void displayAllItems()      const;

    // searchItemById — overloaded (requirement: function overloading / compile-time polymorphism)
    void searchItemById()       const;   // interactive: prompts user for ID
    void searchItemById(int id) const;   // direct: takes ID as parameter

    void searchItemByCategory() const;

    // Bubble sort items by starting price (requirement: sorting with objects)
    void sortItemsByPrice();

    Item* getItems()  { return items;     }
    int   getCount()  { return itemCount; }
};

#endif // ITEM_H