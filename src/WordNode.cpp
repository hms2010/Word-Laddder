
#include "WordNode.h"

WordNode::WordNode(std::string _word): word(_word) {
	length = static_cast<uint8_t >(_word.length());
}

std::string WordNode::getWord(void) const {
	return word;
}

uint8_t WordNode::getDistance(WordNode& wordNode) const {
	uint8_t distance = 0;
	if (length != wordNode.length) {
        std::length_error ex("\"" + wordNode.word + "\" length doesn't match with \""+ word + "\" length.");
		throw ex;
	}
	for (uint8_t i = 0; i < length; i++) {
		if (static_cast<uint8_t>(word[i]) != static_cast<uint8_t>(wordNode.word[i])) {
			distance++;
		}
	}
    return distance;
}

void WordNode::addNeighbors(std::list<WordNode>& wordNodes) {
    for (auto& it: wordNodes) {
        if (getDistance(it) == 1) {
            neighbors.push_back(&it);
        }
    }
}

std::ostream& operator << (std::ostream &stream, const WordNode &wordNode) {
    stream << wordNode.getWord() << "{ ";
    if (!wordNode.neighbors.empty()) {
        for (auto& it: wordNode.neighbors) {
            stream << it->getWord() << " ";
        }
    }
    stream << "}" << std::endl;
    return stream;
}


