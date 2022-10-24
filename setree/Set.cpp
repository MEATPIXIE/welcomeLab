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
}

Set::Set(const Set& other){
    mRoot = copyer(other.mRoot);
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
    size_t num = count();
    if (mRoot == nullptr) {
        return 0;
    }
    delete mRoot;
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

void organize(Node* mBranch, Node* list[], size_t index){
    if(mBranch == NULL){
        return;
    }
    organize(mBranch->left, list, index++);
    list[index] = mBranch;
    organize(mBranch->right, list, index++);
}

const std::string& Set::lookup(size_t n) const{
    Node* look[this->count()];
    if(n >= this->count()){
        throw out_of_range("Out of range");
    }
    if(n == 0){
        return Leaf(mRoot) -> data;
    }
    else if(n == 1){
        return mRoot->left->data;
    }
    else if(n==this->count() - 1){
        return Reaf(mRoot) -> data;
    }
    size_t num = 0;
    organize(mRoot, look, num);
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

struct Node* Delete(Node*& root, string data){
    if(root == NULL){
        return root;
    }
    else if(data < root->data){
        root->left = Delete(root->left, data);
    }
    else if(data > root->data){
        root->right = Delete(root->right, data);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        else if(root->left == NULL){
            struct Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL){
            struct Node *temp = root;
            root = root->left;
            delete temp;
        }
        
        else{
            struct Node* temp = Leaf(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
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

