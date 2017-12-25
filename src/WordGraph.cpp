#include "WordGraph.h"

WordGraph::WordGraph(uint8_t _length, std::ifstream& dictionary): length(_length), startPoint(nullptr), endPoint(nullptr) {
	// load dict here;
	// add strings to WordNodes and add it to allWords

	for (auto& it: allWords) {
		it.addNeighbors(allWords);
	}
}

void WordGraph::print() const {
	for (auto it: allWords) {
		std::cout << it;
	}
}

std::list<std::string> WordGraph::BFS(void) {
	return std::list<std::string>();
}

