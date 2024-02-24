# Rock Paper Scissors

This is a console version of Rock Paper Scissors written in C.

# Features

- Multiple game modes:
  - Infinite rounds - to play indefinitely
  - Ten rounds - a game limited to ten rounds

## Installation

1. Install the [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
2. Build the variant needed (Debug or Release)
3. Run the program from the CMake extension or by executing the following command from the project folder:

```bash
$ build/rock-paper-scissors
```

## Usage

Initial output:

```bash
Welcome to the Rock Paper Scissor Game!
=======================================

Choose a game mode:
(1) Infinite rounds
(2) Ten rounds
>  
```

When user wins:

```bash
Type (1) for Rock, (2) for Papper, (3) for Scissor, (0) to quit the game
> 1
The computer's choice: 3

--> You win the round

---------------------------------------
    You : 1     Computer : 1
---------------------------------------
```

When user loses:

```bash
Type (1) for Rock, (2) for Papper, (3) for Scissor, (0) to quit the game
> 1
The computer's choice: 2

--> The computer wins the round

---------------------------------------
    You : 0     Computer : 1
---------------------------------------
```

When there is a tie:

```bash
Type (1) for Rock, (2) for Papper, (3) for Scissor, (0) to quit the game
> 1
The computer's choice: 1

--> No one wins the round

---------------------------------------
    You : 0     Computer : 0
---------------------------------------
```

Final result:

```bash
---------------------------------------
    You : 2     Computer : 1
---------------------------------------

You win the game!!!
```

## Roadmap

- Keep a score table in external file
- Add tests
- Make the game full screen
