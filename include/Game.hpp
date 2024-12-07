#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum class Action {
    UndefinedAction,
    FinishGame,
    Rock,
    Paper,
    Scissor
};

class Game {
public:
    Game()
        : current_round { 1 }
        , computer_score { 0 }
        , user_score { 0 }
    {
        srand(time(0));
    }

    bool computerIsWinnning() { return computer_score < user_score; }
    bool userIsWinning() { return user_score > computer_score; }
    bool isFinished() { return user_choice == Action::FinishGame; }
    int getComputerScore() { return computer_score; }
    int getUserScore() { return user_score; }
    void startNewRound();
    bool userWonLastRound() { return playerAWins(user_choice, computer_choice); }
    bool computerWonLastRound() { return playerAWins(computer_choice, user_choice); }

private:
    int current_round;
    int user_score;
    int computer_score;
    enum Action user_choice;
    enum Action computer_choice;

    bool playerAWins(enum Action player_a, enum Action player_b);
};
