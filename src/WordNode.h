#ifndef WORDNODE
#define WORDNODE

#include <string>
#include <list>
#include <memory>
#include <cstdint>

class WordNode {
private:
	uint8_t length;
	std::string word;
	std::list<WordNode> neighbors;
public:
	WordNode(void) = default;
	WordNode(std::string _word);
	~WordNode(void);
	bool operator ==(WordNode& right) const;
};

#endif