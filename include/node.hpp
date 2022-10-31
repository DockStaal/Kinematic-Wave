#ifndef NODE_HPP_
#define NODE_HPP_

#include <vector>

// A node in a drain direction map. 
// 
// Prev is empy means that it is a source node.
// Next is empty means that it is a sink node.
struct Node 
{
public:
    Node(); 
    Node(double x, double y, double cell_size, std::vector<Node*> prev, Node* next); 
    Node(double x, double y, double cell_size, double h, std::vector<Node*> prev, Node* next);

    // Add a previous node to the node. 
    // Throw an exception if the node is already in the list 
    // Throw an exception if node is a nullptr.
    void add_prev(Node* node);

    // Throw an exception is node is a nullptr.
    // Throw an exception if next is not nullptr.
    void add_next(Node* node); 

public:
    double h; // Value of the node. We only use h in the algorithm.
    double h_next; // Value of the next node. Only used in algorithm.

    double x; // x coordinate of the node in the map. (Not in the drain map vector)
    double y; // y coordinate of the node in the map. (Not in the drain map vector)

    double cell_size; // Cell size of the node.

    std::vector<Node*> prev; // List of poiters to previous nodes
    Node* next; // Pointer to the next node.
};

#endif // NODE_HPP_
