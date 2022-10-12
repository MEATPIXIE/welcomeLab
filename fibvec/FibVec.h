#include <iostream>
using namespace std;

class FibVec{
private: 
    int* mData;
    size_t mCount;
    size_t mCapacity;
    size_t mCapacity2;
    void FibUp(int value, size_t index);
    void FibDown();
public:
    FibVec();
    ~FibVec();
    size_t count() const;
    size_t capacity() const;
    void insert (int value, size_t index);
    size_t lookup(size_t index) const;
    size_t pop();
    void push(int value);
    size_t remove(size_t index);
    
    friend ostream& operator <<(ostream& ostr, const FibVec& rhs);
};
//care