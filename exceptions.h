#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class TooFewDiceException : public std::exception {
};

class TooManyDiceException : public std::exception {
};

class TooFewPlayersException : public std::exception {
};

class TooManyPlayersException : public std::exception {
};

#endif  // EXCEPTIONS_H