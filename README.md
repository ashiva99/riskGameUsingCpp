This project is a simplified version of the popular strategy game Risk, designed to showcase object-oriented programming concepts and game logic implementation in C++. Players compete to dominate the game board by strategically placing armies, conquering territories, and interacting with other players.

Key Features

    Dynamic Player Setup: Supports a customizable number of players, with each player assigned unique tokens and territories.
    Game Board Management: The game board uses an adjacency matrix to represent territory connections, ensuring strategic gameplay.
    Army Placement: Players use tokens to deploy and manage their armies across territories.
    Turn-Based Interactions: Players take turns performing actions such as attacking or fortifying their positions.
    Win Condition: The objective is to capture all territories on the board and emerge as the sole ruler.

Classes Overview

    Game: The central class responsible for orchestrating the game by handling or calling other classes.
    Dice: Implements the dice mechanics used for battle outcomes.
    GameBoard: Represents the game board, including territories and their connections.
    Player: Manages individual players, their turns, and interactions.
    RiskGameSimulator: Simulates game rounds and manages overall flow.
    StatisticsKeeper: Analyzes game statistics by reading from output.txt.
    Token: Represents the armies or units placed on the game board.
    PlayerInfo: Maintains detailed information about each player.
    riskGame: The main class where the game begins, initializing and coordinating all components.

Technology and Design

    Language: C++
    Core Concepts: Object-Oriented Programming (OOP), file handling (for statistics), modular architecture, and dynamic memory management.

Purpose

    This project demonstrates advanced programming concepts, such as modular design, OOP principles, and game mechanics implementation, while providing a fun and interactive simulation of the classic strategy game Risk.




