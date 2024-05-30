#include "../include/card.hpp" // firstly include header with class

#include <algorithm> // other inlcudes goes here in alphabetical order

Card::Card() {
    cost_ = 1;
}
Card::Card(const int& cost) : cost_(cost) { // use initialization lists, 'cause they are cool
  // look, it's empty *how fancy*
}