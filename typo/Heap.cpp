
#include "Heap.h"
#include <stdexcept>
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
    if (index > mCapacity || index < 0){
        throw out_of_range ("OoR");
    }
    return mData[index];
}





Heap::Entry Heap::pop(){
    Entry var;
    var.value = "test";
    var.score = 0.0;
    
    if (mCount == 0){
        throw underflow_error("underflow_error");
    }
    return var;
}

Heap::Entry Heap::pushpop(const std::string & value, float score){
    Entry x;
    x.value = "mine";
    x.score = 0.0;
    
    if (mCount == 0){
        throw underflow_error("underflow_error");
    }
    
    return x;
}

void Heap::push(const std::string & value, float score){
    /*
    if (mCount == 0){
        throw underflow_error("underflow_error");
    }
    */
}

const Heap::Entry& Heap::top() const{
    if (mCount == 0){
        throw underflow_error("underflow_error");
    }
    
    return mData[0];
}
