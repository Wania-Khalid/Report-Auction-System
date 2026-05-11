// Exception.cpp
// Member 6 — Exception Handling System
//
// All exception classes are defined inline in Exception.h for
// simplicity (header-only classes). This .cpp file satisfies
// the submission requirement of having a separate implementation
// file and serves as documentation for the exception hierarchy.
//
// Exception Hierarchy:
//
//   AuctionBaseException        (abstract base — code 0)
//   ├── InvalidBidException     (code 101)
//   ├── InvalidLoginException   (code 102)
//   ├── ItemNotFoundException   (code 103)
//   ├── AuctionStateException   (code 104)
//   ├── DuplicateUserException  (code 105)
//   └── FileException           (code 106)
//
// Usage example:
//
//   try {
//       if (bid <= 0) throw InvalidBidException(bid, currentHighest);
//   }
//   catch (InvalidBidException& e) {
//       e.display();
//   }
//   catch (AuctionBaseException& e) {   // catch-all for hierarchy
//       e.display();
//   }

#include "Exception.h"
