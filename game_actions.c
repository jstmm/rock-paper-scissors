#include "game_actions.h"

bool b_user_wins(enum Action user_choice, enum Action computer_choice) {
    return
        ( user_choice == Rock    && computer_choice == Scissor ) |
        ( user_choice == Paper   && computer_choice == Rock    ) |
        ( user_choice == Scissor && computer_choice == Paper   );
}
