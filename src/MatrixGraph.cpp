//
// Created by alexis on 12/30/20.
//
#include "MatrixGraph.h"
#include <cassert>

MatrixGraph::MatrixGraph(int size) {
    assert(size > 0);
    graph = std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
}

MatrixGraph::MatrixGraph(const IGraph &obj): graph(obj.size(), std::vector<int>(obj.size(), 0)) {
    for (int i = 0; i < obj.size(); ++i) {
        for (int el : obj.getNextVertices(i)) {
            graph[i][el] = 1;
        }
    }
}

void MatrixGraph::add(int from, int to) {
    assert(from >= 0 && from < size());
    assert(to >= 0 && to < size());
    graph[from][to] = 1;
}

int MatrixGraph::size() const {
    return graph.size();
}

std::vector<int> MatrixGraph::getNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < size());
    std::vector<int> res;
    for (int i = 0; i < size(); ++i) {
        if (graph[vertex][i]) {
            res.push_back(i);
        }
    }
    return res;
}

std::vector<int> MatrixGraph::getPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < size());
    std::vector<int> res;
    for (int i = 0; i < size(); ++i) {
        if (graph[i][vertex]) {
            res.push_back(i);
        }
    }
    return res;
}
