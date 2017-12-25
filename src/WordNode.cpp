#include "WordNode.h"

WordNode::WordNode(std::string _word): word(_word) {
	length = static_cast<uint8_t >(_word.length());
}

std::string WordNode::getWord(void) const {
	return word;
}

uint8_t WordNode::getDistance(WordNode& wordnode) const {
	uint8_t distance = 0;
	if (length != wordnode.length) {
		return SIZE_ERROR;
	}
	for (int i = 0; i < length; i++) {
		if (!(static_cast<uint8_t>(word[i]) ^ static_cast<uint8_t>(wordnode.word[i]))) {
			distance++;
		}
	}
	return distance;
}

void WordNode::addNeigbors(const std::list<WordNode> &wordNodes) {
    for (auto it: wordNodes) {
        if (getDistance(*it) == 1) {
            neighbors.push_back(it);
        }
    }
}
