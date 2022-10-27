#ifndef NODE_H
#define NODE_H
#include <string>

struct Node {
    std::string data;
    Node*       left;
    Node*       right;
    ~Node();
};

Node::~Node(){
    delete left;
    delete right;
}


#endif

