#include <iostream>
#include "graph.h"

using namespace std;

Graph::Graph(std::string edgeDirection)
    : edgeDirection_{edgeDirection}{
    }

Graph::~Graph()
{
    for (const auto& key : nodes_) {
        auto currentPointer = key.second;

        if(currentPointer)
            delete currentPointer;
    }
}

void Graph::addVertex(int value){

    // cheack if nodes already exist into map key
    auto it = nodes_.find(value);
    
    // if not exist then create a node else do nothing
    if(it==nodes_.end()){
        const auto vertex = new Node(value);
        nodes_[value] = vertex;
        return;
    }
    std::cout << "Vertex "<< value << " already exits..." << std::endl;
}


void Graph::addEdge(const int src, const int dest, int cost)
{
    addVertex(src);
    addVertex(dest);

    auto sourceNode = (nodes_.find(src))->second;
    auto destNode = (nodes_.find(dest))->second;
    
     sourceNode->addAdajacent(*destNode);

    if(edgeDirection_ == "UNDIRECTED")
        destNode->addAdajacent(*sourceNode);

}


void Graph::removeVertex(int value)
{
    const auto current = nodes_.find(value)->second;
    if(current){
        for (const auto& v : nodes_) {
            const auto tmp = v.second;
            tmp->removeAdjacent(*current); 
        }
    }
}


void Graph::removeEdge(int src, int dest)
{
    auto sourceNode = (nodes_.find(src))->second;
    auto destNode = (nodes_.find(dest))->second;

    if( sourceNode && destNode){
        sourceNode->removeAdjacent(*destNode);

        if (edgeDirection_ == "UNDIRECTED"){
            destNode->removeAdjacent(*sourceNode);
        }
    }
}


void Graph::print() const
{
    for (const auto& key : nodes_) {
       // print vertex
       std::cout << key.first << " --> ";

       // print the adjacent verties
       const auto value = key.second;
      for (const auto& i : value->getAdjacents()) {
         std::cout << i.getValue() << " --> "; 
      } 

      std::cout  << std::endl;

    }

}
