
# Probability Calculator for Dice Rolls

## Overview
This project contains a C/C++ and Python program designed to calculate the probability of successful dice rolls in a game setting. It's particularly useful for games like Dungeons and Dragons, where players often need to roll dice and add modifiers to hit a target number or "Difficulty Class" (DC). The program calculates the minimum, maximum, and average probabilities of success given a range of bonuses and whether the player has an advantage.

## Features
- **Customizable Parameters**: Users can specify the difficulty class (DC), range of bonuses, advantage status, and the number of sides on the dice.
- **Probability Calculation**: The program calculates the minimum, maximum, and average probabilities of hitting the target DC with the given parameters.
- **Performance Measurement**: The C++ version of the program measures and outputs the time taken to perform the calculations, helping users understand the performance implications of their parameters.

## Code Explanation
The core of the program is the `calculateProbability` function, which takes the following parameters:
- `dc` (int): The Difficulty Class to hit.
- `bonusMin` (int): The minimum bonus to the dice roll.
- `bonusMax` (int): The maximum bonus to the dice roll.
- `advantage` (bool): Whether the roll has an advantage (rolling the dice twice and taking the higher number).
- `diceSides` (int): The number of sides on the dice.

It returns a `ProbabilityResult` struct containing the minimum, maximum, and average probabilities of success.

## How to Compile and Run

### C++ Version
1. **Ensure you have a C++ compiler**: Install `g++` or `clang++` if you haven't already.
2. **Compile the Program**: Navigate to the directory containing your code and run the following command:
   ```
   g++ -std=c++17 -O3 calculate_probability.cpp -o calculate_probability
   ```

### C Version
1. **Ensure you have a C compiler**: Install `gcc` or `clang++` if you haven't already.
2. **Compile the Program**: Navigate to the directory containing your code and run the following command:
   ```
   gcc -O3 calculate_probability.c -o calculate_probability
   ```

### Python Version
1. **Ensure you have Python**: This program is compatible with Python 3.x. Install Python if you haven't already.
2. **Run the Program**: Navigate to the directory containing your code and run the following command:
   ```
   python calculate_probability.py
   ```

## Running the Program
After compiling (for C/C++) or directly (for Python), you can run the program by typing `./calculate_probability` (for compiled versions) or `python calculate_probability.py` (for the Python version) in your terminal. Ensure you're in the directory where the file is located.

## Contributing
Contributions to the project are welcome! Please feel free to fork the repository, make your changes, and submit a pull request.

