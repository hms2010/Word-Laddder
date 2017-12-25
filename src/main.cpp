#include <string>
#include <iostream>
#include <fstream>
#include "WordGraph.h"

int main(int argc, char** argv) {
    std::string startWord, endWord;
    std::string dictionaryName = "../default.dict";
    uint8_t wordsLength = 0;

    if(argc != 3) {
        std::cout << "Number of arguments is not correct; must be 2, but "
		<< argc - 1 
		<< " given.\n Usage:woldladder [first word] [second word]\n(lengths of the words is equal)"
		<< std::endl;
        return 1;
    }

    startWord = static_cast<std::string>(argv[1]);
    endWord = static_cast<std::string>(argv[2]);
    wordsLength = static_cast<uint8_t >(startWord.length());
    if (wordsLength != endWord.length()) {
        std::cout << "Lengths of the words must be equal."
                  << std::endl;
        return 2;
    }

    std::ifstream dictionary(dictionaryName);
    WordGraph graph(wordsLength, dictionary);
    dictionary.close();
    graph.print();
	return 0;
}
