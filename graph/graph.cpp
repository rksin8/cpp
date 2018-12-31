#include <iostream>
#include <queue>
#include <stack>
#include <set>


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


void Graph::bfs(int start) const
{
    std::set<int> visited;
    std::queue<int> q;

    q.push(start);
    visited.insert(start);

    //auto sourceNode = (nodes_.find(start))->second;
    while (!q.empty()) {
        int start = q.front();
        std::cout << start << " " ;
        q.pop();

        // loop through neigbours
        auto nodePtr = (nodes_.find(start))->second;

        const auto adajList = nodePtr->getAdjacents();

        for (auto it = adajList.begin(); it!= adajList.end(); ++it) {
            // check wether node visited
            int value = it->getValue();
            auto it2 = visited.find(value);
           if(it2 == visited.end()){ // not visited
               q.push(value);
               visited.insert(value);
           }
        }
    }
    std::cout << std::endl;
}

void Graph::dfs(int value) const
{
    /*
    std::map<int, Node*> visited;

    std::stack<Node> visitList;

    auto sourceNode = (nodes_.find(value))->second;


    visitList.push(*sourceNode);

    while (!visitList.empty()) {
        const auto node = visitList.top();
        visitList.pop();

        auto it = std::find(visitList.begin(), visitList.end(), *node );

        if(node && !visitList.has(node))
            std::cout << node << std::endl;
        visited[node] = node;

        for (const auto& i : node->getAdjacents()) {
            visitList.push(i);
        }
    }
*/
}
