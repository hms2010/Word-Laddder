#include "WordGraph.h"

WordGraph::WordGraph(uint8_t _length, std::string dictionary) : length(_length) {
    // loads dict here;
    loadDictionary(*this, std::move(dictionary), _length);
    // adds strings to WordNodes and add it to allWords
    for (auto &it: allWords) {
        it.addNeighbors(allWords);
    }
}

void WordGraph::print(std::ostream &stream) const {
    for (auto &it: allWords) {
        stream << it;
    }
}

// 1st arg - current edge, 2nd - it's parent
std::unordered_map<WordNode *, WordNode *> WordGraph::BFS(WordNode *startPoint, WordNode *endPoint) {
    std::queue<WordNode *> wordsQueue;
    std::unordered_map<WordNode *, bool> visited;
    std::list<std::string> path;
    for (auto &it: allWords) {
        visited.emplace(&it, false);
    }

    std::unordered_map<WordNode *, WordNode *> chain;
    chain.emplace(startPoint, nullptr);

    wordsQueue.push(startPoint);
    while (!wordsQueue.empty()) {
        auto current = wordsQueue.front();
        wordsQueue.pop();

        if (current == endPoint) {
            return chain;
        }

        for (auto &it: current->neighbors) {
            if (!visited[it]) {
                wordsQueue.push(it);
                chain.emplace(it, current);
            }
        }

        visited[current] = true;
    }
    return std::unordered_map<WordNode *, WordNode *>();

}

void loadDictionary(WordGraph &destination,
                    std::string dictionary, uint8_t length) {
    std::string dictPath = dictionary + "/" + std::to_string(length);

    const uint16_t size = 256;
    char buffer[size];

    try {
        std::ifstream source(dictPath);
        if (!source.is_open()) {
            throw std::ifstream::failure("Dictionary wasn't open");
        };
        source.getline(buffer, length + 1);
        while (!source.eof()) {
            buffer[length + 1] = '\0';
            destination.allWords.emplace_back(buffer);
            source.getline(buffer, length + 1);
        }
        source.close();
    }
    catch (std::ifstream::failure &ex) {
        throw ex;
    }
    catch (std::exception &ex) {
        throw ex;
    }

}

std::list<std::string> WordGraph::createPath(WordNode *startPoint, WordNode *endPoint) {
    std::list<std::string> path;
    if (startPoint->length != length) {
        throw std::length_error("Invalid argument length \"" + startPoint->getWord() + "\"");
    }
    if (endPoint->length != length) {
        throw std::length_error("Invalid argument length \"" + endPoint->getWord() + "\"");
    }
    if (startPoint->length != endPoint->length) {
        throw std::length_error("Lengths of the words must be equal");
    }

    if (startPoint == endPoint) {
        path.emplace_front(startPoint->getWord());
        path.emplace_front(startPoint->getWord());
        return path;
    }
    // 1st arg - current edge, 2nd - it's parent
    std::unordered_map<WordNode *, WordNode *> chain = BFS(startPoint, endPoint);
    path.emplace_front(endPoint->getWord());
    WordNode *key = chain[endPoint];
    while (key != nullptr) {
        path.emplace_front(key->getWord());
        key = chain[key];
    }
    return std::move(path);
}

WordNode *WordGraph::findWord(std::string &word) {
    for (auto &it: allWords) {
        if (it.getWord() == word) {
            return &it;
        }
    }
    if (word.length() != length) {
        throw std::length_error("Invalid argument length \"" + word + "\"");
    }
    throw std::invalid_argument("\"" + word + "\" was not found in dictionary");

}

std::list<std::string> WordGraph::createPath(std::string startWord, std::string endWord) {
    WordNode *startPoint;
    WordNode *endPoint;
    startPoint = findWord(startWord);
    endPoint = findWord(endWord);
    return std::move(createPath(startPoint, endPoint));
}
