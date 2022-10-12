#include "List.h"
#include <cstring>
#include <iostream>
using namespace std;

List::List(){
    head = NULL;
}

/*
List::List(const List& other){
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
    str[strlen(other.str)] = '\0';
}
*/

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
