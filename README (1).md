# AquaTrack – Community Water Usage and Leak Reporting System

A beginner-friendly C++ mini-project for an OOPS lab, mapped to **SDG 6: Clean Water and Sanitation**.

## Features
- Add household water-usage records.
- Display registered households.
- Identify usage above a sample threshold of 500 litres.
- Submit water-leakage reports.
- View reports and update their status.
- Save a summary to a text file.

## OOP and C++ concepts
Classes, objects, private data members, encapsulation, constructors, member functions, vectors, loops, conditions, and file handling.

## How to compile and run
Using g++:

```bash
g++ main.cpp -o aquatrack
./aquatrack
```

On Windows:

```bash
g++ main.cpp -o aquatrack.exe
aquatrack.exe
```

## Note
This is an educational console-based prototype. The 500-litre alert is a sample threshold used for demonstration; it is not an official household water-use standard. Records are held in memory while the program runs. The Save Summary option exports the current session's summary to `aquatrack_summary.txt`.

## Team
- Srishti Aggarwal – 02114803125
- Arshia Garg – 00114803125
- Tanvi Gaba – 00514803125
- Group: 3I1
