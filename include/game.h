#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

const char score_file_path[] = "../resources/scores.txt";

enum GameType {
    UndefinedGameType = -1,
    QuitGame          = 0,
    InfiniteRounds    = 1,
    TenRounds         = 2,
    ScoreTable        = 3
};

enum Action {
    UndefinedAction = -1,
    Quit            = 0,
    Rock            = 1,
    Paper           = 2,
    Scissor         = 3
};

void rock_paper_scissors_game(void);

#endif /* GAME_H */
