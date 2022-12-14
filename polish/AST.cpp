
#include "AST.h"
#include "Nodes.h"
#include <sstream>
#include "Stack.h"

using namespace std;

AST* AST::parse(const std::string& expression) {
    istringstream leer(expression);
    string token;
    Stack c;
    while(leer >> token){
        if(token == "+"){
            if(c.count < 2){ //fix this
                while(!c.isEmpty()){
                    AST* yuh = c.top();
                    c.pop();
                    delete yuh;
                }
                throw runtime_error("Not enough operands.");
            }
            Add* aNode = new Add;
            AST* rNode = c.top();
            aNode->right = rNode;
            c.pop();
            
            AST* lNode = c.top();
            aNode->left = lNode;
            c.pop();
            c.push(aNode);
            continue;
        }else if(token == "-"){
            if(c.count < 2){
                while(!c.isEmpty()){
                    AST* yuh = c.top();
                    c.pop();
                    delete yuh;
                }
                throw runtime_error("Not enough operands.");
            }
            Sub* sNode = new Sub;
            AST* rNode = c.top();
            sNode->right = rNode;
            c.pop();

            AST* lNode = c.top();
            sNode->left = lNode;
            c.pop();
            c.push(sNode);
            continue;
        }else if(token == "*"){
            if(c.count < 2){
                while(!c.isEmpty()){
                    AST* yuh = c.top();
                    c.pop();
                    delete yuh;
                }
                throw runtime_error("Not enough operands.");
            }
            Mul* mNode = new Mul;
            AST* rNode = c.top();
            mNode->right = rNode;
            c.pop();

            AST* lNode = c.top();
            mNode->left = lNode;
            c.pop();
            c.push(mNode);
            continue;
        }else if(token == "/"){
            if(c.count < 2){
                while(!c.isEmpty()){
                    AST* yuh = c.top();
                    c.pop();
                    delete yuh;
                }
                throw runtime_error("Not enough operands.");
            }
            Div* dNode = new Div;
            AST* rNode = c.top();
            dNode->right = rNode;
            c.pop();

            AST* lNode = c.top();
            dNode->left = lNode;
            c.pop();
            c.push(dNode);
            continue;
        }else if(token == "%"){
            if(c.count < 2){
                while(!c.isEmpty()){
                    AST* yuh = c.top();
                    c.pop();
                    delete yuh;
                }
                throw runtime_error("Not enough operands.");
            }
            Rem* remNode = new Rem;
            AST* rNode = c.top();
            remNode->right = rNode;
            c.pop();

            AST* lNode = c.top();
            remNode->left = lNode;
            c.pop();
            c.push(remNode);
            continue;
        }else if(token == "~"){
            if(c.count == 0){
                throw runtime_error("Not enough operands.");
            }
            Neg* nNode = new Neg;
            nNode->left = c.top();
            c.pop();
            c.push(nNode);
            continue;
        }else{
            string::size_type readSize;
            string error = "Invalid token: " + token;
            try{
                double end = stod(token, &readSize);
                if(readSize != token.length()){
                    while(!c.isEmpty()){
                        AST* yuh = c.top();
                        c.pop();
                        delete yuh;
                    }
                    throw runtime_error(error);
                }
                Number* lNode = new Number(end);
                c.push(lNode);
            }catch(...){
                while(!c.isEmpty()){
                    AST* yuh = c.top();
                    c.pop();
                    delete yuh;
                    }
                throw runtime_error(error);
                }
        }
    }
    if(c.count == 0){
        throw runtime_error("No input.");
    }else if(c.count > 1){
        while(!c.isEmpty()){
            AST* yuh = c.top();
            c.pop();
            delete yuh;
        }
        throw runtime_error("Too many operands.");
    }
    return c.top();
}   
