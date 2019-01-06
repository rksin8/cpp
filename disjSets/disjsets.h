#ifndef DISJSETS_H
#define DISJSETS_H

#include <vector>

class Disjsets
{
private:
    std::vector<int> s;

public:
    explicit Disjsets(int numElementes);

    int find(int x) const;
    int find(int x);

    void unionSets(int root1, int root2);

    void unionByHeight(int root1, int root2);
};

#endif /* DISJSETS_H */
