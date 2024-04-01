#include "Program.h"

void Program::getMenuSelection()
{
    int input;
    std::cin >> input;
    menu_selection = static_cast<MenuSelection>(input);
}

void Program::processMenuSelection()
{
    switch (menu_selection) {
    case MenuSelection::Undefined:
        break;
    case MenuSelection::InfiniteRounds:
        startInfiniteRoundGame();
        break;
    case MenuSelection::TenRounds:
        startTenRoundsGame();
        break;
    case MenuSelection::ScoreTable:
        printScoreTable();
        break;
    default:
        break;
    }
}

void Program::printResult(Game& game)
{
    printf("\n\n--> ");

    if (game.userIsWinning()) {
        printf("You win the round");
    } else if (game.computerIsWinnning()) {
        printf("Computer wins the round");
    } else {
        printf("No one wins the round");
    }

    printf("\n\n--------------------------------------------------------------------------------\n");
    printf("    You : %d     Computer : %d\n", game.getUserScore(), game.getComputerScore());
    printf("================================================================================\n");
}

void Program::printFinalResult(Game& game)
{
    // FIX ME
    // if (game.userIsWinning()) {
    //     printf("\nYou win the game!!!\n");
    // } else if (game.computerIsWinnning()) {
    //     printf("\nThe computer wins the game\n");
    // } else {
    //     printf("\nNo one wins the game\n");
    // }
    // printf("================================================================================\n");
}

void Program::saveResultToFile(Game& game)
{
    // FIX ME
    // FILE* file = fopen(score_file_path, "a+");
    // char buffer[10];
    // sprintf(buffer, "%d,%d\n", game.getUserScore(), game.getComputerScore());
    // fputs(buffer, file);
    // fclose(file);
}

void Program::startInfiniteRoundGame()
{
    Game game {};
    do {
        game.startNewRound();

        if (game.isFinished()) {
            printFinalResult(game);
            saveResultToFile(game);
            break;
        }

        printResult(game);
    } while (true);
}

void Program::startTenRoundsGame()
{
    Game game {};

    int round = 0;
    int user_score = 0;
    int computer_score = 0;
    int round_left = 10;

    do {
        auto user_choice = Action::UndefinedAction;

        printf("Round %d\n\n", ++round);
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

        if (user_choice == Action::FinishGame) {
            printFinalResult(game);
            saveResultToFile(game);
            break;
        }

        auto computer_choice = static_cast<Action>((rand() % 3) + 1);

        printResult(game);

        round_left--;
        if (round_left == 0) {
            printFinalResult(game);
            saveResultToFile(game);
            break;
        }
    } while (true);
}

void Program::printScoreTable()
{
    ScoreSaving score_saving {};

    if (score_saving.notFound()) {
        printf("(no records)");
        return;
    }

    // FIX ME
    // printf("Scores\n");
    // char line_buffer[10];
    // while (fgets(line_buffer, sizeof(line_buffer), file) != NULL) {
    //     printf("%s", line_buffer);
    // }
    // fclose(file);
    printf("================================================================================\n");
}
