#include <iostream>
using namespace std;

class FibVec{
private: 
    size_t* mData;
    size_t mCount;
    size_t mCapacity;
    int degree;
public:
    FibVec();
    ~FibVec();
    size_t count() const;
    size_t capacity() const;
    void insert (int value, size_t index);
    size_t lookup(size_t index) const;
    void pop();
    void push(int value);
    size_t remove(size_t index);
    
    int fibo(int degree); 
    friend ostream& operator <<(ostream& ostr, const FibVec& rhs);
}; 
//newl