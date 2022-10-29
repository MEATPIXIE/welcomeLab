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


Sub::Sub(AST*, AST*){
}
Sub::~Sub(){
    delete left;
    delete right;
}
double Sub::value() const{
    return (left->value() - right->value());
}
std::string Sub::prefix() const{
    return left->prefix() + " " - right->prefix() + " /";
}
std::string Sub::postfix() const{
    return left->postfix() + " " - right->postfix() + " /";
}


Mul::Mul(AST*, AST*){
}
Mul::~Mul(){
    delete left;
    delete right;
}
double Mul::value() const{
    return (left->value() * right->value());
}
std::string Mul::prefix() const{
    return left->prefix() + " " * right->prefix() + " /";
}
std::string Mul::postfix() const{
    return left->postfix() + " " * right->postfix() + " /";
}


Div::Div(AST*, AST*){
}
Div::~Div(){
    delete left;
    delete right;
}
double Div::value() const{
    return (left->value() / right->value());
}
std::string Div::prefix() const{
    return left->prefix() + " " / right->prefix() + " /";
}
std::string Div::postfix() const{
    return left->postfix() + " " / right->postfix() + " /";
}


Rem::Rem(AST*, AST*){
}
Rem::~Rem(){
    delete left;
    delete right;
}
double Rem::value() const{
    return (left->value() % right->value());
}
std::string Rem::prefix() const{
    return left->prefix() + " " % right->prefix() + " /";
}
std::string Rem::postfix() const{
    return left->postfix() + " " % right->postfix() + " /";
}


Neg::Neg(AST*, AST*){
}
Neg::~Neg(){
    delete left;
    //delete right;
}
double Neg::value() const{
    return (left->value() * -1);
}
std::string Neg::prefix() const{
    return left->prefix() + " " * -1 + " /";
}
std::string Neg::postfix() const{
    return left->postfix() + " " * -1 + " /";
}
