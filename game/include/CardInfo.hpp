#pragma once

#include <string>

class CardInfo {
 public:
    CardInfo() {}

    int getID() const { return id_; }
    std::string getName() const { return name_; }
    int getAttack() const { return attack_; }
    int getHP() const { return hp_; }
    int getCost() const { return cost_; }
    int getPoints() const { return points_; }
    std::string getDescription() const { return description_; }
    std::string getImagePath() const { return imagePath_; }

    void setID(const int& id) { id_ = id; }
    void setName(const std::string& name) { name_ = name; }
    void setAttack(const int& attack) { attack_ = attack; }
    void setHP(const int& hp) { hp_ = hp; }
    void setCost(const int& cost) { cost_ = cost; }
    void setPoints(const int& points) { points_ = points; }
    void setDescription(const std::string& description) { description_ = description; }
    void setImagePath(const std::string& imagePath) { imagePath_ = imagePath; }

 private:
    int id_;
    std::string name_;
    int attack_;
    int hp_;
    int cost_;
    int points_;
    std::string description_;
    std::string imagePath_;
};
