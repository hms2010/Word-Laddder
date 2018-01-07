#include <string>
#include <iostream>
#include <list>
#include "WordGraph.h"

void usage();

int main(int argc, char **argv) {
    std::list<std::string> path;
    uint8_t wordsLength = 0;

    std::string startWord, endWord;

    std::string dictionaryName;
    dictionaryName = "default";


    std::string inputFileName;

    if (argc != 2) {
        usage();
        return 1;
    }

    inputFileName = static_cast<std::string>(argv[1]);

    try {
        std::ifstream inputFile(inputFileName + ".dat");
        if (!inputFile.is_open()) {
            usage();
            return 1;
        }
        inputFile >> startWord;
        inputFile >> endWord;
        inputFile.close();
        wordsLength = static_cast<uint8_t >(startWord.length());

        WordGraph graph(wordsLength, dictionaryName);
        path = graph.createPath(startWord, endWord);

        std::ofstream outputFile(inputFileName + ".ans");
        if (path.empty()) {
            outputFile << "Path was not found" << std::endl;
        }

        for (auto &it: path) {
            outputFile << it << std::endl;
        }
    }
    catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (...) {
        std::cout << "Something went wrong. Sorry" << std::endl;
    }

    return 0;
}

void usage() {
    std::cout << "See usage:\nWord-Ladder <filename>\nFilename without .dat extension" << std::endl;
}