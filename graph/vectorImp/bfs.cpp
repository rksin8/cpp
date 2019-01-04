#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


std::vector<int> adj[10];

void bfs(int s)
{
    std::queue<int> q;
    std::vector<bool> visited(10, false);
    int level[10];

    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while(!q.empty()){
        auto v = q.front(); 
        std::cout << v << std::endl;
        q.pop();

        auto neighbours = adj[v];
        for (const auto& w : neighbours) {
            if(!visited[w]){
                q.push(w);
                visited[w] = true;
                level[w]  = level[v] + 1;
            }
        }
    }

    std::cout << "node    " << "     level [node]" << std::endl;
    std::cout << "s (source node) " << "      " << level[0] << std::endl;
    for (int i = 1; i < 10; ++i) {
        std::cout << i << "                  " << level[i] << std::endl;
    }
}



void initialize(){
    int x, y,edges;
    //std::cin >> nodes;
    std::cin >> edges;

    // why 0 to edge-1
    for (int i = 0; i < edges; ++i) {
        std::cin >> x >> y;
        adj[x].push_back(y);  // Insert y adjacency list of x
    }
}


int main(int argc, char *argv[])
{
    //representation();
    initialize();
    bfs(0);


    return 0;
}
