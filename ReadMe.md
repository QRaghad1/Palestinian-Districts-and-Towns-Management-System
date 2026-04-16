# Palestinian Districts and Towns Management System

## Overview
This project is a **C-based data structures system** that manages Palestinian districts and their towns using **doubly linked lists**.
It allows loading, sorting, updating, and analyzing hierarchical geographic data (districts → towns → population).
The system also implements **Radix Sort** for sorting districts alphabetically and supports multiple dynamic operations such as insertion, deletion, and updates.

---

## Features

### Data Loading
- Load districts, towns, and population from an input file (`districts.txt`)
- Parse and store data into linked lists

### District Management
- Add new districts dynamically
- Delete existing districts
- Sort districts alphabetically using **Radix Sort**

### Town Management
- Add towns to specific districts
- Delete towns
- Update town population
- Sort towns inside each district by population (ascending)

### Analytics
- Calculate total population of Palestine
- Find maximum and minimum town population
- Display population per district

### File Handling
- Load data from input file
- Save sorted results to output file (`sorted_districts.txt`)

---

## Data Structures Used

- Doubly Linked List (Districts & Towns)
- Array-based character buckets (Radix Sort)
- Dynamic memory allocation (malloc/free)

---

## Sorting Algorithm

### Radix Sort (for districts)
- Uses character-based sorting
- Supports:
  - A–Z
  - a–z
  - special padding character (`$`)
- Sorts districts alphabetically efficiently

---

## Project Structure

main.c              # Main program (menu + logic)
districts.txt       # Input file
sorted_districts.txt# Output file


## How to Run
##Compile:
gcc main.c -o project
###Run:
./project

## Menu Options

- 1. Load input file
- 2. Print loaded data
- 3. Sort districts (Radix Sort)
- 4. Sort towns by population
-5. Print sorted data
-6. Add district
-7. Add town
-8. Delete town
-9. Delete district
-10. Population statistics
-11. Show district populations
-12. Update town population
-13. Save to file
-14. Exit

## Author
-Raghad
-Computer Engineering Student 

## Notes
- The project uses manual memory management (malloc/free).
- Designed for educational purposes.
- No external libraries used except standard C libraries.

## Future Improvements

- Add GUI interface
- Convert to database system
- Improve memory safety
- Optimize radix sort implementation
