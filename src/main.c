#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

enum Action {
    Quit = 0,
    Rock = 1,
    Paper = 2,
    Scissor = 3
};

bool user_wins(enum Action user_choice, enum Action computer_wins) {
    return (user_choice == Rock && computer_wins == Scissor) |
        (user_choice == Paper && computer_wins == Rock) |
        (user_choice == Scissor && computer_wins == Paper);
}

int main(int argc, char const *argv[]) {
    printf("Welcome to the Rock Paper Scissor Game!\n=======================================\n");

    srand(time(0));

    int user_score = 0;
    int computer_score = 0;

    do {
        enum Action user_choice = -1;
        bool quit_game = false;

        printf("\nType (1) for Rock, (2) for Paper, (3) for Scissor, (0) to quit\n");

        do {
            int int_user_choice = -1;
            printf("Your choice: ");
            scanf("%d", &int_user_choice);

            if (int_user_choice == Quit) {
                quit_game = true;
            } else if (-1 <= int_user_choice & int_user_choice <= 3) {
                user_choice = int_user_choice;
            } else {
                printf("Invalid input, try again\n");
            }
        } while ((user_choice == -1) & (quit_game == false));

        if (quit_game) {
            break;
        }

        enum Action computer_choice = (rand() % 3) + 1;

        printf("The computer's choice: %d", computer_choice);
        printf("\n\n--> ");

        if (user_choice == computer_choice) {
            printf("No one wins");
        } else if (user_wins(user_choice, computer_choice)) {
            user_score++;
            printf("You won");
        } else {
            computer_score++;
            printf("You've lost");
        }

        printf("\n\n---------------------------------------\n");
        printf("    You : %d     Computer : %d\n", user_score, computer_score);
        printf("---------------------------------------\n");
    } while (true);

    printf("\nBye!\n\n");

    return 0;
}
