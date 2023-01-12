#ifndef TOO_MANY_PLAYERS_EXCEPTION_H
#define TOO_MANY_PLAYERS_EXCEPTION_H

#include <exception>

class TooManyPlayersException : public std::exception {
 public:
  TooManyPlayersException() = default;
  ~TooManyPlayersException() = default;
};

#endif  // TOO_MANY_PLAYERS_EXCEPTION_u