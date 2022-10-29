//Nodes.cpp
#include "Nodes.h"

double Number::value() const{
    return data;
}
std::string prefix() {
    //cout << "DWDE";
    return NULL;
}
std::string postfix() {
    //cout << "ddee";
    return NULL;
}



Add::Add(AST*, AST*){
}
Add::~Add(){
    delete left;
    delete right;
}
double Add::value() const{
    return (left->value() + right->value());
}
std::string Add::prefix() const{
    return left->prefix() + " " + right->prefix() + " /";
}
std::string Add::postfix() const{
    return left->postfix() + " " + right->postfix() + " /";
}
