#include "Stack.h"
#include <cstddef>
#include <iostream>
using namespace std;

Stack::Stack(){
    topp = NULL;
}

Stack::~Stack() {
    Node* curr;
    while(topp != NULL){
        curr = topp->next;
        delete topp;
        topp = curr;
    }
    this->count = 0;
}

void Stack::push(AST* token){
    struct Node* yuh = new Node(token);
    if(!topp){
        topp = yuh;
    }else{
        yuh->next = topp;
        topp = yuh;
    }
    count++;
}

void Stack::pop(){
    Node* yuh;
    if(topp == NULL){
        throw out_of_range("Empty");
    }else{
        yuh = topp->next;
        delete topp;
        topp = yuh;
    }
    this->count--;
}



bool Stack::isEmpty() const{
    return topp == NULL;
}

AST* Stack::top(){
    if (!this->isEmpty()){
        return topp->data;
    }
    throw out_of_range("Empty");
}
