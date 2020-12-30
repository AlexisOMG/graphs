//
// Created by alexis on 12/30/20.
//

#ifndef GRAPH_ARCGRAPH_H
#define GRAPH_ARCGRAPH_H

#include "IGraph.h"
#include <utility>

class ArcGraph: public IGraph {
private:
    std::vector<std::pair<int, int>> graph;
    int cntVertices = 0;
public:
    ArcGraph() = default;
    explicit ArcGraph(int size);
    explicit ArcGraph(const IGraph &obj);
    ArcGraph& operator=(const IGraph &obj) = delete;
    ~ArcGraph() = default;

    void add(int from, int to) override;
    int size() const override;

    std::vector<int> getNextVertices(int vertex) const override;
    std::vector<int> getPrevVertices(int vertex) const override;
};
#endif //GRAPH_ARCGRAPH_H
