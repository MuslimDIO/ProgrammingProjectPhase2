
# RoboRally – Fall 2024 Programming Project

## Overview

**RoboRally** is a two-player strategy game developed during the Fall 2024 semester as part of the CMPS102 Programming Techniques course at Cairo University. Inspired by the board game *RoboRally*, this digital version challenges players to maneuver robots across a grid-based map filled with interactive elements. The game was developed in C++ using the **CMUgraphics** library for the graphical interface.

## Gameplay

Players compete to reach a designated flag cell first while navigating a 5x11 grid filled with strategic components. Each robot follows programmed movement commands, with its available moves dependent on its current health status.

### Grid Features:
- **Belts** – Move the robot automatically in a specific direction.
- **Gears** – Rotate robots when landed on.
- **Water Pits** – Eliminate robots immediately if fallen into.
- **Dangerous Cells** – Decrease robot health.
- **Workshop** – Repair or upgrade the robot.
- **Antenna** – May provide helpful information or strategic advantages.

## Features

- **Design Mode** – Allows creation and customization of the game grid.
- **Play Mode** – A turn-based gameplay system where two players compete.
- **Health and Command System** – Health-dependent number of commands.
- **Graphical Interface** – Built using CMUgraphics for a user-friendly visual experience.
- **Object-Oriented Design** – Modular codebase that cleanly separates responsibilities between game elements.

## Technologies Used

- **Language**: C++
- **Graphics**: CMUgraphics Library
- **Paradigms**: Object-Oriented Programming (OOP)

## Installation and Setup

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/MuslimDIO/RoboRally-Programming-Project.git
   ```

2. **Navigate to the Project Directory**:
   ```bash
   cd RoboRally-Programming-Project
   ```

3. **Compile the Code**:
   - Ensure you have a C++ compiler and CMUgraphics set up.
   - Use an IDE like Code::Blocks or Visual Studio, or compile from terminal.

4. **Run the Executable**:
   - Launch the application to start designing your board or playing the game.

## Educational Outcomes

Working on RoboRally gave us valuable experience in the following areas:

- **Object-Oriented Design and Architecture**  
  We learned how to use inheritance, polymorphism, encapsulation, and modular class design to manage a moderately complex codebase. Each object on the grid (like Belts, Gears, or the Robot itself) was modeled as a class with its own behavior.

- **Team Collaboration and Version Control**  
  The project was developed collaboratively using GitHub. We practiced team coordination, managing merge conflicts, and communicating through issues and commits.

- **Event-Driven and GUI Programming**  
  With CMUgraphics, we transitioned from console-based projects to a full graphical interface. We implemented mouse-based interactions, dynamic UI updates, toolbars, and visual game state transitions.

- **Game Logic and Simulation Design**  
  We tackled challenges involving timing, order of operations, collision resolution, and game rules enforcement. This helped us think critically about system behavior and robustness.

- **Debugging and Code Quality**  
  Maintaining readable, well-commented, and testable code was essential. We became proficient in debugging large interconnected systems and testing through iteration.

- **Planning and Time Management**  
  Developing a game from scratch required structured planning. From the design document to final integration, we learned how to manage time, divide responsibilities, and meet deliverables.

- **Creative Problem-Solving**  
  We often faced issues that required non-standard solutions, such as ensuring visual clarity on a small grid, optimizing how objects interact, and making gameplay engaging while staying within our technical limits.


## Team Members

This project was developed collaboratively by:

- [@IbrahimMohsenMoussa](https://github.com/IbrahimMohsenMoussa)
- [@abdelrahmanbana](https://github.com/abdelrahmanbana)
- [@AbdullahSaad0](https://github.com/AbdullahSaad0)
- [@MuslimDIO](https://github.com/MuslimDIO)

Each member contributed to various aspects of the game’s logic, interface design, debugging, and overall system integration. The teamwork and division of responsibilities were crucial in successfully delivering the final product.
