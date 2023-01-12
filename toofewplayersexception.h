#ifndef TOO_FEW_PLAYERS_EXCEPTION_H
#define TOO_FEW_PLAYERS_EXCEPTION_H

#include <exception>

class TooFewPlayersException : public std::exception {
 public:
  TooFewPlayersException() = default;
  ~TooFewPlayersException() = default;
};

#endif  // TOO_FEW_PLAYERS_EXCEPTION_H