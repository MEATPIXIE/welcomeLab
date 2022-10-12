#include <stdexcept>
#include "FibVec.h"
#include <iostream>
using namespace std;

FibVec::FibVec()
{
    mCount = 0;
    mCapacity = 1;
    mCapacity2 = 1;
    mData = new int[mCapacity];
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

void FibVec::FibDown(){
    size_t temp = mCapacity - mCapacity2;
    mCapacity = mCapacity2;
    mCapacity2 = temp;
    int* newVec = new int[mCapacity];
    for(size_t i = 0; i <mCapacity; i++){
        newVec[i] = mData[i];
    }
    delete[] mData;
    mData = newVec;
}

void FibVec::FibUp(int value, size_t index){
    size_t temp = mCapacity;
    mCapacity += mCapacity2;
    mCapacity2 = temp;
    int* newVec = new int[mCapacity];
    for (size_t i = 0; i < index; i++){
        newVec[i] = mData[i];
    }
    newVec[index++] = value;
    for (; index <= mCapacity2; index++){
        newVec[index] = mData[index - 1];
    }
    delete[] mData;
    mData = newVec;
}

void FibVec::push(int value){
    if (mCount < mCapacity){
        mData[mCount] = value;
        mCount++;
    }
    else{
        this->FibUp(value, mCapacity);
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
        this->FibUp(value, mCapacity);
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
size_t FibVec::lookup(size_t index) const{
    if ((index >= mCount)){
        throw out_of_range("out_of_range");
    }
    return mData[index];
}

size_t FibVec::pop(){
    if (mCount == 0){
        throw underflow_error("underflow_error");
    }
    int what = mData[mCount - 1];
    if (mCount == mCapacity - mCapacity2){
        this->FibDown();
    }
    mCount--;
    return what;
}
//wrong
size_t FibVec::remove(size_t index){
    if(index >= mCount){
        throw out_of_range("out_of_range");
    }
    int huh = mData[index];
    for (size_t i = index; i < mCount - 1; i++){
        mData[i] = mData[i + 1];
    }
    if (mCount == mCapacity - mCapacity2){
        this->FibDown();
    }

    return huh;
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
    
    for(int i = 0; i <= 12; i++){
        v.push(i);
        cout << v << endl;
    }
    //cout << v << endl;
    
    cout << v.count() << endl << v.capacity() << endl;
    for(int i = 0; i <= 8; i++){
        v.pop();
    }
    cout << v << endl;
    cout << v.count() << endl << v.capacity() << endl;
    
    return 0;
}
*/
//please