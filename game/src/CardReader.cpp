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