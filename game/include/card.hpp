#pragma once // do this (#define is cringe)

class Card {
 public: // one space before classificator
    Card();
    Card(const int& cost); // const reference everything you can

    int getCost() const { return cost_; } // one line funcs like getters and setters should be in class declaration like this // also const functions that doesn't change the object

    void setCost(const int& cost) { cost_ = cost; }


 private:
    int cost_; // default values should be defined in constructors
};
