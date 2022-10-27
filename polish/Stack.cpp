#include "Stack.h"
#include <cstddef>
#include <iostream>
using namespace std;

Stack::Stack(int size){
    topp = -1;
    capacity = size;
    vec = new int[size];
}
Stack::~Stack() {
    delete[] vec;
}
void Stack::push(int x){
    if (topp == capacity - 1){
        cout << "Overflow";
        return;
    }
    vec[++topp] = x;
}
int Stack::pop(){
    if(topp == 0){
        cout << "Underflow";
    }
    return vec[topp--];
}
int Stack::top(){
    if(topp > 0){
        return vec[topp];
    }
    return 0;
}

/*
int main(){
    Stack a(SIZE);
    a.push(1);
    a.pop();
    a.pop();
    
    return 0;
}
*/
