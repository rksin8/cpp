#include <iostream>
#include <iostream>
#include <queue>
#include <deque>


using pair = std::pair<int, int>; // node, weight

using Edge = pair;
//std::vector<Edge> edges;

std::vector<std::vector<pair>> edges;

void bfs(int start)
{
    std::deque<int> q;
    std::vector<int> distance;
    q.push_back(start);
    distance[start] = 0;

    while (!q.empty()) {
        auto v = q.front(); q.pop_front();

        // loop through all the neighbours of v
        for (size_t i = 0; i < edges[v].size(); ++i) {


            if (distance[edges[v][i].first] > distance[v] + edges[v][i].second) {
                distance[edges[v][i].first] = distance[v] + edges[v][i].second;

                if ( edges[v][i].second == 0)
                    q.push_front(edges[v][i].first);
                else
                    q.push_back(edges[v][i].first);
            }
            
        }
        
    }
}


int main(int argc, char *argv[])
{
    using pair = std::pair<int, double>;
    std::vector<int> v[10];
    pair p = {2,3.0};

    std::cout << p.first << " " << p.second << std::endl;

    return 0;
}
