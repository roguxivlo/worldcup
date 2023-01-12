#ifndef WORLDCUP2022_H
#define WORLDCUP2022_H

#include <list>

#include "board.h"
#include "player.h"
#include "exceptions.h"
#include "worldcup.h"

// todo: jakich typów użyć do pieniedzy?

const unsigned int N_DICE = 2;
const unsigned int MIN_PLAYERS = 2;
const unsigned int MAX_PLAYERS = 11;
const unsigned int INITIAL_MONEY = 1000;

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
  void addPlayer(std::string const &name) override {
    players.push_back(Player(name, INITIAL_MONEY));
  }

  // Konfiguruje tablicę wyników. Domyślnie jest skonfigurowana tablica
  // wyników, która nic nie robi.
  void setScoreBoard(std::shared_ptr<ScoreBoard> scoreboard) override {
    this->scoreboard = scoreboard;
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
  void play(unsigned int rounds) override {}

 private:
  std::list<Player> players;
  std::shared_ptr<ScoreBoard> scoreboard;
  std::shared_ptr<Die> dice[N_DICE];
  size_t n_dice = 0;
};

#endif  // WORLDCUP2022_H