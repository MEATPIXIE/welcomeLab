#include "List.h"
#include <cstring>
#include <iostream>
using namespace std;

List::List()
    : str{ nullptr}
{
    str = new char[1];
    str[0] = '\0';
}

List::List(const List& other){
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
    str[strlen(other.str)] = '\0';
}

List::List(List&& other){
    str = other.str;
    other.str = nullptr;
}

List::~List(){
    delete str;
}