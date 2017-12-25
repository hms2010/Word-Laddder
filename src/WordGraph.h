#ifndef WORDGRAPH
#define WORDGRAPH

#include <string>
#include <fstream>
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
	~WordGraph(void);
	WordGraph(uint8_t _length);
	void Build(std::string _startPointWord, std::string _endPointWord);
}; 

#endif