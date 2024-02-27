#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    QuitGame          = 0,
    InfiniteRounds    = 1,
    TenRounds         = 2,
    ScoreTable        = 3
};

const char score_file_path[] = "../resources/scores.txt";

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

    printf("\n\n--------------------------------------------------------------------------------\n");
    printf("    You : %d     Computer : %d\n", *user_score, *computer_score);
    printf("================================================================================\n");
}

void print_final_result(int user_score, int computer_score) {
    if (user_score > computer_score) {
        printf("\nYou win the game!!!\n");
    } else if (computer_score > user_score) {
        printf("\nThe computer wins the game\n");
    } else {
        printf("\nNo one wins the game\n");
    }
    printf("================================================================================\n");
}

void save_result_to_file(int user_score, int computer_score) {
    FILE *file = fopen(score_file_path, "a+"); 
    char buffer[10];
    sprintf(buffer, "%d,%d\n", user_score, computer_score);
    fputs(buffer, file);
    fclose(file);
}

void start_infinite_round_game() {
    int round = 0;

    do {
        int user_score = 0;
        int computer_score = 0;
        enum Action user_choice = UndefinedAction;

        printf("Round %d\n\n", ++round);
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
    } while(true);
}

void start_ten_rounds_game() {
    int round = 0;
    int user_score = 0;
    int computer_score = 0;
    int round_left = 10;

    do {
        enum Action user_choice = UndefinedAction;

        printf("Round %d\n\n", ++round);
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

        round_left--;
        if (round_left == 0) {
            print_final_result(user_score, computer_score);
            save_result_to_file(user_score, computer_score);
            break;
        }

    } while (true);
}

void print_score_table() {
    FILE *file = fopen(score_file_path, "r+");
    if (!file) {
        printf("(no records)");
        return;
    }
    printf("\n====== Scores ======\n");
    char line_buffer[10];
    while (fgets(line_buffer, sizeof(line_buffer), file) != NULL)
    {
        printf("%s", line_buffer);
    }
    fclose(file);
    printf("================================================================================\n");
}

int main(int argc, char const *argv[]) {
    int user_score = 0;
    int computer_score = 0;
    int menu_selection = UndefinedGameType;
    int round_left = 10;

    srand(time(0));

    printf("\n\nWelcome to the Rock Paper Scissor Game!\n");
    printf("=======================================\n\n");
 
    printf("(1) Infinite rounds\n"); 
    printf("(2) Ten rounds\n");
    printf("(3) Score Table\n");
    printf("(0) Quit\n");
    printf("> ");
    scanf("%d", &menu_selection);
    printf("================================================================================\n");

    switch (menu_selection)
    {
    case UndefinedGameType:
        break;
    case InfiniteRounds:
        start_infinite_round_game();
        break;
    case TenRounds:
        start_ten_rounds_game();
        break;
    case ScoreTable:
        print_score_table();
        break;
    default:
        break;
    }

    printf("\nBye!\n\n");

    return 0;
}
