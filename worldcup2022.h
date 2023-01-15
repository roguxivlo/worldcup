#ifndef WORLDCUP2022_H
#define WORLDCUP2022_H

#include <list>

#include "board.h"
#include "defaultscoreboard.h"
#include "exceptions.h"
#include "player.h"
#include "types.h"
#include "worldcup.h"

// TODO czy ddefault score board obowiązkowy.

class WorldCup2022 : public WorldCup {
 public:
  virtual ~WorldCup2022() = default;

  // Jeżeli argumentem jest pusty wskaźnik, to nie wykonuje żadnej operacji
  // (ale nie ma błędu).
  void addDie(std::shared_ptr<Die> die) override {
    if (die != nullptr) {
      dice[(n_dice++) % N_DICE] = die;
    }
  }

  // Dodaje nowego gracza o podanej nazwie.
  void addPlayer(player_name_t const &name) override {
    players.push_back(Player(name, INITIAL_MONEY));
  }

  // Konfiguruje tablicę wyników. Domyślnie jest skonfigurowana tablica
  // wyników, która nic nie robi.
  void setScoreBoard(std::shared_ptr<ScoreBoard> scoreboard) override {
    this->scoreboard = scoreboard;
    scoreboard_set = true;
  }

  // Przeprowadza rozgrywkę co najwyżej podanej liczby rund (rozgrywka może
  // skończyć się wcześniej).
  // Jedna runda obejmuje po jednym ruchu każdego gracza.
  // Gracze ruszają się w kolejności, w której zostali dodani.
  // Na początku każdej rundy przekazywana jest informacja do tablicy wyników
  // o początku rundy (onRound), a na zakończenie tury gracza informacje
  // podsumowujące dla każdego gracza (onTurn).
  // Rzuca TooManyDiceException, jeśli jest zbyt dużo kostek.
  // Rzuca TooFewDiceException, jeśli nie ma wystarczającej liczby kostek.
  // Rzuca TooManyPlayersException, jeśli jest zbyt dużo graczy.
  // Rzuca TooFewPlayersException, jeśli liczba graczy nie pozwala na
  // rozpoczęcie gry.
  // Wyjątki powinny dziedziczyć po std::exception.
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
    players_in_game = players.size();
    size_t round = 0;
    Square *square;
    while (round < rounds && players_in_game > 1) {
      scoreboard->onRound(round);
      for (auto p : players) {
        size_t moves = dice[0]->roll() + dice[1]->roll();
        square = p.play_round(moves, board);
        scoreboard->onTurn(p.get_name(), p.get_status(), square->name,
                           p.get_money());
      }
    }
    for (auto p : players) {
    }
  }

 private:
  static const size_t N_DICE = 2;
  static const size_t MIN_PLAYERS = 2;
  static const size_t MAX_PLAYERS = 11;
  static const money_t INITIAL_MONEY = 1000;
  static const DefaultScoreBoard DEFAULT_SCOREBOARD;
  player_list_t players;
  size_t players_in_game;
  bool scoreboard_set = false;
  std::shared_ptr<ScoreBoard> scoreboard;
  std::shared_ptr<Die> dice[N_DICE];
  size_t n_dice = 0;
  Board board;
};

#endif  // WORLDCUP2022_H