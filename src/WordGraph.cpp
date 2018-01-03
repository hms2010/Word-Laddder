#include "WordGraph.h"



WordGraph::WordGraph(uint8_t _length, std::string dictionary, std::string start, std::string end): length(_length) {
	// loads dict here;
    loadDictionary(*this, std::move(dictionary), _length);
    // adds strings to WordNodes and add it to allWords
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

void WordGraph::print(void) const {
	for (auto& it: allWords) {
		std::cout << it;
	}
}

std::list<std::string> WordGraph::BFS(void) {
	std::queue<WordNode&> wordsQueue;
    std::set<std::pair<WordNode&, bool>> visited;
    std::pair<WordNode&, >

    for (auto& it: allWords) {
        visited.emplace(&it, false);
    }

    wordsQueue.push(*startPoint);

    while (!wordsQueue.empty()) {
        auto current = wordsQueue.front();
        wordsQueue.pop();
        if (&current == endPoint){
            printPath(stdout);
        }

    }
    return std::list<std::string>();
}

bool WordGraph::isCorrect(void) const {
    return startPoint == nullptr ? false : endPoint != nullptr;
}

void loadDictionary(WordGraph& destination,
                    std::string dictionary, uint8_t length) {
    std::ifstream source(dictionary + "/" + std::to_string(length));
    const uint16_t size = 256;
    char buffer[size];
    while (!source.eof()){
        source.getline(buffer, size);
        destination.allWords.emplace_back(buffer);
    }

}

void WordGraph::printPath(std::ostream out) {
    
}
