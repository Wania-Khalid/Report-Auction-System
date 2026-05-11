#ifndef EXCEPTION_H
#define EXCEPTION_H

// ============================================================
// Exception.h
// Member 6 — Exception Handling System
//
// OOP Concepts Demonstrated:
//   - Inheritance       (exception hierarchy)
//   - Polymorphism      (virtual what() method)
//   - Abstraction       (AuctionBaseException as abstract base)
//   - Encapsulation     (private message field + getter)
// ============================================================

#include <iostream>
#include <string>
using namespace std;

// ============================================================
// ABSTRACT BASE EXCEPTION CLASS
// All custom exceptions in this system inherit from this.
// ============================================================
class AuctionBaseException {
protected:
    string message;
    int    errorCode;

public:
    AuctionBaseException(string msg, int code = 0)
        : message(msg), errorCode(code) {}

    // Pure virtual — forces every subclass to define its own what()
    virtual string what() const = 0;

    // Getters
    string getMessage()  const { return message;   }
    int    getCode()     const { return errorCode; }

    // Virtual display — can be overridden for richer output
    virtual void display() const {
        cout << "[ERROR " << errorCode << "] " << what() << endl;
    }

    virtual ~AuctionBaseException() {}
};

// ============================================================
// INVALID BID EXCEPTION
// Thrown when a bid amount is invalid (negative, zero, or
// lower than the current highest bid).
// ============================================================
class InvalidBidException : public AuctionBaseException {
private:
    double attemptedAmount;
    double minimumRequired;

public:
    InvalidBidException(double attempted, double minimum)
        : AuctionBaseException("Invalid bid amount", 101),
          attemptedAmount(attempted), minimumRequired(minimum) {}

    string what() const override {
        return "InvalidBidException: Bid of $" + to_string(attemptedAmount)
             + " is too low. Minimum required: $" + to_string(minimumRequired);
    }

    void display() const override {
        cout << "[BID ERROR] " << what() << endl;
    }

    double getAttempted() const { return attemptedAmount; }
    double getMinimum()   const { return minimumRequired; }
};

// ============================================================
// INVALID LOGIN EXCEPTION
// Thrown when username or password does not match any account.
// ============================================================
class InvalidLoginException : public AuctionBaseException {
private:
    string attemptedUser;

public:
    InvalidLoginException(string user)
        : AuctionBaseException("Login failed", 102),
          attemptedUser(user) {}

    string what() const override {
        return "InvalidLoginException: No account found for username '"
             + attemptedUser + "'. Check credentials and try again.";
    }

    void display() const override {
        cout << "[LOGIN ERROR] " << what() << endl;
    }
};

// ============================================================
// ITEM NOT FOUND EXCEPTION
// Thrown when a requested item ID does not exist.
// ============================================================
class ItemNotFoundException : public AuctionBaseException {
private:
    int requestedId;

public:
    ItemNotFoundException(int id)
        : AuctionBaseException("Item not found", 103),
          requestedId(id) {}

    string what() const override {
        return "ItemNotFoundException: No item with ID "
             + to_string(requestedId) + " exists in the system.";
    }

    void display() const override {
        cout << "[ITEM ERROR] " << what() << endl;
    }

    int getRequestedId() const { return requestedId; }
};

// ============================================================
// AUCTION STATE EXCEPTION
// Thrown when an operation is attempted in the wrong state
// (e.g., bidding when auction is not active).
// ============================================================
class AuctionStateException : public AuctionBaseException {
private:
    string operation;
    bool   expectedActive;

public:
    AuctionStateException(string op, bool shouldBeActive)
        : AuctionBaseException("Invalid auction state", 104),
          operation(op), expectedActive(shouldBeActive) {}

    string what() const override {
        string expected = expectedActive ? "ACTIVE" : "INACTIVE";
        return "AuctionStateException: Operation '" + operation
             + "' requires auction to be " + expected + ".";
    }

    void display() const override {
        cout << "[STATE ERROR] " << what() << endl;
    }
};

// ============================================================
// DUPLICATE USER EXCEPTION
// Thrown when registering a username that already exists.
// ============================================================
class DuplicateUserException : public AuctionBaseException {
private:
    string duplicateUsername;

public:
    DuplicateUserException(string uname)
        : AuctionBaseException("Duplicate username", 105),
          duplicateUsername(uname) {}

    string what() const override {
        return "DuplicateUserException: Username '"
             + duplicateUsername + "' is already taken.";
    }

    void display() const override {
        cout << "[REGISTER ERROR] " << what() << endl;
    }
};

// ============================================================
// FILE EXCEPTION
// Thrown when file I/O operations fail.
// ============================================================
class FileException : public AuctionBaseException {
private:
    string filename;
    string operation; // "read" or "write"

public:
    FileException(string file, string op)
        : AuctionBaseException("File operation failed", 106),
          filename(file), operation(op) {}

    string what() const override {
        return "FileException: Failed to " + operation
             + " file '" + filename + "'.";
    }

    void display() const override {
        cout << "[FILE ERROR] " << what() << endl;
    }
};

#endif // EXCEPTION_H
