
#include "Helpers.h"

#include <stdexcept>
#include <cmath>
using namespace std;


Heap::Heap (size_t capacity){
    mCapacity = capacity;
    mCount = 0;
    mData = new Entry[capacity];
}
Heap::Heap (const Heap & other){
    this->mCapacity = other.mCapacity;
    this->mCount = other.mCount;
    this->mData = other.mData;
    Entry *mine = new Entry[mCapacity];
    if (other.mData == NULL){
        return;
    }else{
        for (size_t i = 0; i < mCount; i++){
            mine[i] = other.mData[i];
        }
    }
    mData = mine;
}
Heap::Heap (Heap && other){
    this->mCapacity = other.mCapacity;
    this->mCount = other.mCount;
    this->mData = other.mData;
    other.mData = NULL;
}
Heap::~Heap(){
    delete[]mData;
}
size_t Heap::capacity() const{
  return mCapacity;
}
size_t Heap::count() const{
  return mCount;
}
const Heap::Entry& Heap::lookup (size_t index) const{
    if (index >= mCount || mCount == 0){
        throw out_of_range ("OoR");
    }else{
        return mData[index];
    }
}
const Heap::Entry& Heap::top() const{
    if (mCount == 0){
        throw underflow_error("UE");
    }else{
        return mData[0];
    }
}

void Heap::push(const Star& value, float distance){
    Entry var = {value, distance};
    if (mCount > mCapacity){
        throw overflow_error("OE");
    }else if(count() == capacity()){
        throw overflow_error("OE");
    }else{
        size_t ours = mCount;
        mData[ours] = var;
        mCount++;
        while(mData[(ours - 1)/2].distance > mData[ours].distance && ours != 0){
            Entry theirs = mData[ours];
            mData[ours] = mData[(ours - 1)/2];
            mData[(ours - 1)/2] = theirs;
            ours = (ours - 1)/2;
        }
    }
}
Heap::Entry Heap::pop(){
    if (mCount == 0){
        throw underflow_error("UE");
    }else if(mCount == 1){
        mCount--;
        return mData[0];
    }

    Entry var = mData[0];
    mData[0] = mData[mCount - 1];
    mCount--;
    size_t ours = 0;   
    
    while(ours < mCount){
        size_t first = (ours * 2) + 1;
        size_t second = (ours * 2) + 2;
        size_t largest = ours;

        if (first < mCount && mData[first].distance > mData[ours].distance){
            largest = first;
        }else{
            largest = ours;
        }
        if (second < mCount && mData[second].distance > mData[ours].distance){
            largest = second;
        }
        if (largest != ours){
            swap(mData[ours], mData[largest]);
            ours = largest;
        }else{
            break;
        }
    }
    return var;
}
Heap::Entry Heap::pushpop(const Star& value, float distance){
    
    if (mCount == 0){
        throw underflow_error("UE");
    }

    Entry var = mData[0];
    mData[0] = {value, distance};
    size_t ours = 0;   
    
    while(ours < mCount){
        size_t first = ours * 2 + 1;
        size_t second = ours * 2 + 2;
        if (first >= mCount){
            break;
        }
        if (second >= mCount){
            if (mData[ours].distance < mData[first].distance){
                Entry temp = mData[ours];
                mData[ours] = mData[first];
                mData[first] = temp;
                ours = first;
            }else{
                break;
            }
        }
        else{
            if (mData[ours].distance < mData[first].distance && mData[first].distance >= mData[second].distance){
                Entry temp = mData[ours];
                mData[ours] = mData[first];
                mData[first] = temp;
                ours = first;
            }else if (mData[ours].distance < mData[second].distance && mData[second].distance >= mData[first].distance){
                Entry temp = mData[ours];
                mData[ours] = mData[second];
                mData[second] = temp;
                ours = second;
            }else{
                break;
            }
        }
    }
    return var;
}
double distanceFrom(double x, double y, double z){
    double firstJump = sqrt(((Star.x - x)*(Star.x - x)) + ((Star.y - y)*(Star.y - y)));
    double secondJump = sqrt((firstJump * firstJump) + ((Star.z - z)*(Star.z - z)));
    return secondJump;
} 

////////////////////////////////////////////////////////////////////////////////
/////////////  HEAP ^  /////////////  K-DIMENTIONAL MAP v  /////////////////////
////////////////////////////////////////////////////////////////////////////////

/*
const int k = 2 //3

struct Node{
    int point[k];
    Node *left, *right;
}
struct Node* newNode(int arr[]){
    struct Node* temp = new Node;

    for (int i= 0; i< k; i++){
        temp -> point[i] = arr[i];
    }
    temp->left = temp->right = NULL;
    return temp;
}

// Insert new point with given point in KD Tree and return new root
Node *insertRec(Node *root, int point[], unsigned depth){
    if (root == NULL){
       return newNode(point);
    }
    unsigned cd = depth % k; //x, y, or z?
  
    // Compare and decide left or right subtree
    if (point[cd] < (root->point[cd]))
        root->left  = insertRec(root->left, point, depth + 1);
    else
        root->right = insertRec(root->right, point, depth + 1);
  
    return root;
}
Node* insert(Node *root, int point[]){
    return insertRec(root, point, 0);
}

// Searches a Point represented by "point[]" in the K D tree.
bool searchRec(Node* root, int point[], unsigned depth){
    if (root == NULL)
        return false;
    if (arePointsSame(root->point, point))
        return true;
  
    // Current dimension is computed using current depth and total dimensions (k)
    unsigned cd = depth % k;
  
    // Compare point with root with respect to cd (Current dimension)
    if (point[cd] < root->point[cd]){
        return searchRec(root->left, point, depth + 1);
    }
    return searchRec(root->right, point, depth + 1);
}
bool search(Node* root, int point[]){
    return searchRec(root, point, 0);//Pass current depth as 0
}

bool arePointsSame(int point1[], int point2[]){
    for(int i = 0; i < k; i++){
        if (point1[i] != point2[i]){
            return false;
        }
    }
    return true;
}
*/
