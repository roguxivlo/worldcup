#ifndef DEFAULT_SCORE_BOARD_H
#define DEFAULT_SCORE_BOARD_H

#include "worldcup.h"

class DefaultScoreBoard : public ScoreBoard {
public:
    // Wywoływane, aby zasygnalizować początek rundy.
    void onRound([[maybe_unused]] unsigned int roundNo) override {  }

    // Wywoływane po skończeniu kolejki danego gracza, aby przekazać informacje o
    // aktualnym stanie gracza.
    void onTurn([[maybe_unused]] std::string const &playerName, [[maybe_unused]] std::string const &playerStatus,
                [[maybe_unused]] std::string const &squareName, [[maybe_unused]] unsigned int money) override {
    }

    // Wywoływane, aby zasygnalizować zwycięstwo danego gracza.
    void onWin([[maybe_unused]] std::string const &playerName) override {  }
};

#endif  // DEFAULT_SCORE_BOARD_H