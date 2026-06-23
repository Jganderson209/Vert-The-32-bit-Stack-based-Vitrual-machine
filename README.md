# Vert — 32-bit Stack-Based Virtual Machine

A 32-bit stack-based virtual machine written in C++ from scratch. Vert loads a program into memory, processes a custom opcode set, and supports both manual and randomly generated input. Requires a C++17 compiler.

---

## What is a Stack-Based VM?

A virtual machine that performs all operations by pushing values onto a stack and popping them off to compute results — no named registers involved. It's one of the two core VM designs, and the same model used by the JVM and CPython.

---

## Features

- Custom opcode set: `PUSH`, `ADD`, `SUB`, `MULTIPLY`, `DIVIDE`, `PRINT`, `HALT`
- Two input modes: **Manual** (user-defined programs) and **Random** (RNG-generated)
- Stack underflow protection on all arithmetic operations
- Validated input with range checking and graceful error recovery

---

## Opcode Reference

| Opcode | Value | Description |
|--------|-------|-------------|
| `PUSH` | 1 | Push the next value in memory onto the stack |
| `ADD` | 2 | Pop two values, push their sum |
| `SUB` | 4 | Pop two values, push their difference (second − first) |
| `MULTIPLY` | 6 | Pop two values, push their product |
| `DIVIDE` | 5 | Pop two values, push their quotient (second ÷ first) |
| `PRINT` | 3 | Print the top of the stack without popping it |
| `HALT` | 0 | Stop execution immediately |

---

## Planned Improvements

- Visual mode with per-instruction delay so execution is human-readable in real time
- Extended opcode set
- GUI showing live stack and memory state
- Stretch goal: compile and run programs from a custom language into Vert bytecode
