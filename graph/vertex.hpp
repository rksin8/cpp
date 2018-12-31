#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <list>

class Node
{
private:
    int value_;
    std::list<Node> adjacents_;


public:
    Node(int value);

    bool operator==(const Node& node) const;

    void addAdajacent(const Node& node);

    void removeAdjacent(const Node& node);

    std::list<Node> getAdjacents();

    bool isAdjacent(const Node& node);

    int getValue() const;

    //virtual ~Node();
};

#endif /* NODE_H */
