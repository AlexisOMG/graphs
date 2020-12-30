//
// Created by alexis on 12/30/20.
//

#include <iostream>
#include <functional>
#include <queue>
#include "IGraph.h"
#include "ListGraph.h"
#include "SetGraph.h"
#include "MatrixGraph.h"
#include "ArcGraph.h"

void BFS(IGraph &graph, int vertex, std::function<void(int)> visit) {
    std::vector<bool> used(graph.size(), false);
    std::queue<int> q;
    q.push(vertex);
    used[vertex] = true;
    while (!q.empty()) {
        int from = q.front();
        q.pop();
        visit(from);
        for (int el : graph.getNextVertices(from)) {
            if (!used[el]) {
                q.push(el);
                used[el] = true;
            }
        }
    }
}

void printPrevVertices(const IGraph &graph) {
    for (int i = 0; i < graph.size(); ++i) {
        for (int el : graph.getPrevVertices(i)) {
            std::cout << el << " ";
        }
        std::cout << "\n";
    }
}

int test() {
    ListGraph listGraph(5);
    listGraph.add(0, 1);
    listGraph.add(0, 3);
    listGraph.add(0, 4);
    listGraph.add(1, 4);
    listGraph.add(4, 2);

    MatrixGraph matrixGraph(listGraph);
    SetGraph setGraph(listGraph);
    ArcGraph arcGraph(listGraph);

    std::cout << "Compare sizes: ";
    if (listGraph.size() == matrixGraph.size() && listGraph.size() == setGraph.size() && listGraph.size() == arcGraph.size()) {
        std::cout << "Equal\n";
    } else {
        std::cout << "Failed\n";
        return 1;
    }

    std::cout << "\nCompare prevVertices: ";
    for (int i = 0; i < listGraph.size(); ++i) {
        if (listGraph.getPrevVertices(i) != matrixGraph.getPrevVertices(i) ||
                listGraph.getPrevVertices(i) != setGraph.getPrevVertices(i) ||
                listGraph.getPrevVertices(i) != arcGraph.getPrevVertices(i)) {
            std::cout << "Failed\n";
            return 1;
        }
    }
    std::cout << "Equal\n";

    std::cout << "\nCompare nextVertices: ";
    for (int i = 0; i < listGraph.size(); ++i) {
        if (listGraph.getNextVertices(i) != matrixGraph.getNextVertices(i) ||
            listGraph.getNextVertices(i) != setGraph.getNextVertices(i) ||
            listGraph.getNextVertices(i) != arcGraph.getNextVertices(i)) {
            std::cout << "Failed\n";
            return 1;
        }
    }
    std::cout << "Equal\n";

    std::cout << "\nBFS for listGraph: ";
    BFS(listGraph, 0, std::function<void(int)>([](int v){std::cout << v << ", ";}));

    std::cout << "\nBFS for matrixGraph: ";
    BFS(matrixGraph, 0, std::function<void(int)>([](int v){std::cout << v << ", ";}));

    std::cout << "\nBFS for setGraph: ";
    BFS(setGraph, 0, std::function<void(int)>([](int v){std::cout << v << ", ";}));

    std::cout << "\nBFS for arcGraph: ";
    BFS(arcGraph, 0, std::function<void(int)>([](int v){std::cout << v << ", ";}));

    std::cout << "\n";
    return 0;
}

int main() {
    test();
    return 0;
}

