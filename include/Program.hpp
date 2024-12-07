#pragma once

#include <iostream>

#include "Game.h"
#include "ScoreSaving.h"

enum class MenuSelection {
    Undefined = -1,
    InfiniteRounds = 1,
    TenRounds = 2,
    ScoreTable = 3,
    Quit = 0
};

class Program {
public:
    Program()
        : menu_selection { MenuSelection::Undefined }
    {
    }

    void getMenuSelection();

    void processMenuSelection();

    bool isFinished() { return menu_selection == MenuSelection::Quit; }

private:
    MenuSelection menu_selection;

    void printResult(Game& game);

    void printFinalResult(Game& game);

    void saveResultToFile(Game& game);

    void startInfiniteRoundGame();

    void startTenRoundsGame();

    void printScoreTable();
};
