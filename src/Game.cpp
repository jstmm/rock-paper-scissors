#include "Game.h"

void Game::startNewRound()
{
    if (current_round != 1)
        current_round += 1;
    user_choice = Action::UndefinedAction;
    computer_choice = Action::UndefinedAction;
    printf("Round %d\n\n", current_round);
    printf("\nType (1) for Rock, (2) for Paper, (3) for Scissor, (0) to quit the game\n");
    do {
        int input = 0;
        printf("> ");
        scanf("%d", &input);
        user_choice = static_cast<Action>(input);

        if (user_choice < Action::UndefinedAction | Action::Scissor < user_choice) {
            printf("Invalid input, try again\n");
            user_choice = Action::UndefinedAction;
        }
    } while (user_choice == Action::UndefinedAction);
    // printf("You chose: %d", user_choice); FIX ME

    computer_choice = static_cast<Action>((rand() % 3) + 1);
    // printf("\nThe computer's choice: %d", computer_choice); FIX ME

    if (userWonLastRound()) {
        user_score += 1;
    } else if (computerWonLastRound()) {
        computer_score += 1;
    }
}

bool Game::playerAWins(enum Action player_a, enum Action player_b)
{
    return (player_a == Action::Rock && player_b == Action::Scissor)
        || (player_a == Action::Paper && player_b == Action::Rock)
        || (player_a == Action::Scissor && player_b == Action::Paper);
}
