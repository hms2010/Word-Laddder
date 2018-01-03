#ifndef WORDGRAPH
#define WORDGRAPH

#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <memory>
#include <utility>
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
	WordGraph(uint8_t _length, std::string dictionary, std::string start, std::string end);
	~WordGraph(void) = default;
    bool isCorrect(void) const;
	std::list<std::string> BFS(void);
    void printPath(std::ostream out, std::pair<WordNode&, WordNode*> wordChain);
	void print(void) const;
    friend void loadDictionary(WordGraph& destination,
                               std::string dictionary, uint8_t length);

}; 

#endif