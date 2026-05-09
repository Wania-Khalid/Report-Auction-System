#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 50;

class Item {
private:
    int    itemId;
    string itemName;
    string category;
    double startingPrice;
    string sellerName;

public:
    // Constructors
    Item();
    Item(int id, string name, string cat, double price, string seller);

    // Getters
    int    getId() const;
    string getName() const;
    string getCategory() const;
    double getStartingPrice() const;
    string getSellerName() const;

    void display() const;
};

class ItemManager {
private:
    Item items[MAX_ITEMS];  
    int  itemCount;
    int  nextId;

public:
    ItemManager();

    void addItem();                
    void displayAllItems() const;        
    void searchItemById() const;         
    void searchItemByCategory() const;   
    void addItemObject(Item item);
};

#endif