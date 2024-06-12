#include "../include/CardReader.hpp"

#include <fstream>

void CardReader::openFile(const std::string& path) {
    pathToCardList_ = path;

    std::ifstream file(pathToCardList_);

    std::string line;
    while(std::getline(file, line)) {
        file_.push_back(line);
    }
}

bool CardReader::isFileOpen() {
    return !file_.empty();
}

void CardReader::processFile() {
    CardInfo info = CardInfo();
    int id = 0;
    for(const auto& line : file_) {
        std::string nameOfAtribute = line.substr(0, line.find_first_of(':'));

        if (nameOfAtribute == "id") {
            id = std::stoi(line.substr(line.find_first_of(':') + 1, 69));
            info.setID(id);
        } else if (nameOfAtribute == "name") {
            info.setName(line.substr(line.find_first_of('\"') + 1, line.size() - line.find_first_of('\"') - 2));
        } else if (nameOfAtribute == "attack") {
            info.setAttack(std::stoi(line.substr(line.find_first_of(':') + 1, 69)));
        } else if (nameOfAtribute == "hp") {
            info.setHP(std::stoi(line.substr(line.find_first_of(':') + 1, 69)));
        } else if (nameOfAtribute == "cost") {
            info.setCost(std::stoi(line.substr(line.find_first_of(':') + 1, 69)));
        } else if (nameOfAtribute == "points") {
            info.setPoints(std::stoi(line.substr(line.find_first_of(':') + 1, 69)));
        } else if (nameOfAtribute == "description") {
            info.setDescription(line.substr(line.find_first_of('\"') + 1, line.size() - line.find_first_of('\"') - 2));
        } else if (nameOfAtribute == "imagePath") {
            info.setImagePath(line.substr(line.find_first_of('\"') + 1, line.size() - line.find_first_of('\"') - 2));
            cards_.insert(std::pair<int, CardInfo>(id, info));
        }
    }
}
