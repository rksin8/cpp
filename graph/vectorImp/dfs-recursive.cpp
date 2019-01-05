#include <iostream>
#include <vector>

#define N 6

std::vector<int> v[N];

void dfsRecursive(int s, bool visited[])
{
    visited[s] = true;
    std::cout << s << " ";

    // loop through neigbours of s
    for (size_t w = 0;  w < v[s].size(); ++w) {
        auto node = v[s][w];
        if(!visited[node])
            dfsRecursive(node, visited);
    }
}

int main(int argc, char *argv[])
{
    int x , y;

    bool *visited = new bool[N];
    for (int i = 0; i < N; ++i) {
        visited[i] = false;
    }


    for (int i = 0; i < N; ++i) {
        std::cin >> x >> y;
        v[x].push_back(y);
    }


    dfsRecursive(2, visited);


    return 0;
}
