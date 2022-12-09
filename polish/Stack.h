#ifndef STACK_H
#define STACK_H
#include "AST.h"

using namespace std;

struct Node{
    AST* data;
    Node* next;
    Node(AST* token){
        this->data = token;
        this->next = NULL;
    }
};

class Stack{
public:
    Stack();
    ~Stack();
    Node* topp;
    void push(AST* token);
    void pop();
    AST* top();
    
    size_t count = 0;
    bool isEmpty() const;
};

#endif
