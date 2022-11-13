
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
    if (index > mCapacity){ //|| index < 0){
        throw out_of_range ("OoR");
    }
    return mData[index];
}





Heap::Entry Heap::pop(){
    if (mCount == 0){
        throw underflow_error("UE");
    }
    
    Entry var = mData[0];
    var.value = "test";
    var.score = 0.0;
    
    return var;
}

Heap::Entry Heap::pushpop(const std::string & value, float score){
    Entry x;
    x.value = "mine";
    x.score = 0.0;
    
    if (mCount == 0){
        throw underflow_error("UE");
    }
    
    return x;
}




void Heap::push(const std::string & value, float score){
    if (mCount > mCapacity){
        throw overflow_error("OE");
    }
    
    size_t ours = 0;
    mData[0] = {value, score};
    
    while(ours < mCount){
        size_t left = 2 * ours + 2;
        size_t right = 2 * ours + 2;
        if (left >= mCount){
            break;
        }
        if (right >= mCount){
            if (mData[ours].score > mData[left].score){
                Entry temp = mData[ours];
                mData[ours] = mData[left];
                mData[left] = temp;
                ours = left;
            }else{
                break;
            }
        }
    }
}








const Heap::Entry& Heap::top() const{
    if (mCount == 0){
        throw underflow_error("UE");
    }
    
    return mData[0];
}
