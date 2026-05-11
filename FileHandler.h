#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
#include "Student.h"
#include "Item.h"

using namespace std;

// ============================================================
// ABSTRACT BASE CLASS — DataStore
// OOP concepts:
//   - Abstraction     (pure virtual functions)
//   - Inheritance     (FileHandler extends DataStore)
//   - Polymorphism    (FileHandler overrides virtual methods)
// ============================================================

class DataStore {
public:
    virtual void saveData()    = 0;
    virtual void loadData()    = 0;
    virtual void clearData()   = 0;
    virtual void displayData() = 0;

    virtual ~DataStore() {}
};

// ============================================================
// FileHandler — inherits from DataStore
// Member 5 — Data Persistence (File Handling)
// ============================================================

class FileHandler : public DataStore {
private:
    Student* users;
    int*     userCount;
    Item*    items;
    int*     itemCount;

public:
    // Constructor
    FileHandler(Student* u, int* uc, Item* it, int* ic)
        : users(u), userCount(uc), items(it), itemCount(ic) {}

    // -------------------------------------------------------
    // Overrides from DataStore
    // -------------------------------------------------------

    void saveData() override {
        saveUsers(users, *userCount);
        saveItems(items, *itemCount);
        saveItemsBinary(items, *itemCount);   // binary save included
        cout << "[DataStore] All data saved.\n";
    }

    void loadData() override {
        *userCount = loadUsers(users, 50);
        *itemCount = loadItems(items, 50);
        cout << "[DataStore] All data loaded.\n";
    }

    void clearData() override {
        clearBidHistory();
    }

    void displayData() override {
        displayBidHistory();
    }

    // -------------------------------------------------------
    // SAVE USERS  (text file)
    // -------------------------------------------------------
    static void saveUsers(Student users[], int count) {
        ofstream file("users.txt");
        if (!file.is_open()) {
            cout << "[ERROR] Could not open users.txt for writing.\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            file << users[i].getUsername() << "|"
                 << users[i].getPassword() << "|"
                 << users[i].getStudentID() << "\n";
        }
        file.close();
        cout << "[SAVED] " << count << " user(s) saved to users.txt\n";
    }

    // -------------------------------------------------------
    // LOAD USERS  (text file)
    // -------------------------------------------------------
    static int loadUsers(Student users[], int maxCount) {
        ifstream file("users.txt");
        if (!file.is_open()) {
            cout << "[INFO] users.txt not found. Starting fresh.\n";
            return 0;
        }
        int count = 0;
        string line;
        while (getline(file, line) && count < maxCount) {
            size_t sep1 = line.find('|');
            size_t sep2 = line.find('|', sep1 + 1);
            if (sep1 == string::npos || sep2 == string::npos) continue;

            string uname = line.substr(0, sep1);
            string pass  = line.substr(sep1 + 1, sep2 - sep1 - 1);
            string sid   = line.substr(sep2 + 1);

            users[count++] = Student(uname, pass, sid);
        }
        file.close();
        cout << "[LOADED] " << count << " user(s) loaded from users.txt\n";
        return count;
    }

    // -------------------------------------------------------
    // SAVE ITEMS  (text file)
    // -------------------------------------------------------
    static void saveItems(Item items[], int count) {
        ofstream file("items.txt");
        if (!file.is_open()) {
            cout << "[ERROR] Could not open items.txt for writing.\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            file << items[i].getId()            << "|"
                 << items[i].getName()          << "|"
                 << items[i].getCategory()      << "|"
                 << items[i].getStartingPrice() << "|"
                 << items[i].getSellerName()    << "\n";
        }
        file.close();
        cout << "[SAVED] " << count << " item(s) saved to items.txt\n";
    }

    // -------------------------------------------------------
    // LOAD ITEMS  (text file)
    // -------------------------------------------------------
    static int loadItems(Item items[], int maxCount) {
        ifstream file("items.txt");
        if (!file.is_open()) {
            cout << "[INFO] items.txt not found. Starting fresh.\n";
            return 0;
        }
        int count = 0;
        string line;
        while (getline(file, line) && count < maxCount) {
            size_t sep1 = line.find('|');
            size_t sep2 = line.find('|', sep1 + 1);
            size_t sep3 = line.find('|', sep2 + 1);
            size_t sep4 = line.find('|', sep3 + 1);
            if (sep1 == string::npos || sep2 == string::npos ||
                sep3 == string::npos || sep4 == string::npos) continue;

            int    id     = stoi(line.substr(0, sep1));
            string name   = line.substr(sep1 + 1, sep2 - sep1 - 1);
            string cat    = line.substr(sep2 + 1, sep3 - sep2 - 1);
            double price  = stod(line.substr(sep3 + 1, sep4 - sep3 - 1));
            string seller = line.substr(sep4 + 1);

            items[count++] = Item(id, name, cat, price, seller);
        }
        file.close();
        cout << "[LOADED] " << count << " item(s) loaded from items.txt\n";
        return count;
    }

