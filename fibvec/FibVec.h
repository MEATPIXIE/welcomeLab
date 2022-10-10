#include <iostream>
using namespace std;

class FibVec{
private: 
    int* mData;
    size_t mCount;
    size_t mCapacity;
    int degree;
public:
    FibVec();
    ~FibVec();
    int degre();
    size_t count() const;
    size_t capacity() const;
    void insert (int value, size_t index);
    size_t lookup(size_t index) const;
    size_t pop();
    void push(int value);
    size_t remove(size_t index);
    
    void shrink();
    size_t Fibonacci(size_t n) const; 
    size_t FibResize(size_t count, size_t capacity) const;
    friend ostream& operator <<(ostream& ostr, const FibVec& rhs);
};
//shrink