#include "WordNode.h"

WordNode::WordNode(std::string _word): word(_word){
	length = _word.length();
}

std::string WordNode::getWord(void) const {
	return word;
}

uint8_t WordNode::getDistance(WordNode& wordnode) {
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

WordNode::~WordNode(void) { }