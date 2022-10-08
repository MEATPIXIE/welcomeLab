#include <stdexcept>
#include "FibVec.h"
#include <iostream>
using namespace std;

FibVec::FibVec()
{
    this->mCount = 0;
    this->mCapacity = 1;
    mData = new size_t[mCapacity];
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
int FibVec::fibo(int degree){
    int first = 0;
    int second = 1;
    int carry = 0;
    int space;
    for(int i = 2; i <= degree + 1; i++){
        if(i == 1){
            space = first;
        } else if(i == 2){
            space = second;
        } else {
            carry = first + second;
            first = second;
            second = carry;
            space = carry;
        }
    }
    return space;
}
void FibVec::push(int value){
    if (mCount < mCapacity){
        mData[mCount] = value;
        ++mCount;
    }
    else{
        mCapacity *= 2;
        /*
        mCapacity = fibo(degree);
        degree++;
        */
        if (mCapacity >= mCount){
            size_t *newVec = new size_t[mCapacity];
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



//wrong
void FibVec::insert(int value, size_t index){
    if ((index >= mCount)){
        throw invalid_argument("out_of_range");
    }
    if (mCount != mCapacity){
        for (size_t i = mCount - 1; i >= index; i--){
            mData[i + 1] = mData[i];
        }
        mData[index] = value;
        ++mCount;
    }
    else{
        mCapacity *= 2;
        size_t* newVec = new size_t[mCapacity];
        for (size_t i = 0; i < mCount; i++){
            newVec[i] = mData[i];
        }
        delete[] mData;
        mData = newVec;
        insert(value, index);
    }
}
//wrong
size_t FibVec::lookup(size_t index) const{
    if ((index >= mCount)){
        throw out_of_range("out_of_range");
    }
    return mData[index];
}
//wrong
void FibVec::pop(){
    if (mCount == 0){
        throw underflow_error("underflow_error");
    }
    mCount--;
    //mData[mCount].~FibVec();
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
    
    for(int i = 1; i <= 7; i++){
        cout << endl << "Capacity before is " << v.capacity() << endl << "Count before is " << v.count() << endl;
        v.push(i);
        cout << v << endl;
        cout <<  "Capacity after is " << v.capacity() << endl << "Count after is " << v.count() << endl << endl;
    }
    return 0;
}
*/