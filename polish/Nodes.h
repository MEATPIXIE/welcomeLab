#ifndef NODES_H
#define NODES_H
#include "AST.h"

/*
class Node{
    double key;
    Node* left;
    Node* right;
};
*/

class Number: public AST{
    double data;
public:
    std::string prefix() const;
    std::string postfix() const = 0;
    double value() const;
};


class Add:public AST{
    public:
        AST* left;
        AST* right;
        Add(AST*, AST*);
        ~Add();
        std::string prefix() const;
        std::string postfix() const = 0;
        double value() const;
};

class Sub:public AST{
    public:
        AST* left;
        AST* right;
        Sub(AST*, AST*);
        ~Sub();
        std::string prefix() const;
        std::string postfix() const = 0;
        double value() const;
};

class Mul:public AST{
    public:
        AST* left;
        AST* right;
        Mul(AST*, AST*);
        ~Mul();
        std::string prefix() const;
        std::string postfix() const = 0;
        double value() const;
};

class Div:public AST{
    public:
        AST* left;
        AST* right;
        Div(AST*, AST*);
        ~Div();
        std::string prefix() const;
        std::string postfix() const = 0;
        double value() const;
};

class Rem:public AST{
    public:
        AST* left;
        AST* right;
        Rem(AST*, AST*);
        ~Rem();
        std::string prefix() const;
        std::string postfix() const = 0;
        double value() const;
};

class Neg:public AST{
    public:
        AST* left;
        //AST* right;
        Neg(AST*, AST*);
        ~Neg();
        std::string prefix() const;
        std::string postfix() const = 0;
        double value() const;
};


#endif
