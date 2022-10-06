#include <iostream>
using namespace std;

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
    int remove(size_t index);
    FibVec slice(int index, int count);
    
    
    friend ostream& operator <<(ostream& ostr, const FibVec& rhs);
}; 
