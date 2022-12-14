
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
void Heap::push(const std::string & value, float score){
    Entry var = {value, score};
    if (mCount > mCapacity){
        throw overflow_error("OE");
    }else if(count() == capacity()){
        throw overflow_error("OE");
    }else{
        size_t ours = mCount;
        mData[ours] = var;
        mCount++;
        while(mData[(ours - 1)/2].score > mData[ours].score && ours != 0){
            Entry theirs = mData[ours];
            mData[ours] = mData[(ours - 1)/2];
            mData[(ours - 1)/2] = theirs;
            ours = (ours - 1)/2;
        }
    }
}
Heap::Entry Heap::pushpop(const std::string & value, float score){
    
    if (mCount == 0){
        throw underflow_error("UE");
    }

    Entry var = mData[0];
    mData[0] = {value, score};
    size_t ours = 0;   
    
    while(ours < mCount){
        size_t first = ours * 2 + 1;
        size_t second = ours * 2 + 2;
        if (first >= mCount){
            break;
        }
        if (second >= mCount){
            if (mData[ours].score > mData[first].score){
                Entry temp = mData[ours];
                mData[ours] = mData[first];
                mData[first] = temp;
                ours = first;
            }else{
                break;
            }
        }
        else{
            if (mData[ours].score > mData[first].score && mData[first].score <= mData[second].score){
                Entry temp = mData[ours];
                mData[ours] = mData[first];
                mData[first] = temp;
                ours = first;
            }else if (mData[ours].score > mData[second].score && mData[second].score <= mData[first].score){
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
        if (first < mCount && mData[first].score < mData[ours].score){
            largest = first;
        }else{
            largest = ours;
        }
        if (second < mCount && mData[second].score < mData[largest].score){
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
