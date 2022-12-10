//Nodes.cpp
#include "Nodes.h"

#include <sstream>
#include <cmath>

Number::Number(double token){
    this->data = token;
}

std::string Number::prefix() const{
    std::ostringstream mystream;
    mystream << this->data;
    return mystream.str();
}

std::string Number::postfix() const{
    std::ostringstream mystream;
    mystream << this->data;
    return mystream.str();
}

double Number::value() const{
    return this->data;
}


Add::Add(){
}
Add::~Add(){
    delete left;
    delete right;
}
double Add::value() const{
    return this->left->value() + this->right->value();
}
std::string Add::prefix() const{
    return "+ " + left->prefix() + " " + right->prefix();
}
std::string Add::postfix() const{
    return left->postfix() + " " + right->postfix() + " +";
}


Sub::Sub(){
}
Sub::~Sub(){
    delete left;
    delete right;
}
double Sub::value() const{
    return this->left->value() - this->right->value();
}
std::string Sub::prefix() const{
    return "- " + left->prefix() + " " + right->prefix();
}
std::string Sub::postfix() const{
    return left->postfix() + " " + right->postfix() + " -";
}


Mul::Mul(){
}
Mul::~Mul(){
    delete left;
    delete right;
}
double Mul::value() const{
    return this->left->value() * this->right->value();
}
std::string Mul::prefix() const{
    return "* " + left->prefix() + " " + right->prefix();
}
std::string Mul::postfix() const{
    return left->postfix() + " " + right->postfix() + " *";
}




Div::Div(){
}
Div::~Div(){
    delete left;
    delete right;
}
double Div::value() const{
    if(this->right->value() == 0){
        throw std::runtime_error("Division by zero."); 
    }else{
        return this->left->value() / this->right->value();
    }
}
std::string Div::prefix() const{
    return "/ " + left->prefix() + " " + right->prefix();
}
std::string Div::postfix() const{
    return left->postfix() + " " + right->postfix() + " /";
}


Rem::Rem(){
}
Rem::~Rem(){
    delete left;
    delete right;
}
double Rem::value() const{
    if(this->right->value() == 0){
        throw std::runtime_error("Division by zero."); 
    }else{
        double mine, a, b;
        a = this->left->value();
        b = this->right->value();
        mine = remainder(b, a);
        return mine;
    }
}
std::string Rem::prefix() const{
    return "% " + left->prefix() + " " + right->prefix();
}
std::string Rem::postfix() const{
    return left->postfix() + " " + right->postfix() + " %";
}


Neg::Neg(){
}
Neg::~Neg(){
    delete left;
    //delete right;
}
double Neg::value() const{
    return this->left->value() * -1;
}
std::string Neg::prefix() const{
    return "~ " + left->prefix();
}
std::string Neg::postfix() const{
    return left->postfix() + " ~";
}
