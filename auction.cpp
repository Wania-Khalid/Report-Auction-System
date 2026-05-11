#include "Auction.h"
#include <iostream>

using namespace std;

Auction::Auction(int id, string name)
    : auctionId(id), auctionName(name), isActive(false) {
    cout << "========================================" << endl;
    cout << "Auction Created: " << auctionName << endl;
    cout << "========================================" << endl;
}

void Auction::addItem(Item item) {
    items.push_back(item);
    highestBids.push_back(item.getStartingPrice());
    winners.push_back(-1);

    cout << "[ADDED] " << item.getName()
         << " (Starting Price: $" << item.getStartingPrice() << ")" << endl;
}

void Auction::displayItems() {
    cout << "\n========== ITEMS IN AUCTION ==========" << endl;
    if (items.empty()) {
        cout << "No items available." << endl;
    } else {
        for (size_t i = 0; i < items.size(); i++) {
            items[i].display();
            if (isActive && winners[i] != -1) {
                cout << "  Current Bid: $" << highestBids[i]
                     << " (User " << winners[i] << ")" << endl;
            }
            cout << "---------------------------------------" << endl;
        }
    }
}

void Auction::startAuction() {
    if (items.empty()) throw AuctionException("Cannot start: No items added!");
    if (isActive)      throw AuctionException("Auction is already active!");
    isActive = true;
    cout << "\n>>> AUCTION STARTED <<<\n" << endl;
}

bool Auction::placeBid(int itemId, double amount, int userId) {
    if (!isActive) return false;

    for (size_t i = 0; i < items.size(); i++) {
        if (items[i].getId() == itemId) {
            if (amount > highestBids[i]) {
                highestBids[i] = amount;
                winners[i]     = userId;
                cout << "[ACCEPTED] User " << userId
                     << " bid $" << amount
                     << " on "   << items[i].getName() << endl;
                return true;
            }
            cout << "[REJECTED] Bid too low!" << endl;
            return false;
        }
    }
    return false;
}

void Auction::endAuction() {
    if (!isActive) throw AuctionException("Auction is not active!");
    isActive = false;

    cout << "\n========== FINAL RESULTS ==========" << endl;
    double totalRevenue = 0;
    for (size_t i = 0; i < items.size(); i++) {
        if (winners[i] != -1) {
            cout << "[SOLD] " << items[i].getName()
                 << " to User " << winners[i]
                 << " for $"    << highestBids[i] << endl;
            totalRevenue += highestBids[i];
        } else {
            cout << "[UNSOLD] " << items[i].getName() << endl;
        }
    }
    cout << "Total Revenue: $" << totalRevenue << endl;
    cout << "Total Bids in System: " << Bid::totalBids << endl;
    cout << "==================================\n" << endl;
}

void Auction::showWinners() {
    cout << "\n--- Winners List ---" << endl;
    for (size_t i = 0; i < items.size(); i++) {
        if (winners[i] != -1) {
            cout << "Item: " << items[i].getName()
                 << " | Winner: User " << winners[i] << endl;
        }
    }
}

double Auction::getCurrentHighestBid(int itemId) {
    for (size_t i = 0; i < items.size(); i++) {
        if (items[i].getId() == itemId) return highestBids[i];
    }
    return 0;
}

int Auction::getWinnerId(int itemId) {
    for (size_t i = 0; i < items.size(); i++) {
        if (items[i].getId() == itemId) return winners[i];
    }
    return -1;
}
