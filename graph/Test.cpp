#include <iostream>

#include "vertex.hpp"

#include "graph.h"

int main(int argc, char *argv[])
{
    /*
    Node n{5};
    n.addAdajacent(6);
    n.addAdajacent(7);
    n.addAdajacent(11);

    for (auto i : n.getAdjacents()) {
       std::cout << i.getValue() << std::endl; 
    }

    */

    Graph g("DIRECTED");

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,1);
    g.addEdge(3,2);
    g.addEdge(4,5);
    g.addEdge(5,4);

    g.print();


    Graph graph("UNDIRECTED");

    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(5, 2);
    graph.addEdge(6, 3);
    graph.addEdge(7, 3);
    graph.addEdge(8, 4);
    graph.addEdge(9, 5);
    graph.addEdge(10, 6);

    graph.dfs(1);

    // Topological sort
    Graph gt("DIRECTED");
    gt.addEdge(5,2);
    gt.addEdge(5,0);
    gt.addEdge(4,0);
    gt.addEdge(4,1);
    gt.addEdge(2,3);
    gt.addEdge(3,1);

    std::cout << "topological sort..." << std::endl;
    gt.topsort();

    Graph gt2("DIRECTED");
    gt2.addEdge(1,2);
    gt2.addEdge(1,3);
    gt2.addEdge(1,4);
    gt2.addEdge(2,4);
    gt2.addEdge(2,5);
    gt2.addEdge(3,6);
    gt2.addEdge(4,3);
    gt2.addEdge(4,6);
    gt2.addEdge(4,7);
    gt2.addEdge(5,4);
    gt2.addEdge(5,7);
    gt2.addEdge(7,6);
    gt2.topsort();

    Graph gt3("DIRECTED");
    gt3.addEdge(1,2);
    gt3.addEdge(2,3);
    gt3.addEdge(4,2);
    gt3.addEdge(5,3);
    gt3.topsort();


    gt.unweighted(1);

    return 0;
}
