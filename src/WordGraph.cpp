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
    std::queue<WordNode*> wordsQueue;
    std::unordered_map<WordNode*, bool> visited;
    std::list<std::string> path;
    for (auto& it: allWords) {
        visited.emplace(&it, false);
    }

    wordsQueue.push(startPoint);
    WordNode* parent = nullptr;
    WordChain chain;

    while (!wordsQueue.empty()) {
        auto current = wordsQueue.front();

        wordsQueue.pop();
        chain.emplace(current, parent);
        if (current == endPoint){
            path = createPath(chain);
            break;
        }

        for (auto& it: current->neighbors) {
            if (!visited[it]) {
                wordsQueue.push(it);
            }
        }
        parent = current;
    }
    return path;
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

std::list<std::string> WordGraph::createPath(WordChain wordChain) {
    std::list<std::string> path;

    path.emplace_front(endPoint->getWord());
    WordNode* key = wordChain[endPoint];
    while (key != nullptr) {
        path.emplace_front(key->getWord());
        key = wordChain[key];
    }
    path.emplace_front(startPoint->getWord());
    return std::move(path);
}
