# Tic-Tac-Toe in C++ – Procedural and Object-Oriented Implementations

This project showcases two complete implementations of the classic Tic-Tac-Toe game using C++, developed to demonstrate strong foundational programming knowledge, algorithmic thinking, and software design across both procedural and object-oriented approaches.

---

## Project Summary

- Developed a fully interactive CLI-based Tic-Tac-Toe game in C++.
- Built two modes: Player vs Player and Player vs Computer.
- Integrated two AI difficulty levels:
  - Easy mode using a random move generator.
  - Hard mode using the Minimax algorithm for optimal gameplay.
- Designed and structured two separate implementations:
  - **Procedural Version**
  - **Object-Oriented Version (OOP)**

---

## Procedural Version

- Implemented using **multiple `.cpp` and `.h` files**, separating concerns such as game logic (`game.cpp`), AI logic (`ai.cpp`), and program control (`main.cpp`).
- Managed complexity through **modular design** using header files and function abstraction.
- Controlled build process using **custom tasks in VS Code**, specifying all required source files for compilation.
- Demonstrates understanding of functional flow, program decomposition, and modular logic separation.

---

## Object-Oriented Version (OOP)

- Refactored the entire game using a **single class-based design** in one file: `main.cpp`.
- Encapsulated the board state, game control logic, and AI behavior within a dedicated `TicTacToe` class.
- Used private methods and members to enforce encapsulation and abstraction.
- Structured for readability, reusability, and long-term maintainability using object-oriented principles.
- Demonstrates clear understanding of class design, access control, method structure, and OOP patterns.

---

## Key Features Implemented

- Turn-based game logic for two players.
- Input validation and safe move handling.
- Win condition and draw detection logic.
- Random move generator (Easy AI).
- Minimax algorithm with recursive scoring (Hard AI).
- Code separation (Procedural) vs Encapsulation (OOP).

---

## Skills Demonstrated

- C++ Programming (Procedural and Object-Oriented)
- Algorithm design and recursion (Minimax)
- Clean code architecture and modularity
- Object-oriented principles: encapsulation, abstraction, class structure
- File handling and build configuration in Visual Studio Code
- Logical problem solving and AI implementation in a game setting

---

## How to Run

### Procedural Version
- Navigate to the `procedural-version/` folder.
- Ensure `main.cpp`, `game.cpp`, `game.h`, `ai.cpp`, and `ai.h` are present.
- Configure `tasks.json` in VS Code to compile all files together:


### OOP Version
- Navigate to the `OOPs-version/` folder.
- Compile the single file:
