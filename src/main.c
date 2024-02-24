#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

enum Action {
    UndefinedAction = -1,
    Quit            = 0,
    Rock            = 1,
    Paper           = 2,
    Scissor         = 3
};

enum GameType {
    UndefinedGameType = -1,
    InfiniteRounds    = 1,
    TenRounds         = 2
};

bool b_user_wins(enum Action user_choice, enum Action computer_choice) {
    return
        ( user_choice == Rock    && computer_choice == Scissor ) |
        ( user_choice == Paper   && computer_choice == Rock    ) |
        ( user_choice == Scissor && computer_choice == Paper   );
}

void print_result_for_the_round(int user_choice, int computer_choice, int *user_score, int *computer_score) {
    printf("The computer's choice: %d", computer_choice);
    printf("\n\n--> ");

    if (user_choice == computer_choice) {
        printf("No one wins the round");
    } else if (b_user_wins(user_choice, computer_choice)) {
        *user_score = (*user_score) + 1;
        printf("You win the round");
    } else {
        *computer_score = (*computer_score) + 1;
        printf("Computer wins the round");
    }

    printf("\n\n---------------------------------------\n");
    printf("    You : %d     Computer : %d\n", *user_score, *computer_score);
    printf("---------------------------------------\n");
}

void print_final_result(int user_score, int computer_score) {
    if (user_score > computer_score) {
        printf("\nYou win the game!!!\n");
    } else if (computer_score > user_score) {
        printf("\nThe computer wins the game\n");
    } else {
        printf("\nNo one wins the game\n");
    }
}

int main(int argc, char const *argv[]) {
    srand(time(0));

    int user_score = 0;
    int computer_score = 0;
    int game_type = UndefinedGameType;
    int round_left = 10;

    printf("Welcome to the Rock Paper Scissor Game!\n");
    printf("=======================================\n\n");
 
    printf("Choose a game type:\n");
    printf("(1) Infinite rounds\n"); 
    printf("(2) Ten rounds\n");
    printf("> ");
    scanf("%d", &game_type);

    do {
        enum Action user_choice = UndefinedAction;

        printf("\nType (1) for Rock, (2) for Paper, (3) for Scissor, (0) to quit the game\n");

        do {
            printf("> ");
            scanf("%d", &user_choice);

            if (user_choice < UndefinedAction | Scissor < user_choice) {
                printf("Invalid input, try again\n");
                user_choice = UndefinedAction;
            }
        } while (user_choice == UndefinedAction);

        if (user_choice == Quit) {
            break;
        }

        enum Action computer_choice = (rand() % 3) + 1;

        print_result_for_the_round(user_choice, computer_choice, &user_score, &computer_score);

        if (game_type == TenRounds) {
            round_left--;
        }
        if (round_left == 0) {
            print_final_result(user_score, computer_score);
            break;
        }

    } while (true);

    printf("\nBye!\n\n");

    return 0;
}
