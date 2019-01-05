#include <iostream>
#include <stack>
#include <vector>

#define N  5
//std::vector<std::vector<int>> G;
std::vector<int> G[N];

void dfsIterative(int s)
{
    std::stack<int>  S;
    std::vector<bool> visited(N, false);
    S.push(s);
    visited[s] = true; // mark s as visited

    while (!S.empty()) {
        auto v = S.top(); S.pop();
        std::cout << v << " ";
        
        // loop through all the neighbours w of v and push it into S if not
        // visited and mark as visited
        for (size_t w = 0; w < G[v].size(); ++w) {
            if(!visited[G[v][w]]){
                S.push(G[v][w]);
                visited[v] = true; // mark as visited
            }
        }
    }
    std::cout << std::endl;
}


int main(int argc, char *argv[])
{
    int x, y;
    std::cout << "Enter node values with space : " << std::endl;
    for (int i = 0; i <N; ++i) {
        std::cin >> x>> y;
        G[x].push_back(y);
    }

    dfsIterative(0);
    return 0;
}
