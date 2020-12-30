//
// Created by alexis on 12/30/20.
//

#ifndef GRAPH_SETGRAPH_H
#define GRAPH_SETGRAPH_H

#include "IGraph.h"
#include <set>

class SetGraph: public IGraph {
private:
    std::vector<std::set<int>> graph;
public:
    SetGraph() = default;
    explicit SetGraph(int size);
    explicit SetGraph(const IGraph &obj);
    SetGraph& operator=(const IGraph &obj) = delete;
    ~SetGraph() = default;

    void add(int from, int to) override;
    int size() const override;

    std::vector<int> getNextVertices(int vertex) const override;
    std::vector<int> getPrevVertices(int vertex) const override;
};

#endif //GRAPH_SETGRAPH_H
