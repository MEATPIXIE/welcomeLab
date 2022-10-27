#ifndef STACK_H
#define STACK_H
#define SIZE 10

class Stack{
    int topp;
    int capacity;
    int *vec;
 
public:
    Stack(int size = SIZE);         // constructor
    ~Stack();                       // destructor
 
    void push(int);
    int pop();
    int top();
};

#endif
