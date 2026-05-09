# Pizza Delight - C++ Final Project

A console-based Pizza Ordering System written in C++ for Windows.

This project supports two user roles:
- Customer: place/cancel pizza orders.
- Admin: view pending orders, serve customers, search served history, and view earnings.

## Features

- Customer operations:
  - Place Take-Away order
  - Place Dine-In order
  - Cancel order from cart (allowed within 5 minutes)
- Admin operations:
  - Display all take-away orders
  - Display all dine-in orders
  - Display all pending orders
  - Serve take-away and dine-in orders
  - View all served orders
  - Search served customer by name
  - Calculate total bill of pending orders
  - Calculate total earnings of served orders
- File persistence:
  - Pending orders are stored in text files
  - Admin password is read from file

## Data Structures Used

- Linked Lists:
  - Separate lists for pending take-away and dine-in customers
- Queue:
  - Cart uses a queue of placed orders
- AVL Tree:
  - Served customers are inserted into a balanced BST for sorted display/search by name

## Project Files

- `Project_Code.cpp` - main source code
- `Project_Code.exe` - compiled executable (if already built)
- `admin_password.txt` - admin password (first line is used)
- `takeaway_orders.txt` - saved take-away orders
- `dinein_orders.txt` - saved dine-in orders

## Requirements

- Windows OS
- A C++ compiler, for example:
  - MinGW g++
  - Microsoft Visual C++ (MSVC)
- Uses Windows-specific headers/functions:
  - `windows.h`
  - `conio.h`

## Build and Run

### Option 1: MinGW g++

```bash
g++ -std=c++17 -O2 -o Project_Code.exe Project_Code.cpp
Project_Code.exe
```

### Option 2: MSVC (Developer Command Prompt)

```bat
cl /EHsc /std:c++17 Project_Code.cpp
Project_Code.exe
```

## How to Use

1. Run the program.
2. Choose role:
   - Enter `c` for Customer
   - Enter `a` for Admin
3. For Customer:
   - Choose take-away or dine-in order
   - Enter details and pizza selection
   - Cancel order by name within 5 minutes if needed
4. For Admin:
   - Enter password from `admin_password.txt`
   - Use admin menu to inspect/serve orders and view totals

## Notes

- Order files grow over time because orders are appended.
- Serving a customer moves that order to served history in memory (AVL tree).
- If input handling behaves unexpectedly, restart and enter values carefully (the program mixes `cin` and `getline`).

## Future Improvements

- Input validation for menu index, age, and quantity
- Better ordering priority logic for take-away customers
- Save served history to file/database
- Replace `goto` flow with cleaner function-based navigation
- Add unit tests for search, insertions, and cancellation logic

## Author

Final Project - Pizza Ordering System (C++)
