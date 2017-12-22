#ifndef WORDGRAPH
#define WORDGRAPH

#include <string>
#include <fstream>
#include <cstdint>
#include <memory>
#include "WordNode.h"
using WordNodePtr = std::unique_ptr<WordNode>;

class WordGraph {
private:
	uint8_t length;
	WordNode& startPoint;
	WordNode& endPoint;
	std::list<WordNodePtr> allWords;
	

public:
	WordGraph(void) = default;
	~WordGraph(void);
	void Build(std::string _startPointWord, std::string _endPointWord);
}; 

#endif