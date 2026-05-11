#include "Item.h"
#include <iostream>
using namespace std;

// Default constructor
Item::Item() {
    itemId = 0;
    itemName = "";
    category = "";
    startingPrice = 0.0;
    sellerName = "";
}

// Parameterized constructor
Item::Item(int id, string name, string cat, double price, string seller) {
    itemId = id;
    itemName = name;
    category = cat;
    startingPrice = price;
    sellerName = seller;
}

// Getters
int Item::getId() const {
    return itemId;
}

string Item::getName() const {
    return itemName;
}

string Item::getCategory() const {
    return category;
}

double Item::getStartingPrice() const {
    return startingPrice;
}

string Item::getSellerName() const {
    return sellerName;
}

// Display function
void Item::display() const {
    cout << "Item ID: "       << itemId        << endl;
    cout << "Name: "          << itemName      << endl;
    cout << "Category: "      << category      << endl;
    cout << "Starting Price: $" << startingPrice << endl;
    cout << "Seller: "        << sellerName    << endl;
}

// ========== ItemManager Implementation ==========

ItemManager::ItemManager() {
    itemCount = 0;
    nextId = 1;
}

void ItemManager::addItem() {
    if (itemCount >= MAX_ITEMS) {
        cout << "Cannot add more items! Storage full." << endl;
        return;
    }

    string name, category, seller;
    double price;

    cout << "Enter item name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter category: ";
    getline(cin, category);
    cout << "Enter starting price: $";
    cin >> price;
    cout << "Enter seller name: ";
    cin.ignore();
    getline(cin, seller);

    items[itemCount] = Item(nextId++, name, category, price, seller);
    itemCount++;

    cout << "Item added successfully with ID: " << (nextId - 1) << endl;
}

void ItemManager::addItemObject(Item item) {
    if (itemCount < MAX_ITEMS) {
        items[itemCount] = item;
        itemCount++;
    }
}

void ItemManager::displayAllItems() const {
    if (itemCount == 0) {
        cout << "No items available." << endl;
        return;
    }

    cout << "\n===== ALL ITEMS =====" << endl;
    for (int i = 0; i < itemCount; i++) {
        items[i].display();
        cout << "-------------------" << endl;
    }
}

// Overload 1 — interactive: prompts user for ID
void ItemManager::searchItemById() const {
    int id;
    cout << "Enter item ID to search: ";
    cin >> id;
    searchItemById(id); // delegates to overload 2
}

// Overload 2 — direct: takes ID as parameter
// (requirement: function overloading / compile-time polymorphism)
void ItemManager::searchItemById(int id) const {
    for (int i = 0; i < itemCount; i++) {
        if (items[i].getId() == id) {
            items[i].display();
            return;
        }
    }
    cout << "Item with ID " << id << " not found!" << endl;
}

void ItemManager::searchItemByCategory() const {
    string cat;
    cout << "Enter category to search: ";
    cin.ignore();
    getline(cin, cat);

    bool found = false;
    for (int i = 0; i < itemCount; i++) {
        if (items[i].getCategory() == cat) {
            items[i].display();
            found = true;
            cout << "-------------------" << endl;
        }
    }

    if (!found) {
        cout << "No items found in category: " << cat << endl;
    }
}

// Bubble sort by starting price (requirement: sorting with objects)
void ItemManager::sortItemsByPrice() {
    for (int i = 0; i < itemCount - 1; i++) {
        for (int j = 0; j < itemCount - i - 1; j++) {
            if (items[j].getStartingPrice() > items[j + 1].getStartingPrice()) {
                Item temp   = items[j];
                items[j]    = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
    cout << "[ItemManager] Items sorted by price.\n";
}
