// Authors: Antoni Stachowski, Michał Kostyk
// Date: 2023-01-15
// Description: Testy dla WorldCup2022
// License: Do What The Fuck You Want To Public License (WTFPL)

#include <sstream>
#include <memory>
#include <string>
#include <cassert>
#include "worldcup2022.h"
#include <iostream>
#include "scoreboard.h"
#include "test_dice.h"
#include "regex"

std::string const RED = "\033[1;31m";
std::string const GREEN = "\033[1;32m";
std::string const RESET = "\033[0m";

int main() {
    std::cout << RESET << "Results test 3 running\n" << RESET;

    std::shared_ptr<Die> die1 = std::make_shared<SnakeEyeDie>();
    std::shared_ptr<Die> die2 = std::make_shared<WeirdlySpecificDie>();

    std::shared_ptr<TextScoreBoard> scoreboard = std::make_shared<TextScoreBoard>();

    std::shared_ptr<WorldCup> worldCup2022 = std::make_shared<WorldCup2022>();
    worldCup2022->addDie(die1);
    worldCup2022->addDie(die2);
    worldCup2022->addPlayer("Kleofas");
    worldCup2022->addPlayer("Ildefons");
    worldCup2022->addPlayer("Godehard");
    worldCup2022->setScoreBoard(scoreboard);

    worldCup2022->play(5);

    const std::regex RoundOne("^=== Runda: 0\nKleofas \\[\\*\\*\\* czekanie: 3 \\*\\*\\*] \\[620] - Żółta kartka\nIldefons \\[w grze] \\[620] - Mecz z Meksykiem\nGodehard \\[w grze] \\[1280] - Mecz z Lie*chtensteinem\n(.*\n)*$");
    const std::regex RoundTwo("^(.*\n)*=== Runda: 1\nKleofas \\[\\*\\*\\* czekanie: 2 \\*\\*\\*] \\[620] - Żółta kartka\nIldefons \\[w grze] \\[440] - Bukmacher\nGodehard \\[w grze] \\[1680] - Mecz z Arabią Saudyjską\n(.*\n)*$");
    const std::regex RoundThree("^(.*\n)*=== Runda: 2\nKleofas \\[\\*\\*\\* czekanie: 1 \\*\\*\\*] \\[620] - Żółta kartka\nIldefons \\[w grze] \\[310] - Gol\nGodehard \\[w grze] \\[850] - Rzut karny\n(.*\n)*$");
    const std::regex RoundFour("^(.*\n)*=== Runda: 3\nKleofas \\[w grze] \\[1290] - Mecz z Argentyną\nIldefons \\[\\*\\*\\* bankrut \\*\\*\\*] \\[0] - Mecz z San Marino\nGodehard \\[w grze] \\[1380] - Mecz z San Marino\n(.*\n)*$");
    const std::regex RoundFive("^(.*\n)*=== Runda: 4\nKleofas \\[w grze] \\[4130] - Mecz z Francją\nGodehard \\[w grze] \\[480] - Bukmacher\n=== Zwycięzca: Kleofas\\s*$");

    std::cerr << scoreboard->str();
    std::cerr << RED;
    assert (std::regex_match(scoreboard->str(), RoundOne));
    assert (std::regex_match(scoreboard->str(), RoundTwo));
    assert (std::regex_match(scoreboard->str(), RoundThree));
    assert (std::regex_match(scoreboard->str(), RoundFour));
    assert (std::regex_match(scoreboard->str(), RoundFive));

    std::cout << GREEN << "Results test 3 passed\n\n" << RESET;
    return 0;

}