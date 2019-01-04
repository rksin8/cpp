#include <iostream>
#include <vector>
#include <algorithm>


void representation()
{

    std::vector<int> adj[10];
    int x, y, nodes, edges;
    std::cin >> nodes;
    std::cin >> edges;


    // why 0 to edge-1
    for (int i = 0; i < edges; ++i) {
        std::cin >> x >> y;
        adj[x].push_back(y);  // Insert y adjacency list of x
    }

    // why 1 to nodes
    for (int i = 1; i <= nodes; ++i) {
        std::cout << "Adjacency list of node " << i << ": ";

        // printing is similar to 2D matrix
        for (size_t j = 0; j < adj[i].size(); ++j) {
            if(j == adj[i].size()-1)
                std::cout << adj[i][j] << std::endl;
            else
                std::cout << adj[i][j] << " -->";
        }
    }

}



void checkEgde(){
    std::vector<int> adj[10];

    int x, y, nodes, edges;
    std::cin >> nodes;
    std::cin >> edges;

    // why 0 to edge-1
    for (int i = 0; i < edges; ++i) {
        std::cin >> x >> y;
        adj[x].push_back(y);  // Insert y adjacency list of x
    }
    
    int Q; 
    std::cout << "Enter the no. of queries(Q): ";
    std::cin >> Q;
    for (int k = 0; k < Q; ++k) {
        // now check for edge
        std::cout << "Enter 1st and 2nd node wth space: ";
        std::cin >> x >> y;

        bool edge = false;

        for (size_t j = 0; j < adj[x].size(); ++j) {
            // if i (=node)  in adj[i].vector(); 
            auto itr = std::find(adj[x].begin(), adj[x].end(), y);
            if(itr != adj[x].end()){
                edge = true;
                break;
            }
        }
        if(edge)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;

    }
}


int main(int argc, char *argv[])
{
    //representation();
    
    checkEgde();

    return 0;
}
