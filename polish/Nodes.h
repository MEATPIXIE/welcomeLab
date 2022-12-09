#ifndef NODES_H
#define NODES_H
#include "AST.h"

class Number: public AST{
    double data;
public:
    AST* left;
    AST* right;
    Number(double token);
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};


class Add:public AST{
    public:
        AST* left;
        AST* right;
        Add();
        ~Add();
        std::string prefix() const;
        std::string postfix() const;
        double value() const;
};

class Sub:public AST{
    public:
        AST* left;
        AST* right;
        Sub();
        ~Sub();
        std::string prefix() const;
        std::string postfix() const;
        double value() const;
};

class Mul:public AST{
    public:
        AST* left;
        AST* right;
        Mul();
        ~Mul();
        std::string prefix() const;
        std::string postfix() const;
        double value() const;
};

class Div:public AST{
    public:
        AST* left;
        AST* right;
        Div();
        ~Div();
        std::string prefix() const;
        std::string postfix() const;
        double value() const;
};

class Rem:public AST{
    public:
        AST* left;
        AST* right;
        Rem();
        ~Rem();
        std::string prefix() const;
        std::string postfix() const;
        double value() const;
};

class Neg:public AST{
    public:
        AST* left;
        //AST* right;
        Neg();
        ~Neg();
        std::string prefix() const;
        std::string postfix() const;
        double value() const;
};



#endif
