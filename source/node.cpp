#include <algorithm>
#include <stdexcept>
#include <vector>

#include "node.hpp"

Node::Node() 
    : h(0)
    , prev(std::vector<Node*>())
    , next(nullptr) 
{
}

Node::Node(double x, double y, double cell_size, std::vector<Node*> prev, Node* next) 
    : h(0)
    , x(x)
    , y(y)
    , cell_size(cell_size)
    , prev(prev)
    , next(next) 
{
}

Node::Node(double x, double y, double cell_size, double h, std::vector<Node*> prev, Node* next) 
    : h(h)
    , x(x)
    , y(y)
    , cell_size(cell_size)
    , prev(prev)
    , next(next) 
{
}

void Node::add_prev(Node* node) 
{
    if (node == nullptr) 
        throw std::invalid_argument("node is nullptr");
    if (std::find(prev.begin(), prev.end(), node) != prev.end()) 
        throw std::invalid_argument("node is already in the list");
    prev.push_back(node);
}

void Node::add_next(Node* node) 
{
    if (node == nullptr) 
        throw std::invalid_argument("node is nullptr");
    if (next != nullptr)
        throw std::invalid_argument("next is not nullptr");
    next = node;
}
