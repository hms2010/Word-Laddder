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


class WordGraph {
private:
    uint8_t length;
    std::list<WordNode> allWords;

public:
    WordGraph() = delete;

    WordGraph(uint8_t _length, std::string dictionary);

    ~WordGraph() = default;

    std::unordered_map<WordNode *, WordNode *> BFS(WordNode *startPoint, WordNode *endPoint);

    WordNode *findWord(std::string& word);

    std::list<std::string> createPath(WordNode *startPoint, WordNode *endPoint);

    std::list<std::string> createPath(std::string startWord, std::string endWord);

    void print(std::ostream &stream) const;

    friend void loadDictionary(WordGraph &destination,
                               std::string dictionary, uint8_t length);

};

#endif