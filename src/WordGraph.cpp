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
    if (!isCorrect()) {
        throw std::invalid_argument("One of words (or both) isn't found in dictionary. Check your input or change the dictionary");
    }
}

void WordGraph::print(std::ostream& stream) const {
    for (auto& it: allWords) {
        stream << it;
    }
}

std::list<std::string> WordGraph::BFS() {
    std::queue<WordNode*> wordsQueue;
    std::unordered_map<WordNode*, bool> visited;
    std::list<std::string> path;
    for (auto& it: allWords) {
        visited.emplace(&it, false);
    }

    WordChain chain;
    chain.emplace(startPoint, nullptr);

    wordsQueue.push(startPoint);
    while (!wordsQueue.empty()) {
        auto current = wordsQueue.front();
        wordsQueue.pop();

        if (current == endPoint){
            path = createPath(chain);
            break;
        }

        for (auto& it: current->neighbors) {
            if (!visited[it]) {
                wordsQueue.push(it);
                chain.emplace(it, current);
            }
        }

        visited[current] = true;
    }
    return path;
}

bool WordGraph::isCorrect() const {
    return startPoint == nullptr ? false : endPoint != nullptr;
}

void loadDictionary(WordGraph& destination,
std::string dictionary, uint8_t length) {
    std::string dictPath = dictionary + "/" + std::to_string(length);
    std::cout << "Selected dictionary: " << dictPath << std::endl;

    const uint16_t size = 256;
    char buffer[size];

    try{
        std::ifstream source(dictPath);
        while (!source.eof()){
            source.getline(buffer, length + 1);
            buffer[length + 1] = '\0';
            destination.allWords.emplace_back(buffer);
        }
        source.close();
    }
    catch (std::ifstream::failure& ex){
        std::cout << "Dictionary file processing error." << std::endl;
    }
}

std::list<std::string> WordGraph::createPath(WordChain wordChain) {


    path.emplace_front(endPoint->getWord());
    WordNode* key = wordChain[endPoint];
    while (key != nullptr) {
        path.emplace_front(key->getWord());
        key = wordChain[key];
    }

    return path;
}

void WordGraph::printPath(std::ostream& stream) const {
    stream << "Word Ladder for \"" << startPoint->getWord()
           << "\" and \"" << endPoint->getWord() << "\":" << std::endl;
    uint32_t counter = -1;
    for (auto& it: path) {
        stream << it << std::endl;
        counter++;
    }
    stream << "Total: " << counter << " changes used." << std::endl;
}

std::list<std::string> WordGraph::getPath() const {
    return path;
}
