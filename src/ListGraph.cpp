//
// Created by alexis on 12/30/20.
//
#include "ListGraph.h"
#include <cassert>

ListGraph::ListGraph(int size) {
    assert(size >= 0);
    graph = std::vector<std::vector<int>>(size);
}

ListGraph::ListGraph(const IGraph &obj):graph(obj.size()) {
    for (int i = 0; i < obj.size(); ++i) {
        graph[i] = obj.getNextVertices(i);
    }
}

void ListGraph::add(int from, int to) {
    assert(from >= 0 && from < size());
    assert(to >= 0 && to < size());
    graph[from].push_back(to);
}

int ListGraph::size() const {
    return graph.size();
}

std::vector<int> ListGraph::getNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < size());
    return graph[vertex];
}

std::vector<int> ListGraph::getPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < size());
    std::vector<int> res;
    for (int i = 0; i < size(); ++i) {
        for (int el : graph[i]) {
            if (el == vertex) {
                res.push_back(i);
            }
        }
    }
    return res;
}
