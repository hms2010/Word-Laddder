#include <string>
#include <iostream>
#include <list>
#include "WordGraph.h"

int main(int argc, char** argv) {
	std::string startWord, endWord;
	std::string dictionaryName = "default";
	uint8_t wordsLength = 0;
	std::list<std::string> path;

	if(argc != 3) {
		std::cout << "Number of arguments is not correct; must be 2, but "
		<< argc - 1 
		<< " given.\nUsage: Word_Ladder [first word] [second word]\n(lengths of the words must be equal)"
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

	try {
		WordGraph graph(wordsLength,dictionaryName, startWord, endWord);
        graph.BFS();
        graph.printPath(std::cout);
	}
    catch (std::invalid_argument& ex) {
        std::cout << ex.what() << std::endl;
    }
	catch (std::length_error& ex) {
		std::cout << "Invalid argument length: " << ex.what() << std::endl;
	}
	catch (std::exception& ex) {
		std::cout << "Something went wrong. Sorry." << std::endl;
	}
	return 0;
}
