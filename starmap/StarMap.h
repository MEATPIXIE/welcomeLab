                                                                                                                                                                                                     #ifndef STARMAP_H
#define STARMAP_H

#include "Star.h"

#include <istream>
#include <vector>

class StarMap {
public:
    // Required Class Function
    static StarMap* create(std::istream& stream);

private:
    std::vector<Star>* theUniverse;

public:
    // Constructor & Destructor
    StarMap(std::istream& stream);
    ~StarMap();

    // Required Member Function
    std::vector<Star> find(size_t n, float x, float y, float z);
    

    // Other Member Functions
};

#endif
