#ifndef WORDGRAPH
#define WORDGRAPH

#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <memory>

#include "WordNode.h"

class WordGraph {
private:
	uint8_t length;
	WordNode* startPoint;
	WordNode* endPoint;
	std::list<WordNode> allWords;

public:
	WordGraph(void) = delete;
	WordGraph(uint8_t _length, std::ifstream& dictionary);
	~WordGraph(void) = default;

	void print() const;
}; 

#endif