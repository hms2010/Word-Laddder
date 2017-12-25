#include <iostream>
#include <string>
#include "WordGraph.h"

int main(int argc, char** argv) {
	std::string startWord, endWord;
	if(argc != 3){
		std::cout << "Number of arguments is not correct; must be 2, but " 
		<< argc - 1 
		<< " given.\n Usage:woldladder [first word] [second word]\n(lenghts of the words is equal)" 
		<< std::endl;
		return 0;
	}


	return 0;
}
