#include "../include/CardReader.hpp"

#include <fstream>

void Reader::CardReader::openFile(const std::string& path) {
    pathToCardList_ = path;

    std::ifstream file(pathToCardList_);

    std::string line;
    while(std::getline(file, line)) {
        file_.push_back(line);
    }
}

bool Reader::CardReader::isFileOpen() {
    return !file_.empty();
}

void Reader::CardReader::processFile() {
    CardInfo info = CardInfo();
    int id = 0;
    for(const auto& el : file_) {
        std::string nameOfAtribute = el.substr(0, el.find_first_of(':'));
        
        if (nameOfAtribute == "id") {
            id = std::stoi(el.substr(el.find_first_of(':') + 1, 69));
            info.setID(id);
        } else if (nameOfAtribute == "name") {
            info.setName(el.substr(el.find_first_of('\"') + 1, el.size() - el.find_first_of('\"') - 2));
        } else if (nameOfAtribute == "attack") {
            info.setAttack(std::stoi(el.substr(el.find_first_of(':') + 1, 69)));
        } else if (nameOfAtribute == "hp") {
            info.setHP(std::stoi(el.substr(el.find_first_of(':') + 1, 69)));
        } else if (nameOfAtribute == "cost") {
            info.setCost(std::stoi(el.substr(el.find_first_of(':') + 1, 69)));
        } else if (nameOfAtribute == "points") {
            info.setPoints(std::stoi(el.substr(el.find_first_of(':') + 1, 69)));
        } else if (nameOfAtribute == "description") {
            info.setDescription(el.substr(el.find_first_of('\"') + 1, el.size() - el.find_first_of('\"') - 2));
        } else if (nameOfAtribute == "imagePath") {
            info.setImagePath(el.substr(el.find_first_of('\"') + 1, el.size() - el.find_first_of('\"') - 2));
            cards_.insert(std::pair<int, CardInfo>(id, info));
        }
    }
}
