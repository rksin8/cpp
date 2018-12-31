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


    return 0;
}