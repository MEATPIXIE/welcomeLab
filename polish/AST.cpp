#include "AST.h"
#include "Nodes.h"
#include <sstream>
#include "Stack.h"

AST* AST::parse(const std::string& expression) {
    std::istringstream mystream(expression);
    std::string token;
    Stack c;
    while(mystream >> token){
        if(token == "+"){
            /*
            if(c.topp < 2){
                while(c.topp > 0){
                    AST* temp = c.top();
                    c.pop();
                    delete temp;
                }
                throw std::runtime_error("Not enough operands.");
            }
            */
            Add* Adder = new Add;
            AST* rightN = c.top();
            Adder->right = rightN;
            c.pop();
            AST* leftN = c.top();
            Adder->left = leftN;
            c.pop();
            c.push(Adder);
            continue;
        }
        
        else if(token == "-"){
            /*
            if(c.topp < 2){
                while(c.topp > 0){
                    AST* temp = c.top();
                    c.pop();
                    delete temp;
                }
                throw std::runtime_error("Not enough operands.");
            }
            */
            Sub* Subber = new Sub;
            AST* rightN = c.top();
            Subber->right = rightN;
            c.pop();
            AST* leftN = c.top();
            Subber->left = leftN;
            c.pop();
            c.push(Subber);
            continue;
        }
        
        else if(token == "*"){
            /*
            if(c.topp < 2){
                while(c.topp > 0){
                    AST* temp = c.top();
                    c.pop();
                    delete temp;
                }
                throw std::runtime_error("Not enough operands.");
            }
            */
            Mul* Multer = new Mul;
            AST* rightN = c.top();
            Multer->right = rightN;
            c.pop();
            AST* leftN = c.top();
            Multer->left = leftN;
            c.pop();
            c.push(Multer);
            continue;
        }
        
        else if(token == "/"){
            /*
            if(c.topp < 2){
                while(c.topp > 0){
                    AST* temp = c.top();
                    c.pop();
                    delete temp;
                }
                throw std::runtime_error("Not enough operands.");
            }
            */
            Div* Divide = new Div;
            AST* rightN = c.top();
            Divide->right = rightN;
            c.pop();
            AST* leftN = c.top();
            Divide->left = leftN;
            c.pop();
            c.push(Divide);
            continue;
        }
        
        else if(token == "%"){
            /*
            if(c.topp < 2){
                while(c.topp > 0){
                    AST* temp = c.top();
                    c.pop();
                    delete temp;
                }
                throw std::runtime_error("Not enough operands.");
            }
            */
            Rem* Remain = new Rem;
            AST* rightN = c.top();
            Remain->right = rightN;
            c.pop();
            AST* leftN = c.top();
            Remain->left = leftN;
            c.pop();
            c.push(Remain);
            continue;
        }
        else if(token == "~"){
            /*
            if(c.topp < 2){
                while(c.topp > 0){
                    AST* temp = c.top();
                    c.pop();
                    delete temp;
                }
                throw std::runtime_error("Not enough operands.");
            }
            */
            Neg* Negate = new Neg;
            AST* leftN = c.top();
            Negate->left = leftN;
            c.pop();
            c.push(Negate);
            continue;
        }
        
        else{ //if(token >= 0 && token <= 9){
            /*
            if(c.topp < 2){
                while(c.topp > 0){
                    AST* temp = c.top();
                    c.pop();
                    delete temp;
                }
                throw std::runtime_error("Not enough operands.");
            }
            */
            Number* nummm = new Number;
            AST* rightN = c.top();
            nummm->right = rightN;
            c.pop();
            AST* leftN = c.top();
            nummm->left = leftN;
            c.pop();
            c.push(nummm);
            continue;
        }
        /*    
        else{
            
            if(c.topp < 2){
                while(c.topp > 0){
                    AST* temp = c.top();
                    c.pop();
                    delete temp;
                }
                
                throw std::runtime_error("Invalid token: XXX");
            }
        }
        */
    }
    return c.top();
}
