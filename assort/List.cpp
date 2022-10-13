#include "List.h"
#include <cstring>
#include <iostream>
#include <cstddef>
using namespace std;

List::List(){
    head = NULL;
}

List::List(const List& other){
    if (other.head == NULL){
        head = NULL;
    }
    Node* temp = other.head;
    Node* current = NULL;
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
    if(head == NULL){
        head = temp;
    }else{
        Node* current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = temp;
    }
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
    return NULL;
}

void List::print( bool reverse) const{
    cout << "[";
	if(reverse == false){
		Node* node = this->head;
		while (node != NULL) {
        	cout<<node->data<<" ";
			node = node->next;
    	}
	}else{
		Node* node = this->head;
		Node* current = node;
    	Node *prev = NULL, *next = NULL;
 
    	while (current != NULL) {
        	next = current->next;
        	current->next = prev;
        	prev = current;
        	current = next;
    	}
    	node = prev;
		while (node != NULL) {
        	cout<<node->data<<" ";
			node = node->next;
    	}
	}
    cout << "]";
}

string List::remove(size_t index){
    if(head == NULL){
        return NULL;
    }
    if(index == 0){
        string mine = head->data;
        delete head;
        head = NULL;
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
    cout << "hello" << endl;
}

void List::PushBack(int value){
    if(head == NULL){
        head = new List(value);
    }
    else{
        List* Current = head;
        while(Current->next != NULL){
            Current = Current-next;
        }
        List Node* Temp = new List()
    }
}

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
