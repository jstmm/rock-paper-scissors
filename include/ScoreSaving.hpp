#pragma once

const char score_file_path[] = "../resources/scores.txt";

class ScoreSaving {
public:
    ScoreSaving()
    {
        // file = fopen(score_file_path, "r+");
    }

    bool notFound()
    {
        // return file != NULL;
        return false; // temporary HACK
    }

private:
    // FILE* file;
};
