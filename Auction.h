#ifndef AUCTION_H
#define AUCTION_H

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Bid.h"

class AuctionException {
private:
    std::string message;
public:
    AuctionException(std::string msg) : message(msg) {}
    std::string getMessage() const { return message; }
};

class Auction {
private:
    int         auctionId;
    std::string auctionName;
    bool        isActive;

    std::vector<Item>   items;
    std::vector<double> highestBids;
    std::vector<int>    winners;

public:
    // -------------------------------------------------------
    // Nested class — AuctionTimer
    // (requirement: nested class)
    // -------------------------------------------------------
    class AuctionTimer {
    private:
        int durationSeconds;
    public:
        AuctionTimer(int d) : durationSeconds(d) {}

        int getDuration() const { return durationSeconds; }

        void display() const {
            std::cout << "[AuctionTimer] Duration set to "
                      << durationSeconds << " seconds.\n";
        }
    };

    Auction(int id, std::string name);
    void   addItem(Item item);
    void   displayItems();
    void   startAuction();
    void   endAuction();
    bool   placeBid(int itemId, double amount, int userId);
    double getCurrentHighestBid(int itemId);
    int    getWinnerId(int itemId);
    void   showWinners();

    // Inline functions (requirement: inline functions)
    bool isAuctionActive()  const { return isActive;       }
    int  getItemCount()     const { return items.size();   }
};

#endif
