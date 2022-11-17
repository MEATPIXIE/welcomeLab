
#ifndef HELPERS_H
#define HELPERS_H

#include <cstddef>
#include <string>
#include <algorithm>

#include "Star.h"

class Heap {
public:
    struct Entry {
        Star star;
        float       distance;
    };

private:
    Entry* mData;
    size_t mCapacity;
    size_t mCount;

public:
    Heap(size_t capacity);
    Heap(const Heap& other);
    Heap(Heap&& other);
    ~Heap();

    size_t       capacity() const;
    size_t       count() const;
    const Entry& lookup(size_t index) const;
    Entry        pop();
    Entry        pushpop(const Star& value, float score);
    void         push(const Star& value, float score);
    const Entry& top() const;
};

double distanceFrom(double a, double b, double c);


#endif
