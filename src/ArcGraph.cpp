//
// Created by alexis on 12/30/20.
//

#include "ArcGraph.h"
#include <cassert>

ArcGraph::ArcGraph(int size) {
    assert(size > 0);
    cntVertices = size;
}

ArcGraph::ArcGraph(const IGraph &obj): cntVertices(obj.size()) {
    for (int i = 0; i < obj.size(); ++i) {
        for (int el : obj.getNextVertices(i)) {
            graph.emplace_back(i, el);
        }
    }
}

void ArcGraph::add(int from, int to) {
    assert(from >= 0 && from < size());
    assert(to >= 0 && to < size());
    graph.emplace_back(from, to);
}

int ArcGraph::size() const {
    return cntVertices;
}

std::vector<int> ArcGraph::getNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < size());
    std::vector<int> res;
    for (auto &edge : graph) {
        if (edge.first == vertex) {
            res.push_back(edge.second);
        }
    }
    return res;
}

std::vector<int> ArcGraph::getPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < size());
    std::vector<int> res;
    for (auto &edge : graph) {
        if (edge.second == vertex) {
            res.push_back(edge.first);
        }
    }
    return res;
}
