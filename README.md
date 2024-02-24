# Rock Paper Scissors

This is a console version of Rock Paper Scissors written in C.

## Installation

This game was developed on a Linux machine using VSCode and GCC 11. It can only be build through the VSCode task currently. The command used is:

```bash
gcc main.c -o main
```

## Usage

Initial output:

```bash
Welcome to the Rock Paper Scissor Game!
=======================================

Type (1) for Rock, (2) for Papper, (3) for Scissor, (0) to quit
Your choice:  
```

When user wins:

```bash
Type (1) for Rock, (2) for Papper, (3) for Scissor, (0) to quit
Your choice: 1
The computer's choice: 3

--> You won
```

When user loses:

```bash
Type (1) for Rock, (2) for Papper, (3) for Scissor, (0) to quit
Your choice: 1
The computer's choice: 2

--> You've lost
```

When there is a tie:

```bash
Type (1) for Rock, (2) for Papper, (3) for Scissor, (0) to quit
Your choice: 1
The computer's choice: 1

--> No one wins
```

## What can be improved

- Moving the VSCode task to a Makefile using something like CMake so it can be build on multiple environments
- Remember the score between each rounds
- Limit the number of rounds
- Keep a score table in external file
