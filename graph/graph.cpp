#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <map>

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

void Graph::dfs(int start) const
{
    std::set<int> visited;
    std::stack<int> q;

    q.push(start);
    //visited.insert(start);

    //auto sourceNode = (nodes_.find(start))->second;
    while (!q.empty()) {
        start = q.top();
        q.pop();

        auto it2 = visited.find(start);
        if(it2 == visited.end()){ // not visited
            std::cout << start << " " ;
            visited.insert(start);
        }

        // loop through neigbours
        auto nodePtr = (nodes_.find(start))->second;
        const auto adajList = nodePtr->getAdjacents();

        for (auto it = adajList.begin(); it!= adajList.end(); ++it) {
            // check wether node visited
            int value = it->getValue();
            auto it3 = visited.find(value);
           if(it3 == visited.end()){ // not visited
               q.push(value);
           }
        }
    }
    std::cout << std::endl;
}

// helper function
std::vector<int> zeroIndegree(const std::map<int, int> indegree)
{
    std::vector<int> v;
    for (const auto& i : indegree) {
        if(i.second == 0)
            v.push_back(i.first);
    }
    return v;

}

void Graph::topsort() const
{
    std::queue<int> q;
    std::vector<int> top;
    int counter = 0;

    std::map<int, int> indegree;

    // initialize indegree map
    for (const auto& v : nodes_) 
        indegree[v.first] = 0;
    

    // Calculate indegree
    for (const auto& v : nodes_) {
       auto nodePtr = v.second;
       auto adajList = nodePtr->getAdjacents(); 
       for (const auto w: adajList) {
            indegree[w.getValue()] += 1;
       } 
    }

    // push all zero indegree nodes into queue.
    for (const auto& i : zeroIndegree(indegree)) {
       q.push(i) ;
    }

    while(!q.empty()){

        // remove from the queue
        auto v = q.front();
        top.push_back(v);
        q.pop();
        counter++;

        // decrease the indegree for each vertex w adajacent to v
        /*
        for (auto& i : indegree) {
           indegree[i.first] = i.second - 1; 
        }
        */
        
        // push all the vertices with zero indegree to queue
        // neighbours of v
        auto neigbours = nodes_.find(v)->second->getAdjacents(); 
            for (const auto w: neigbours) {
                indegree[w.getValue()] -= 1;
                if(indegree[w.getValue()]==0)
                    q.push(w.getValue());
            } 
    }
    
    int size = nodes_.size();

    if (counter != size) {
        // throw exception "CycleFoundEception;
        std::cout << "CycleFound...!" << std::endl;
        return;
    }

    for (const auto& i : top) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
