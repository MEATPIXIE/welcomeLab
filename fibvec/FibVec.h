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
    void insert (int value, size_t index);
    int lookup(size_t index) const;
    void pop();
    void push(int value);
    int remove(size_t index);
    FibVec slice(size_t index, size_t count) const;
    
    
    friend ostream& operator <<(ostream& ostr, const FibVec& rhs);
}; 
