#ifndef NODES_H
#define NODES_H
#include "AST.h"

class Node{
    int key;
    Node* left;
    Node* right;
};
class Number: public AST{
    double data;
public:
    std::string prefix() const;
    std::string postfix() const = 0;
    double value() const;
};



class Add: public AST{
    public:
        AST* left;
        AST* right;
        Add(AST*, AST*);
        ~Add();
        std::string prefix() const;
        std::string postfix() const = 0;
        double value() const;
};






#endif
