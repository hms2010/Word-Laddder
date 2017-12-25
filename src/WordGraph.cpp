#include "WordGraph.h"


WordGraph::~WordGraph(void) {

}
WordGraph::WordGraph(uint8_t _length, std::fstream dictionary): length(_length), startPoint(nullptr), endPoint(nullptr) {
    // load dict here;
    // add strings to WordNodes and add it to WordsList
    for (auto it: allWords) {
        it.addNeigbors(allWords);
    }
}

