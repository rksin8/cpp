#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <list>
#include <utility>

using namespace std;

struct vertex {
    using ve = pair<double, vertex*>;
    std::vector<ve> adj;  // cost of edge, destination vertex
    string name;
    vertex(string s) : name{s}{}
};


class Graph
{
public:
    using vmap = std::map<string, vertex*>;
    vmap work;
    ~Graph();
    void addVertex(const string&);
    void addEdge(const string& from,  const string& to, double cost);
};

Graph::~Graph()
{
    // iterate through all the key of map and delete the vertex
    for (auto it = work.begin(); it != work.end(); ++it) {
       auto vertexPtr = it->second;
      if(vertexPtr){
        delete vertexPtr;
      } 
    }

}
void Graph::addVertex(const string& name)
{
    // check name already exist in map
    auto it = work.find(name);
    // if not then add to map
    if(it==work.end()){
        vertex* v = new vertex(name);
        work[name] = v;
        return;
    }
    // else do nothing
}

void Graph::addEdge(const string& from,  const string& to, double cost)
{
    vertex* f = (work.find(from)->second);
    vertex* t = (work.find(to)->second);

    pair<double,vertex*> edge = make_pair(cost, t);

    f->adj.push_back(edge);
}




int main(int argc, char *argv[])
{
    std::vector<double> v;
    std::list<double> l;

    std::cout << sizeof(v) << " " << sizeof(l) << std::endl;

    Graph g;
    g.addVertex("patna");
    g.addVertex("delhi");
    g.addVertex("bombay");
    g.addVertex("kolkata");

    g.addEdge("patna", "delhi", 1);
    g.addEdge("delhi", "bombay", 2);
    g.addEdge("bombay", "kolkata", 2);
    g.addEdge("kolkata", "patna", 1);


    auto t = g.work.find("patna")->second;

    std::cout << "adjacent to patna: " << std::get<1>(t->adj[0])->name << std::endl;
    std::cout << "cost: " << std::get<0>(t->adj[0]) << std::endl;

    for (const auto& i : g.work) {
        std::cout << i.first << " --> ";
        std::cout << std::get<1>(i.second->adj[0])->name << " ";
        std::cout << std::get<0>(i.second->adj[0]) << std::endl;
        
    }





    return 0;
}










