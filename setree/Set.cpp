#include "Set.h"
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

size_t Set::clear(){
    return 0;
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


Node* insertHelper(Node* node, const std::string& value, Node* newNode){
    if (node == NULL){
        node == newNode;
    }
    else if(value < node->data){
        node->left = insertHelper(node->left, value, newNode);
    }
    else if(value > node->data){
        node->right = insertHelper(node->right, value, newNode);
    }
    return node;
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
