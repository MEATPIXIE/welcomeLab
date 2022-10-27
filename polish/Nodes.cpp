//Nodes.cpp

#include "Nodes.h"
// Implement your AST subclasses' member functions here.
// To format a double for output:
//   std::ostringstream stream;
//   stream << value;
//   return stream.str();


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
