#include "WordNode.h"

WordNode::WordNode(std::string _word): word(_word){
	length = _word.length()
}

std::string WordNode::getWord(void) {
	return word;
}
WordNode::~WordNode(void);