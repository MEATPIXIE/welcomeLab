#include "List.h"
#include <cstring>
#include <iostream>
#include <cstddef>
#include <stdexcept>
using namespace std;

List::List(){
    head = NULL;
}

List::List(const List& other){
    Node* temp = other.head;
    Node* current = NULL;
    if (other.head == NULL){
        head = NULL;
    }
    head = new Node;
    head->data = temp->data;
    head->next = NULL;
    current = head;
    temp = temp->next;

    while(temp != NULL){
        current->next = new Node;
        current = current->next;
        current->data = temp->data;
        current->next = NULL;
        temp = temp->next;
    }
} 

List::List(List&& other){
    this->head = other.head;
    other.head = NULL;
}

List::~List(){
    Node* current = head;
    while (current != NULL){
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
}

size_t List::count() const{
    if(head == NULL){
        return 0;
    }
    Node* temp = head;
    size_t yo = 0;
    while(temp != NULL){
        yo++;
        temp = temp->next;
    }
    return yo;
}

void List::insert(const std::string& value){
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;
    Node* current = head;
    if(head == NULL){
        head = temp;
    }
    if (head->data >= temp->data){
        head = temp;
        head->next = current;
        return;
    }
    while(current->next != NULL && current->next->data < temp->data){
        current = current->next;
    }
    temp->next = current->next;
    current->next = temp;
}

//impliment index > nodes throw
const string& List::lookup(size_t index) const{
    size_t what = 0;
    Node* temp = head;
    while(temp != NULL){
        if(what == index){
            return (temp->data);
        }
        what++;
        temp = temp->next;
    }
    throw out_of_range("out_of_range");
    return NULL;
}

void printReverse(Node* head, size_t heirs)
{
    if (head == NULL){
        return;
    }
    printReverse(head->next, heirs + 1);
    cout << head->data;
    if(heirs > 0){
        cout << ", ";
    }
}

void List::print(bool reverse) const{
    Node* current = this->head;
    if(reverse == false){
        string theirs = "[";
        while(current != NULL){
            theirs += current->data;
            if(current->next){
                theirs+=", ";
            }
            current = current->next;
        }
        theirs += "]";
        cout << theirs << endl;
    }
    if(reverse == true){
        cout << "[";
        size_t heirs = 0;
        printReverse(current, heirs);
        cout << "]" << endl;
    }
}

string List::remove(size_t index){
    Node* temp = head
    if(head == NULL){
        throw out_of_range("out_of_range");
    }
    if(index == 0){
        head = temp->next;
        string mine = temp->data;
        delete temp;
        return mine;
    }
    Node* current = head;
    for (size_t i = 0; i < index - 1; i++) {
       current = current->next;
    }
    string mine = current->next->data;
    delete current->next;
    current->next = NULL;
    return mine;
}

size_t List::remove(const std::string& value){
    size_t yours = 0;
    Node* current = head;
    Node* prev = NULL;
    while (current) {
        if (current->data == value) {
            yours++;
            if (current == head) {
                head = current->next;
                delete current;
                current = head;
                continue;
            }
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
    return yours;
}

/*
int main(){
    List a;
    a.insert("Doc");
    a.insert("Grumpy");
    a.insert("Happy");
    a.insert("Sleepy");
    a.insert("Bashful");
    a.insert("Sneezy");
    a.insert("Dopey");
    
    a.print();
}
*/
