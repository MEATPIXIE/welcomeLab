#include "Set.h"
#include <iostream>
using namespace std;

Set::Set(){
    mRoot = NULL;
}

Node* copyer(const Node* mRoot){
    if(mRoot == NULL){
        return NULL;
    }
    Node* copy = new Node();
    copy->left = copyer(mRoot->left);
    copy->data = mRoot->data;
    copy->right = copyer(mRoot->right);
    return copy;
    //delete copy;
}

Set::Set(const Set& other){
    mRoot = copyer(other.mRoot);
}

Set::Set(Set&& other){
    mRoot = other.mRoot;
    other.mRoot = NULL;
}

Set::~Set(){
    this->clear();
}

void cleanup(Node* node){
	if(!node){
		return;
	}else{
		cleanup(node->left);
		cleanup(node->right);
		delete node;
		return;
	}
}

size_t Set::clear() {
    size_t num = this->count();
    cleanup(mRoot);
    mRoot = nullptr;
    return num;
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
	    delete newNode;
	    return 0;
	}
    }
    delete newNode;
    return 0;
}

Node* mineaf(Node* root){
    root = root->left
    while(root->right != NULL){ 
	    root = root->right;
    }
    return root;
}

Node* Reaf(Node* node){
    Node* curr = node;
    while(curr->right != NULL){
        curr = curr->right;
    }
    return curr;
}

int organize(Node* mBranch, string* vector, int index){
    if(mBranch == NULL){
        return index;
    }
    index = organize(mBranch->left, vector, index);
    vector[index] = mBranch->data;
    index = organize(mBranch->right, vector, index + 1);
    return index;
}

string str;
const std::string& Set::lookup(size_t n) const{
    size_t size = count();
    string vec[size];
    organize(mRoot, vec, 0);
    if (n >= size){
        throw out_of_range("out of range");
    }
    str = vec[n];
    return str;
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


struct Node* Delete(struct Node*& root, string data) {
    if(root == NULL){ 
	    return root; 
    }
    else if(data < root->data){ 
	    root->left = Delete(root->left,data);
    }
    else if (data > root->data){ 
	    root->right = Delete(root->right,data);
    }else{
	    if(root->left == NULL && root->right == NULL) { 
	        delete root;
	        root = NULL;
	    }else if(root->left == NULL) {
    	    struct Node *temp = root;
	        root = root->right;
	        delete temp;
	    }else if(root->right == NULL) {
	        struct Node *temp = root;
    	    root = root->left;
	        delete temp;
	    }else{ 
	        struct Node *temp = mineaf(root->right);
	        root->data = temp->data;
	        root->right = Delete(root->right,temp->data);
	    }
    }
    return root;
}


size_t Set::remove(const std::string& value){
    if (contains(value) == false){
        return 0;
    }
    Delete(mRoot, value);
    return 1;
}
