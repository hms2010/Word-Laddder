#include <string>
#include <iostream>
#include <list>
#include "WordGraph.h"

int main(int argc, char **argv) {
    std::list<std::string> path;
    std::string startWord, endWord;
    std::string dictionaryName;
    dictionaryName = "default";
    uint8_t wordsLength = 0;
    std::string fileName;
    if (argc != 3) {
        std::cout << "Number of arguments is not correct; must be 2, but "
                  << argc - 1
                  << " given.\nUsage: Word_Ladder [first word] [second word]\n(lengths of the words must be equal)"
                  << std::endl;
        return 1;
    }

    startWord = static_cast<std::string>(argv[1]);
    endWord = static_cast<std::string>(argv[2]);
    wordsLength = static_cast<uint8_t >(startWord.length());



    try {
        WordGraph graph(wordsLength, dictionaryName);
        path = graph.createPath(startWord, endWord);
        if (path.empty()){
            std::cout << "Path was not found" << std::endl;
        }
        for (auto& it: path){
            std::cout << it << std::endl;
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
