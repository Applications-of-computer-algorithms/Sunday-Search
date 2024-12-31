# Sunday Algorithm Implementation

This repository contains an implementation of the **Sunday String Search Algorithm** in C++. The Sunday algorithm is a pattern-matching technique that efficiently finds occurrences of a substring (pattern) within a larger string (text). The algorithm is known for its simplicity and efficiency, especially for cases with sparse matches due to its use of the **Bad Character Heuristic (BCH)**.

## Algorithm Overview

The **Sunday Algorithm** relies on:

1. **Bad Character Heuristic (BCH):**
   - The BCH table precomputes the shift values for each character in the pattern and the text.
   - When a mismatch occurs, the algorithm looks at the character in the text immediately following the current search window and uses the BCH table to determine the optimal shift.

2. **Shift Mechanism:**
   - This allows the algorithm to skip unnecessary comparisons, leading to faster execution in practice compared to naive string search.

### Complexity
- **Time Complexity:** O(n + m), where `n` is the length of the text and `m` is the length of the pattern (on average, due to the BCH optimization).
- **Space Complexity:** O(m + Σ), where `m` is the pattern length and Σ is the alphabet size.

---

## Features

- Reads input text from a file.
- Searches for a user-specified pattern within the text.
- Outputs the following to `out.txt`:
  - The BCH (Bad Character Heuristic) table.
  - The starting indices of all matches.

---

## How to Use

### Requirements
- A C++ compiler (e.g., `g++`).
- A text file containing the input text (e.g., `input.txt`).

### Compilation
Use the following command to compile the program:
```bash
g++ -o sunday DN2.cpp
```

### Execution
Run the compiled program with the following parameters:
1. The pattern to search for.
2. The name of the file containing the input text.

Example:
```bash
./sunday "pattern" input.txt
```

### Example Input and Output

#### Example Input (file: `input.txt`)
```
Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam...
```

#### Command:
```bash
./sunday "dolor" input.txt
```

#### Output (file: `out.txt`)
```
<Contents of BCH array>
12 56 102
```
The `out.txt` file contains:
1. The BCH table values used for efficient shifts.
2. The starting indices of matches (e.g., `12`, `56`, `102` for the word "dolor").

---

## Code Details

### Key Functions

1. **`readInputText`**
   - Reads the entire text from a given file.

2. **`outputBCH`**
   - Outputs the BCH table to the file.

3. **`sunday`**
   - Implements the Sunday string search algorithm using the BCH heuristic.

4. **`main`**
   - Handles command-line arguments and coordinates the search process.

### Error Handling
- If the input file cannot be opened, the program exits with an error message.
- If the output file cannot be opened, an appropriate error is returned.

---

## Notes
- The input file must be in the same directory as the program.
- The program outputs both the BCH table and match indices to the `out.txt` file.
