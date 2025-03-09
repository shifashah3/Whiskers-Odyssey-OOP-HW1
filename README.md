# **Whisker's Odyssey - OOP Homework 1 Submission**  

## **Overview**  
This project is part of **Object-Oriented Programming (OOP) Homework 1**. Whisker's Odyssey is a text-based adventure game where the player, Alex, embarks on a quest to rescue their cat, Whisker, from an eccentric wizard. The game involves navigating through different locations, collecting Lost Collar Charms, and managing limited Treats to reach the final destination.  

## **How to Play**  
- Start at **Pet Haven** with **40 Treats**.  
- Move using **arrow keys** (North, South, East, West).  
- Collect **three Lost Collar Charms** to proceed.  
- Avoid **Bewildering Bog**, or the game ends.  
- Reach **Temporal Tower** with all charms to win.  

## **Game Status**  
- **Running**: Game is in progress.  
- **Lost**: Ran out of Treats or entered Bewildering Bog.  
- **Won**: Successfully rescued Whisker.

### How to Compile and Run  

#### Windows  
Open the project folder in **VSCode** (or any terminal) and run:  
```sh
g++ *.cpp -I C:\mingw_dev_lib\include -L C:\mingw_dev_lib\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -o game.exe
```
Then, execute the game:  
```sh
./game.exe
```

**Note:** The provided files are configured for Windows. If using another OS, modifications may be required.
