#include <stdexcept>
#include "FibVec.h"
#include <iostream>
using namespace std;
/*
class FibVec{
private: 
    int* mData;
    size_t mCount;
    size_t mCapacity;
public:
    FibVec();
    ~FibVec();
    size_t count() const;
    size_t capacity() const;
    void insert (int index, int value);
    int lookup(int index);
    void pop();
    void push(int value);
    void remove(size_t index);
    
    
    friend ostream& operator <<(ostream& ostr, const FibVec& rhs);
}; 
*/



FibVec::FibVec()
{
    this->mCount = 0;
    this->mCapacity = 1;
    mData = new size_t[mCapacity];
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
/*
void Vector::PushBack(int value){
    if(size < capacity){
        array[size] = value;
        size++;
    }else{
        capacity = fibo(size);
        int *newarray = new int[capacity];
        for (int i=0; i < size; i++){
            newarray[i] = array[i];
        }
        newarray[size] = value;
        size++;
        delete[] array;
        array = newarray;
    }
}
*/


size_t FibVec::lookup(size_t index) const{
    if ((index >= mCount)){
        throw invalid_argument("out_of_range");
    }
    return mData[index];
}

void FibVec::pop(){
    if (mCount == 0){
        throw invalid_argument("underflow_error");
    }
    --mCount;
}

void FibVec::push(int value){
    if (mCount < mCapacity){
        mData[mCount] = value;
        ++mCount;
    }
    else{
        mCapacity *= 2;
        size_t* newVec = new size_t[mCapacity];
        for(size_t i = 0; i < mCount; i++){
            newVec[i] = mData[i];
        }
        mData[mCount] = value;
        ++mCount;
        
        /*
        delete[] mData;
        mData = newVec;
        */
        
    }
}

/*
void FibVec::push(int value){
    if (mCount < mCapacity){
        mData[mCount] = value;
        ++mCount;
    }
    else{
        mCapacity = fibo(size);
        size_t *newVec = new size_t[mCapacity];
        for(size_t i = 0; i < mCount; i++){
            newVec[i] = mData[i];
        }
        mData[mCount] = value;
        mCount++;
        delete[] mData;
        mData = newVec;
        
    }
}
*/
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


size_t FibVec::remove(size_t index){
    if(index >= mCount){
        throw invalid_argument("out_of_range");
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
        cout << rhs.mData[i] << " ";
    }
    return ostr;
}
int main()
{
    cout<<"Hello World" << endl;
    FibVec v;
    for(int i = 1; i <= 6; i++){
        v.push(i);
        
    }
    cout << v << endl;
    v.insert(8, 3);
    cout << v << endl;
 
    return 0;
}
*/