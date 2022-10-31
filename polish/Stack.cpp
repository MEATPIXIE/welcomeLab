#include "Stack.h"
#include <cstddef>
#include <iostream>
using namespace std;

Stack::Stack(){
    topp = NULL;
}

Stack::~Stack() {
    Node* next;
    while(topp != NULL){
        next = topp->next;
        delete topp;
        topp = next;
    }
}

void Stack::push(AST* token){
    Node* n = new Node;
    if(topp == NULL){
        n->data = token;
        n->next = NULL;
        topp = n;
    }else{
        n->data = token;
        n->next = topp;
        topp = n;
    }
}

AST* Stack::pop(){
    AST* node = topp->data;
    if(topp == NULL){
        return NULL;
    }else{
        Node* temp;
        temp = topp;
        topp = topp->next;
        delete temp;
        temp = NULL;
    }
    return node;
}

AST* Stack::top(){
    AST* node = topp->data;
    return node;
}
