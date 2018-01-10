#include <string>
#include <iostream>
#include <list>
#include "exitStatusCodes.h"
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
        return INCORRECT_ARGS_NUMBER_STATUS;
    }

    inputFileName = static_cast<std::string>(argv[1]);

    try {
        std::ifstream inputFile(inputFileName + ".dat");
        if (!inputFile.is_open()) {
            std::cout << "Check if your file exists" << std::endl;
            usage();
            return FILE_DOESNT_EXISTS_STATUS;
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
        return KNOWN_EXCEPTION_CAUGHT_STATUS;
    }
    catch (...) {
        std::cout << "Something went wrong. Sorry" << std::endl;
        return UNKNOWN_EXCEPTION_CAUGHT_STATUS;
    }

    return CORRECT_EXIT_STATUS;
}

void usage() {
    std::cout << "See usage:\nWord-Ladder <filename>\nFilename without .dat extension" << std::endl;
}