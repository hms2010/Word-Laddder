#ifndef WORDNODE
#define WORDNODE

#define SIZE_ERROR 255

#include <string>
#include <list>
#include <memory>
#include <cstdint>

class WordNode {
private:
	uint8_t length;
	std::string word;
	std::list<WordNode*> neighbors;

public:
	WordNode(void) = delete;
	explicit WordNode(std::string _word);
	~WordNode(void) = default;

	std::string getWord(void) const;
    uint8_t getDistance(WordNode& wordNode) const;
    void addNeigbors(const std::list<WordNode>& wordNodes);
};

#endif