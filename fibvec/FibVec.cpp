#include <stdexcept>
#include "FibVec.h"
#include <iostream>
using namespace std;

FibVec::FibVec()
{
    this->mCount = 0;
    this->mCapacity = 1;
    mData = new int[mCapacity];
    this->degree = 1;
}
FibVec::~FibVec(){
    delete[] mData;
}
size_t FibVec::capacity() const{
    return mCapacity;
}
size_t FibVec::count() const{
    return mCount;
}
size_t FibVec::Fibonacci(size_t n) const{
    if (n <= 1){
        return 1;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
size_t FibVec::FibResize(size_t count, size_t capacity) const{
    size_t n = count + 1;
    size_t i = 1;
    
    while(n > capacity){
        capacity = Fibonacci(i + 1);
        i++;
    }
    
    if (n < Fibonacci(i - 2)){
        capacity = Fibonacci(i - 1);
        i--;
    }
    return capacity;
}
void FibVec::push(int value){
    if (mCount < mCapacity){
        mData[mCount] = value;
        ++mCount;
    }
    else{
        mCapacity = FibResize(mCount, mCapacity);
        if (mCapacity >= mCount){
            int *newVec = new int[mCapacity];
            for(size_t i = 0; i < mCount; i++){
                newVec[i] = mData[i];
            }
            newVec[mCount] = value;
            mCount++;
            delete[] mData;
            mData = newVec;
        }
    }
}

void FibVec::insert(int value, size_t index){
    if(index > mCount){
        throw out_of_range("out_of_range");
    }
    if (mCount < mCapacity){
        int* newVec = new int[mCapacity];
        for(size_t i = 0; i < mCount + 1; i++){
            if(i < index){
                newVec[i] = mData[i];
            }
            else if (i == index){
                newVec[i] = value;
            }
            else{
                newVec[i] = mData[i - 1];
            }
        }
        delete[] mData;
        mCount += 1;
        mData = newVec;
    }else{
        mCapacity = FibResize(mCount, mCapacity);
        if(mCapacity >= mCount){
            int* newVec = new int[mCapacity];
            for(size_t i = 0; i < mCount + 1; i++){
                if(i < index){
                    newVec[i] = mData[i];
                }
                else if (i == index){
                    newVec[i] = value;
                }
                else{
                    newVec[i] = mData[i - 1];
                }
            }
        delete[] mData;
        mCount += 1;
        mData = newVec;
        }
    }
}

//wrong
size_t FibVec::lookup(size_t index) const{
    if ((index >= mCount)){
        throw out_of_range("out_of_range");
    }
    return mData[index];
}
//wrong2
size_t FibVec::pop(){
    if (mCount == 0){
        throw underflow_error("underflow_error");
    }else{
        size_t last = mData[mCount - 1];
        int *newVec = new int[mCapacity];
        for(size_t i = 0; i < mCount; i++){
            newVec[i] = mData[i];
        }
        mCount--;
        delete[] mData;
        mData = newVec;
        return last;
    }
}
//wrong
size_t FibVec::remove(size_t index){
    if(index >= mCount){
        throw out_of_range("out_of_range");
    }
    for (size_t i = index; i < mCount - 1; i++){
        mData[i] = mData[i + 1];
    }
    --mCount;

    return 0;
}


/*
ostream& operator <<(ostream& ostr, const FibVec& rhs){
    for(int i = 0; i < rhs.mCount; i++){
        ostr << rhs.mData[i] << " ";
    }
    ostr << " || ";
    for(int i = rhs.mCount; i < rhs.mCapacity; i++){
        ostr << rhs.mData[i] << " ";
    }
    return ostr;
}
int main()
{
    FibVec v;
    
    for(int i = 0; i <= 15; i++){
        //cout << endl << "Capacity before is " << v.capacity() << endl << "Count before is " << v.count() << endl;
        v.insert(i, i);
        cout << v << endl;
        //cout <<  "Capacity after is " << v.capacity() << endl << "Count after is " << v.count() << endl << endl;
    }
    //cout << v << endl;
    return 0;
}
*/
