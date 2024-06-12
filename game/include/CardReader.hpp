#pragma once

// Local Headers
#include "CardInfo.hpp"

// C++ Headers
#include <map>
#include <string>
#include <vector>

class CardReader {
 public:
    CardReader() {}

    std::map<int, CardInfo> getCardsMap() { return cards_; }
    
    void openFile(const std::string& path);
    bool isFileOpen();
    void processFile();

 private:
    std::map<int, CardInfo> cards_;
    std::string pathToCardList_;
    std::vector<std::string> file_;
};