    // -------------------------------------------------------
    // SAVE ITEMS — BINARY FILE
    // (requirement: binary vs text files / binary file I/O)
    // Writes a count integer followed by raw Item structs.
    // -------------------------------------------------------
    static void saveItemsBinary(Item items[], int count) {
        ofstream file("items.bin", ios::binary);
        if (!file.is_open()) {
            cout << "[ERROR] Could not open items.bin for writing.\n";
            return;
        }
        file.write(reinterpret_cast<char*>(&count), sizeof(int));
        for (int i = 0; i < count; i++)
            file.write(reinterpret_cast<const char*>(&items[i]), sizeof(Item));
        file.close();
        cout << "[SAVED] " << count << " item(s) saved to binary file items.bin\n";
    }

    // -------------------------------------------------------
    // LOAD ITEMS — BINARY FILE
    // -------------------------------------------------------
    static int loadItemsBinary(Item items[], int maxCount) {
        ifstream file("items.bin", ios::binary);
        if (!file.is_open()) {
            cout << "[INFO] items.bin not found.\n";
            return 0;
        }
        int count = 0;
        file.read(reinterpret_cast<char*>(&count), sizeof(int));
        if (count > maxCount) count = maxCount;
        for (int i = 0; i < count; i++)
            file.read(reinterpret_cast<char*>(&items[i]), sizeof(Item));
        file.close();
        cout << "[LOADED] " << count << " item(s) loaded from items.bin\n";
        return count;
    }

    // -------------------------------------------------------
    // SAVE BID RECORD  (append to bids.txt)
    // -------------------------------------------------------
    static void saveBidRecord(int bidId, double amount,
                              int userId, int itemId) {
        ofstream file("bids.txt", ios::app);
        if (!file.is_open()) {
            cout << "[ERROR] Could not open bids.txt for writing.\n";
            return;
        }
        file << bidId  << "|"
             << amount << "|"
             << userId << "|"
             << itemId << "\n";
        file.close();
    }

    // -------------------------------------------------------
    // LOAD BID RECORDS
    // -------------------------------------------------------
    static int loadBidRecords(int bidIds[], double amounts[],
                              int userIds[], int itemIds[],
                              int maxCount) {
        ifstream file("bids.txt");
        if (!file.is_open()) {
            cout << "[INFO] bids.txt not found. No bid history.\n";
            return 0;
        }
        int count = 0;
        string line;
        while (getline(file, line) && count < maxCount) {
            size_t sep1 = line.find('|');
            size_t sep2 = line.find('|', sep1 + 1);
            size_t sep3 = line.find('|', sep2 + 1);
            if (sep1 == string::npos || sep2 == string::npos ||
                sep3 == string::npos) continue;

            bidIds[count]  = stoi(line.substr(0, sep1));
            amounts[count] = stod(line.substr(sep1 + 1, sep2 - sep1 - 1));
            userIds[count] = stoi(line.substr(sep2 + 1, sep3 - sep2 - 1));
            itemIds[count] = stoi(line.substr(sep3 + 1));
            count++;
        }
        file.close();
        cout << "[LOADED] " << count << " bid record(s) from bids.txt\n";
        return count;
    }

    // -------------------------------------------------------
    // CLEAR BID HISTORY
    // -------------------------------------------------------
    static void clearBidHistory() {
        ofstream file("bids.txt", ios::trunc);
        file.close();
        cout << "[CLEARED] bids.txt has been reset.\n";
    }

    // -------------------------------------------------------
    // DISPLAY BID HISTORY
    // -------------------------------------------------------
    static void displayBidHistory() {
        ifstream file("bids.txt");
        if (!file.is_open()) {
            cout << "[INFO] No bid history found.\n";
            return;
        }
        cout << "\n========== BID HISTORY ==========\n";
        string line;
        int count = 0;
        while (getline(file, line)) {
            size_t sep1 = line.find('|');
            size_t sep2 = line.find('|', sep1 + 1);
            size_t sep3 = line.find('|', sep2 + 1);
            if (sep1 == string::npos) continue;

            string bidId  = line.substr(0, sep1);
            string amount = line.substr(sep1 + 1, sep2 - sep1 - 1);
            string userId = line.substr(sep2 + 1, sep3 - sep2 - 1);
            string itemId = line.substr(sep3 + 1);

            cout << "Bid #"       << bidId
                 << " | Amount: $" << amount
                 << " | User: "    << userId
                 << " | Item: "    << itemId << "\n";
            count++;
        }
        if (count == 0) cout << "No bids recorded yet.\n";
        cout << "==================================\n";
        file.close();
    }
};

#endif
