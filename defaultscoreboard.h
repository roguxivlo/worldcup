#ifndef DEFAULT_SCORE_BOARD_H
#define DEFAULT_SCORE_BOARD_H

#include "worldcup.h"

class DefaultScoreBoard : public ScoreBoard {
public:
    // Wywoływane, aby zasygnalizować początek rundy.
    void onRound(unsigned int roundNo) override { return; }

    // Wywoływane po skończeniu kolejki danego gracza, aby przekazać informacje o
    // aktualnym stanie gracza.
    void onTurn(std::string const &playerName, std::string const &playerStatus,
                std::string const &squareName, unsigned int money) override {
        return;
    }

    // Wywoływane, aby zasygnalizować zwycięstwo danego gracza.
    void onWin(std::string const &playerName) override { return; }
};

#endif  // DEFAULT_SCORE_BOARD_H