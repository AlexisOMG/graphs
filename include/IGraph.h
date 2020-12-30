//
// Created by alexis on 12/30/20.
//

#ifndef GRAPH_IGRAPH_H
#define GRAPH_IGRAPH_H

#include <vector>

class IGraph {
public:
    virtual ~IGraph() = default;

    virtual void add(int from, int to) = 0;

    virtual int size() const  = 0;

    virtual std::vector<int> getNextVertices(int vertex) const = 0;
    virtual std::vector<int> getPrevVertices(int vertex) const = 0;
};

#endif //GRAPH_IGRAPH_H
