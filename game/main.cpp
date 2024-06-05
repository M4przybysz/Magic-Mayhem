#include "include/CardReader.hpp"

#include <iostream>
#include <memory>


int main(int argc, char *argv[]) {
    std::shared_ptr<Reader::CardReader> reader = std::make_shared<Reader::CardReader>(Reader::CardReader());

    reader->openFile("./cards.list");

    if(!reader->isFileOpen()) {
        std::cerr << "Error: File not opened!\n";
        return 1;
    }
    else {
        std::clog << "File opened successfully!\n";
    }
    reader->processFile();
    

    return 0;
}