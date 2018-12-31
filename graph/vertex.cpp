#include <algorithm>
#include <list>

#include "vertex.hpp"

Node::Node(int value):
    value_{value}{}


bool Node::operator==(const Node& rhs) const
{
    return value_ == rhs.value_;

}


void Node::addAdajacent(const Node& node)
{
    adjacents_.push_back(node);
}

void Node::removeAdjacent(const Node& node)
{
    // find the index of node
    auto it = std::find(adjacents_.begin(), adjacents_.end(), node);

    // then remove it
    if(it != adjacents_.end()){
        adjacents_.remove(node);
    }else{
        // throw an exception that node doesnot exist
    }
}
std::list<Node> Node::getAdjacents()
{
    return adjacents_;
}

bool Node::isAdjacent(const Node& node)
{
    // find the index of node
    auto it = std::find(adjacents_.begin(), adjacents_.end(), node);
    
    return it != adjacents_.end();
}
int Node::getValue() const
{
    return value_;
}
