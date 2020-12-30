//
// Created by alexis on 12/30/20.
//

#ifndef GRAPH_MATRIXGRAPH_H
#define GRAPH_MATRIXGRAPH_H

#include "IGraph.h"

class MatrixGraph: public IGraph {
private:
    std::vector<std::vector<int>> graph;
public:
    MatrixGraph() = default;
    explicit MatrixGraph(int size);
    explicit MatrixGraph(const IGraph &obj);
    MatrixGraph& operator=(const IGraph &obj) = delete;
    ~MatrixGraph() = default;

    void add(int from, int to) override;
    int size() const override;

    std::vector<int> getNextVertices(int vertex) const override;
    std::vector<int> getPrevVertices(int vertex) const override;
};

#endif //GRAPH_MATRIXGRAPH_H
