#include <iostream>
#include <string>
#include <vector>
#include "Auction.h"
#include "Item.h"
#include "Student.h"
#include "Exception.h"

using namespace std;

// Global storage to match your previous setup
Item items[100];
Student users[50];
int itemCount = 0;
int userCount = 0;

int main() {
    cout << "========================================" << endl;
    cout << "    AUCTION SYSTEM: HARDCODED TEST" << endl;
    cout << "========================================" << endl;

    Auction auction(101, "Spring Semester Auction");

    // 1. ADD ITEMS
    cout << "\n[Step 1] Adding Items..." << endl;
    items[itemCount++] = Item(1, "MacBook", "Electronics", 80000, "Ali");
    items[itemCount++] = Item(2, "Gaming_Mouse", "Electronics", 5000, "Sara");
    
    for (int i = 0; i < itemCount; i++) {
        auction.addItem(items[i]);
    }
    auction.displayItems();

    // 2. START AUCTION
    cout << "\n[Step 2] Admin starting the auction..." << endl;
    auction.startAuction();

    // 3. REGISTER & BID (Simulation)
    cout << "\n[Step 3] Simulating Bids..." << endl;
    
    // Create students manually
    Student s1("Afifah", "pass123", "S001");
    Student s2("Wania", "pass456", "S002");

    // Afifah bids 85000 on Item 1
    cout << "-> Afifah bids 85000 on MacBook..." << endl;
    auction.placeBid(1, 85000, 001);

    // Wania tries to bid lower (should trigger exception logic or be rejected)
    cout << "-> Wania bids 82000 on MacBook..." << endl;
    auction.placeBid(1, 82000, 002);

    // Wania bids higher
    cout << "-> Wania bids 90000 on MacBook..." << endl;
    auction.placeBid(1, 90000, 002);

    // 4. END AUCTION
    cout << "\n[Step 4] Closing Auction and showing Winners..." << endl;
    auction.endAuction();
    auction.showWinners();

    cout << "\n========================================" << endl;
    cout << "    SIMULATION SUCCESSFULLY COMPLETED" << endl;
    cout << "========================================" << endl;

    return 0;
}