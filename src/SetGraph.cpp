//
// Created by alexis on 12/30/20.
//
#include "SetGraph.h"
#include <cassert>

SetGraph::SetGraph(int size) {
    assert(size > 0);
    graph = std::vector<std::set<int>>(size);
}

SetGraph::SetGraph(const IGraph &obj): graph(obj.size()) {
    for (int i = 0; i < obj.size(); ++i) {
        for (int el : obj.getNextVertices(i)) {
            graph[i].insert(el);
        }
    }
}

void SetGraph::add(int from, int to) {
    assert(from >= 0 && from < size());
    assert(to >= 0 && to < size());
    graph[from].insert(to);
}

int SetGraph::size() const {
    return graph.size();
}

std::vector<int> SetGraph::getNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < size());
    std::vector<int> res;
    for (int el : graph[vertex]) {
        res.push_back(el);
    }
    return res;
}

std::vector<int> SetGraph::getPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < size());
    std::vector<int> res;
    for (int i = 0; i < size(); ++i) {
        if (graph[i].find(vertex) != graph[i].end()) {
            res.push_back(i);
        }
    }
    return res;
}

