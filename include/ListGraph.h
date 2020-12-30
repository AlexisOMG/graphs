//
// Created by alexis on 12/30/20.
//

#ifndef GRAPH_LISTGRAPH_H
#define GRAPH_LISTGRAPH_H

#include "IGraph.h"

class ListGraph: public IGraph {
private:
    std::vector<std::vector<int>> graph;
public:
    ListGraph() = default;
    explicit ListGraph(int size);
    explicit ListGraph(const IGraph &obj);
    ListGraph& operator=(const  IGraph &obj) = delete;
    ~ListGraph() = default;

    void add(int from, int to) override;
    int size() const override;

    std::vector<int> getNextVertices(int vertex) const override;
    std::vector<int> getPrevVertices(int vertex) const override;
};

#endif //GRAPH_LISTGRAPH_H
