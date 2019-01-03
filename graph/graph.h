#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>

#include "vertex.hpp"

class Graph
{
private:
    std::map<int, Node*> nodes_;
    std::string edgeDirection_;
    

public:
    Graph(std::string edgeDirection = "DIRECTED");
    ~Graph();


    void addVertex(int value);
    void addEdge(const int src, const int dest, int cost=1);


    void removeVertex(int value);
    void removeEdge(int src, int dest);

    void print() const;

    void bfs(int value) const;

    void dfs(int value) const;

    void topsort() const;

    void unweighted(const int s);

};

#endif /* GRAPH_H */
