#ifndef STACK_H
#define STACK_H
#include "AST.h"

struct Node{
    AST* data;
    Node* next;
};

class Stack{
public:
    Stack();
    ~Stack();
    Node* topp;
    void push(AST* token);
    AST* pop();
    AST* top();

};

#endif
