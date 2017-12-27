#include "WordGraph.h"

WordGraph::WordGraph(uint8_t _length, std::ifstream& dictionary, std::string start, std::string end): length(_length) {
	// load dict here;
	// add strings to WordNodes and add it to allWords

	for (auto& it: allWords) {
		it.addNeighbors(allWords);
        if (it.getWord() == start) {
            startPoint = &it;
        }
        if (it.getWord() == end) {
            endPoint = &it;
        }
	}
}

void WordGraph::print() const {
	for (auto& it: allWords) {
		std::cout << it;
	}
}

std::list<std::string> WordGraph::BFS(void) {
	std::queue<WordNode*> wordsQueue;
    std::map<WordNode*, bool> visited;

    for (auto& it: allWords) {
        visited.emplace(&it, false);
    }

    wordsQueue.push(startPoint);
    while (!wordsQueue.empty()) {

    }
    return std::list<std::string>();
}

