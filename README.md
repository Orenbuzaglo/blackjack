# Blackjack (C Terminal Game)

 
The project simulates a classic Blackjack table with a player and a dealer.

---

## Features

- Standard Blackjack rules
- Player actions:
  - **Hit**
  - **Stand**
- Dealer automatic play logic
- Card deck simulation
- ASCII / terminal card display
- Score calculation with Ace handling (1 or 11)

---

## Game Rules

- Goal: get as close as possible to **21** without going over.
- Number cards count as their value.
- Face cards (**J, Q, K**) count as **10**.
- **Ace** counts as **1 or 11**, whichever is better.
- Player plays first.
- Dealer must **hit until reaching 17** or more.
- If a player exceeds **21**, they **bust** and lose immediately.



## Project Structure

blackjack/
│
├── main.c
├── linkedlist.c
├── linkedlist.h
├── calculations.c
├── calculations.h
└── README.md

Files responsibilities:


 `main.c` - Program entry point 
 `linkedlist.c` - deck,player hand and dealer hand are linkedlists. 
 `calculations.c` - Game calculations

---

## Card Representation

Cards are stored in **one byte**:

bits 7-4 : card value
bits 3-0 : suit



## Author

Oren


## License

This project is open source and free to use.