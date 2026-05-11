# On-Campus Auction System
CS-112 OOP — GIKI Spring 2026

---

## Compile
```
g++ -std=c++11 main.cpp auction.cpp item.cpp Bid.cpp FileHandler.cpp Exception.cpp -o main.exe
```

## Run
```
.\main.exe
```

---

## Quick Test
```
register wania 1234
login admin admin
start
logout
login wania 1234
bid 1 55000
logout
login admin admin
end
winners
logout
exit
```

---

## Commands

**Student:** `view` `bid <id> <amount>` `search <id>` `history` `logout`

**Admin:** `view` `add <id> <name> <category> <price> <seller>` `start` `end` `winners` `save` `load` `logout`

> Admin login: `admin` / `admin`

---

