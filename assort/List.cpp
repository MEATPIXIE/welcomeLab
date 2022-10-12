#include "List.h"
#include <cstring>
#include <iostream>
#include <cstddef>
using namespace std;

List::List(){
    head = NULL;
}

List::List(const List& other){
    /*
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
    str[strlen(other.str)] = '\0';
    */
    cout <<"efe";
}

List::List(List&& other){
    head = other.head;
    other.head = NULL;
}

List::~List(){
    Node *temp = head;
    while (temp != NULL){
        Node *temp2 = temp->next;
        delete temp;
        temp = temp2;
    }
}

size_t List::count() const{
    return 0;
}

void List::insert(const std::string& value){
    cout << "ewe";
}  


const string& List::lookup(size_t index) const{
    return NULL;
}

void List::print(bool reverse) const{
    cout << "ewewe";
}

string List::remove(size_t index){
    return 0;
}

size_t List::remove(const std::string& value){
    return 0;
}

/*
ostream& operator <<(ostream& ostr, const List& rhs){
    for(int i = 0; i < rhs.mCount; i++){
        ostr << rhs.mData[i] << " ";
    }
    ostr << " || ";
    for(int i = rhs.mCount; i < rhs.mCapacity; i++){
        ostr << rhs.mData[i] << " ";
    }
    return ostr;
}
*/
