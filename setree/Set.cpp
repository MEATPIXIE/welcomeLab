#include "Set.h"
using namespace std;

Set::Set(){
    mRoot = NULL;
}

Set::Set(const Set& other){
    mRoot = NULL;
    /*
    Node* temp = other.head;
    Node* current = NULL;
    if (other.head == NULL){
        head = NULL;
    }else{

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
    */
}

Set::Set(Set&& other){
    this->mRoot = other.mRoot;
    other.mRoot = NULL;
}

Set::~Set(){
    mRoot = NULL;
    /*
    while (current != NULL){
        Node* next = current->next;
        delete current;
        current = next;
    }
    mRoot = NULL;
    */
}



size_t Set::clear(){
    return 0;
}

bool Set::contains(const std::string& value) const{
    return false;
}

size_t Set::count() const{
    return 0;
    /*
    if(mRoot == NULL){
        return 0;
    }
    Node* temp = mR;
    size_t yo = 0;
    while(temp != NULL){
        yo++;
        temp = temp->next;
    }
    return yo; 
    */
}

void Set::debug(){
    return;
}

size_t Set::insert(const std::string& value){
    return 0;
    /*
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
    */
}

const std::string& Set::lookup(size_t n) const{
    return NULL;
    /*
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
    */
}

void Set::print() const{
    return;
    /*
    Node* current = this->head;
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
    */
}

size_t Set::remove(const std::string& value){
    return 0;
    /*
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
    */
}
