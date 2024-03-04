#include <criterion/criterion.h>

#include "game.h"

Test(user_wins, test) {
    enum Action user_choice = Rock;
    enum Action computer_choice = Scissor;
    bool result = b_user_wins(user_choice, computer_choice);
    cr_assert(result == true, "Incorrect");
}

Test(user_loses, test) {
    enum Action user_choice = Rock;
    enum Action computer_choice = Paper;
    bool result = b_user_wins(user_choice, computer_choice);
    cr_assert(result == false, "Incorrect");
}
