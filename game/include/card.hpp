#pragma once

class Card {
 public:
    Card();
    Card(const int& cost);

    int getCost() const { return cost_; }

    void setCost(const int& cost) { cost_ = cost; }


 private:
    int cost_;
};
