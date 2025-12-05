# 🚀 CSCI 159 – Computer Science I (Fall 2025)
**Author:** Nico Ramos  
**Student at:** Vancouver Island University  

---

## 📌 Overview

This repository contains my lab work for **CSCI 159: Computer Science I** at **Vancouver Island University**.

All labs are written in **C++**, with a focus on:
- Core programming fundamentals  
- Clean structure and readable code  
- Algorithmic thinking and problem solving  

---

## 📁 Labs Overview

### 🧪 Lab 1 — C++ Basics  
Terminal navigation, compiling with `g++`, and writing first programs:
- Basic I/O with `cin` and `cout`
- Simple arithmetic
- Using comments and consistent formatting

---

### 🧮 Lab 2 — User Input & Formatting  
Working with:
- User input and basic validation  
- Proportional calculations  
- Output formatting with `<iomanip>` (`setw`, `fixed`, `setprecision`, etc.)

---

### ✅ Lab 3 — Input Validation  
Strengthening logic and error checking:
- Validating numeric input  
- Rejecting invalid values with clear error messages  
- Looping until valid data is entered  

---

### 🎯 Lab 4 — Pi Estimation (Monte Carlo)  
Using randomized simulation to approximate π:
- Random number generation with `srand(time(NULL));`  
- `#include <cstdlib>` for `rand()`  
- Coordinate-based hit/miss logic to estimate π  
- Shows how probability and code work together

---

### 📊 Lab 5 — Grade Calculator  
Arrays + sorting + functions:
- Storing grades in arrays  
- Bubble sort to order values  
- Trimmed averages (dropping highest/lowest)  
- Multi-function program design (breaking logic into smaller parts)

---

### 📦 Lab 6 — Package Processor (Circular Queue)  
Implements a **circular queue** of packages using structs:
- `struct Package` for sender, recipient, content, address, and value  
- Fixed-size array-based queue implementation  
- Insert, remove, and display operations  
- Wrap-around logic using `front`, `back`, and `size`  

> 💾 Implemented with regular `Package` objects stored directly in the queue array.

---

### ⭐ Bonus Lab — Package Processor (Dynamic Allocation)  
Extends the original Package Processor by switching to **pointer-based storage** and heap allocation:

- Replaces array of `Package` objects with an array of `Package*`  
- Uses `new` to dynamically allocate packages on the heap  
- Uses `delete` to properly free memory when a package is removed  
- Reinforces:
  - Pointers  
  - Dynamic memory (`new` / `delete`)  
  - Pointer-based queue logic



---

## 🧠 Learning Reflection 

Throughout **CSCI 159**, I strengthened my foundation in C++ and problem solving.  
Each lab pushed me to think more systematically — from formatting and validation to arrays, sorting, and simulation.

I learned how to:
- Break down problems into smaller logical steps  
- Write cleaner, more organized code  
- Debug more confidently  
- Understand how algorithms behave on real data  
- Build programs that model real-world processes (like package queues or grade calculators)

---

## ⚙️ Tech Stack

- **Language:** C++  
- **Compiler:** `g++`  
- **Editor:** VS Code  

---

## ▶️ How to Run a Lab

To compile and run a specific lab, replace `X` with the lab number (or file name), e.g. `lab5.cpp`:


```bash
g++ labX.cpp -o labX
./labX

```bash 
g++ bonus.cpp -o bonus
./bonus