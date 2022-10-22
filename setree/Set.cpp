#include "Set.h"
#include <iostream>
using namespace std;

Set::Set(){
    mRoot = NULL;
}

Set::Set(const Set& other){
    mRoot = other.mRoot;
    /*
    Node* temp = other.mRoot;
    Node* current = NULL;
    if (other.mRoot == NULL){
        mRoot = NULL;
    }else{

        mRoot = new Node;
        mRoot->data = temp->data;
        mRoot->next = NULL;
        current = mRoot;
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
    mRoot = other.mRoot;
    other.mRoot = NULL;
}

Set::~Set(){
    delete mRoot;
    /*
    while (current != NULL){
        Node* next = current->next;
        delete current;
        current = next;
    }
    mRoot = NULL;
    */
}


size_t Set::clear() {
    size_t numValues = 1;
    if (mRoot == nullptr) {
        return 0;
    }
    if (mRoot->left != nullptr) {
        numValues += clear();
    }
    if (mRoot->right != nullptr) {
        numValues += clear();
    }
    delete mRoot;
    mRoot = nullptr;
    return numValues;
}

bool Set::contains(const std::string& value) const{
    Node *node = mRoot;
    while (node != nullptr){
        if (value == node->data){
            return true;
        }
        if (value < node->data){
            node = node->left;
        }else{
            node = node->right;
        }
    }
    return false;
}
size_t Count(Node *root){
    if(root == NULL){
        return 0;
    }
    return 1 + Count(root->left) + Count(root->right);
}

size_t Set::count() const{
    return Count(mRoot);
}

void Set::debug(){
    return;
}

size_t Set::insert(const std::string& value){
	Node* newNode = new Node;
	newNode->data = value;
	newNode->left = nullptr;
	newNode->right = nullptr;
	if (mRoot == nullptr){
		mRoot = newNode;
		return 1;
	}
	Node* curr = mRoot;
	while (curr != nullptr){
		if (value < curr->data){
			if (curr->left == nullptr){
				curr->left = newNode;
				return 1;
			}else{
				curr = curr->left;
			}
		}
		else if (value > curr->data){
			if (curr->right == nullptr){
				curr->right = newNode;
				return 1;
			}else{
				curr = curr->right;
			}
		}
		else{
			return 0;
		}
	}
	return 0;
}

Node* Leaf(Node* node){
    if(node->left == NULL){
        return node;
    }
    return Leaf(node->left);
}

Node* Reaf(Node* node){
    if(node->right == NULL){
        return node;
    }
    return Reaf(node->right);
}

const std::string& Set::lookup(size_t n) const{
    Node* look[this->count()];
    if(n >= this->count()){
        throw out_of_range("Out of range");
    }
    if(n == 0){
        return Leaf(mRoot) -> data;
    }
    else if(n==this->count() - 1){
        return Reaf(mRoot) -> data;
    }
    return look[n]->data;
}

void PrintP(Node* Ptr){
    if(Ptr == NULL){
        cout << "-";
    }
    else if(Ptr->left == NULL && Ptr->right == NULL){
        cout << Ptr->data;
    }
    else{
        cout << "(";
        PrintP(Ptr->left);
        cout << " " << Ptr->data << " ";
        PrintP(Ptr->right);
        cout << ")";
    }
    return;
}

void Set::print() const{
    PrintP(mRoot);
    cout << endl;
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
