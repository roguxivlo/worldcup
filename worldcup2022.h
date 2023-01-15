#ifndef WORLDCUP2022_H
#define WORLDCUP2022_H

#include <list>

#include "board.h"
#include "defaultscoreboard.h"
#include "dice.h"
#include "exceptions.h"
#include "player.h"
#include "types.h"
#include "worldcup.h"

using player_list_t = std::list<std::shared_ptr<Player>>;

class WorldCup2022 : public WorldCup {
public:
    // Jeżeli argumentem jest pusty wskaźnik, to nie wykonuje żadnej operacji
    // (ale nie ma błędu).
    void addDie(std::shared_ptr<Die> die) override {
        if (die != nullptr) {
            dice.add_die(die);
            n_dice++;
        }
    }

    // Dodaje nowego gracza o podanej nazwie.
    void addPlayer(player_name_t const &name) override {
        players.push_back(std::make_shared<Player>(name, INITIAL_MONEY));
    }

    // Konfiguruje tablicę wyników. Domyślnie jest skonfigurowana tablica
    // wyników, która nic nie robi.
    void setScoreBoard(std::shared_ptr<ScoreBoard> _scoreboard) override {
        this->scoreboard = _scoreboard;
    }

    // W planszy trzymamy listę pól, a każdy gracz pamięta nr pola, na którym stoi.
    // Gracz w ruchu otrzymuje kości i rzuca nimi lub nie. Następnie przechodzi
    // przez kolejne pola planszy i na każdym z nich wywołuje metodę action.
    void play(unsigned int rounds) override {
        if (n_dice > N_DICE) {
            throw TooManyDiceException();
        }
        if (n_dice < N_DICE) {
            throw TooFewDiceException();
        }
        if (players.size() > MAX_PLAYERS) {
            throw TooManyPlayersException();
        }
        if (players.size() < MIN_PLAYERS) {
            throw TooFewPlayersException();
        }
        size_t round = 0;
        Square *square;
        players_in_game = players.size();
        while (round < rounds) {
            scoreboard->onRound(round);
            for (const auto &p: players) {
                if (p->get_status() == Player::BANKRUPT) {
                    continue;
                }
                square = p->play_round(dice, board).get();
                scoreboard->onTurn(p->get_name(), p->status_to_string(), square->name,
                                   p->get_money());
                if (p->get_status() == Player::BANKRUPT) {
                    --players_in_game;
                }
                if (players_in_game == 1) {
                    for (const auto &q: players) {
                        if (q->get_status() != Player::BANKRUPT) {
                            scoreboard->onWin(q->get_name());
                            return;
                        }
                    }
                }
            }

            ++round;
        }
        if (round == rounds) {
            money_t max_money = 0;
            for (const auto &p: players) {
                if (p->get_money() > max_money) {
                    max_money = p->get_money();
                }
            }
            for (const auto &p: players) {
                if (p->get_money() == max_money) {
                    scoreboard->onWin(p->get_name());
                }
            }
        }
    }

private:
    static const size_t N_DICE = 2;
    static const size_t MIN_PLAYERS = 2;
    static const size_t MAX_PLAYERS = 11;
    constexpr static const money_t INITIAL_MONEY = 1000;
    player_list_t players;
    size_t players_in_game;
    std::shared_ptr<ScoreBoard> scoreboard;
    Dice dice;
    size_t n_dice = 0;
    Board board;
};

#endif  // WORLDCUP2022_H