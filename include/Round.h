#pragma once

class Round {
public:
    Round(int round_nb)
        : round_nb { round_nb }
    {
    }

private:
    int round_nb;
    int user_score;
    int computer_score;
};
