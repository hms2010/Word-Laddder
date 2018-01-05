#ifndef WORD_GRAPH
#define WORD_GRAPH

#include <unordered_map>
#include <queue>
#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <utility>
#include "WordNode.h"
// 1st arg - current edge, 2nd - it's parent
using WordChain = std::unordered_map<WordNode *, WordNode *>;

class WordGraph {
private:
    uint8_t length;
    WordNode *startPoint;
    WordNode *endPoint;
    std::list<std::string> path;
    std::list<WordNode> allWords;

public:
    WordGraph() = delete;

    WordGraph(uint8_t _length, std::string dictionary, std::string start, std::string end);

    ~WordGraph() = default;

    bool isCorrect() const;

    std::list<std::string> BFS();

    std::list<std::string> createPath(WordChain wordChain);

    void printPath(std::ostream &stream) const;

    void print(std::ostream &stream) const;

    std::list<std::string> getPath() const;

    friend void loadDictionary(WordGraph &destination,
                               std::string dictionary, uint8_t length);

};

#endif