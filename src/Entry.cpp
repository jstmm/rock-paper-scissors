#include <iostream>

#include "Program.h"

int main(int argc, char const* argv[])
{
    Program program {};

    printf("\n\nWelcome to the Rock Paper Scissor Game!\n");
    printf("=======================================\n\n");

    do {

        printf("(1) Infinite rounds\n");
        printf("(2) Ten rounds\n");
        printf("(3) Score Table\n");
        printf("(0) Quit\n");
        printf("> ");
        program.getMenuSelection();
        printf("================================================================================\n");
        program.processMenuSelection();

    } while (!program.isFinished());

    printf("\nBye!\n\n");

    return 0;
}
