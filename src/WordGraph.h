#ifndef WORDGRAPH
#define WORDGRAPH

#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <memory>
#include <queue>
#include <map>
#include <set>
#include "WordNode.h"

class WordGraph {
private:
	uint8_t length;
	WordNode* startPoint;
	WordNode* endPoint;
	std::list<WordNode> allWords;

public:
	WordGraph(void) = delete;
	WordGraph(uint8_t _length, std::ifstream& dictionary, std::string start, std::string end);
	~WordGraph(void) = default;
    bool isCorrect(void) const;
	std::list<std::string> BFS(void);
	void print(void) const;
}; 

#endif