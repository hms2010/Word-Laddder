#ifndef WORD_NODE
#define WORD_NODE

#include <string>
#include <list>
#include <memory>
#include <cstdint>
#include <iostream>
#include <exception>

class WordNode {
private:
    uint8_t length;
    std::string word;
    std::list<WordNode *> neighbors;

public:
    friend class WordGraph;

    WordNode() = delete;

    explicit WordNode(std::string _word);

    ~WordNode() = default;

    std::string getWord() const;

    uint8_t getDistance(WordNode &wordNode) const;

    void addNeighbors(std::list<WordNode> &wordNodes);

    friend std::ostream &operator<<(std::ostream &stream, const WordNode &wordNode);
};

#endif