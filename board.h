#ifndef BOARD_H
#define BOARD_H

#include <map>
#include <vector>
#include <memory>

#include "bookie.h"
#include "goal.h"
#include "match.h"
#include "notraining.h"
#include "penalty.h"
#include "start.h"
#include "types.h"
#include "yellowcard.h"

class Player;

using square_list_t = std::vector<std::shared_ptr<Square>>;

class Board {
public:
    std::shared_ptr<Square> get_square(size_t position) { return squares[position]; }

    size_t get_n_squares() const { return N_SQUARES; }

private:
    static const size_t N_SQUARES = 12;
    const square_list_t squares = {
            std::make_shared<Start>("Początek sezonu", 50),
            std::make_shared<Match>("Mecz z San Marino", 160, Match::FRIENDLY),
            std::make_shared<NoTraining>("Dzień wolny od treningu"),
            std::make_shared<Match>("Mecz z Liechtensteinem", 220, Match::FRIENDLY),
            std::make_shared<YellowCard>("Żółta kartka", 3),
            std::make_shared<Match>("Mecz z Meksykiem", 300, Match::GROUP_STAGE),
            std::make_shared<Match>("Mecz z Arabią Saudyjską", 280, Match::GROUP_STAGE),
            std::make_shared<Bookie>("Bukmacher", 3, 100, 100),
            std::make_shared<Match>("Mecz z Argentyną", 250, Match::GROUP_STAGE),
            std::make_shared<Goal>("Gol", 120),
            std::make_shared<Match>("Mecz z Francją", 400, Match::FINAL),
            std::make_shared<Penalty>("Rzut karny", 180)};
};

#endif  // BOARD_H