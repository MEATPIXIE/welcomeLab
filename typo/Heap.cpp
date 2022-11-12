
#include "Heap.h"


Heap::Heap(size_t capacity){
    mCapacity = capacity;
    mCount = 0;
    mData =  new Entry[capacity];
}

Heap::Heap(const Heap& other){
}

Heap::Heap(Heap&& other){
    this->mData = other.mData;
    this->mCount = other.mCount;
    this->mCapacity = other.mCapacity;
    
    other.mData = NULL;
}

Heap::~Heap(){
}

size_t Heap::capacity() const{
    return 0;
}

size_t Heap::count() const{
    return 0;
}

const Heap::Entry& Heap::lookup(size_t index) const{
    return mData[index];
}

Heap::Entry Heap::pop(){
    Entry var;
    
    var.value = "test";
    var.score = 0.0;
    
    return var;
    
}

Heap::Entry Heap::pushpop(const std::string& value, float score){
    Entry x;
    
    x.value = "mine";
    x.score = 0.0;
    
    return x;
}

void Heap::push(const std::string& value, float score){
}

const Heap::Entry& Heap::top() const{
    return mData[0];
}
