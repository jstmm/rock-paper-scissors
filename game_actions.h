#ifndef GAME_ACTIONS_H
#define GAME_ACTIONS_H

#include <stdbool.h>

enum Action {
    UndefinedAction = -1,
    Quit            = 0,
    Rock            = 1,
    Paper           = 2,
    Scissor         = 3
};

bool b_user_wins(enum Action, enum Action);

#endif /* GAME_ACTIONS_H */
