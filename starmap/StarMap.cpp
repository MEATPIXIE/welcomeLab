
#include "StarMap.h"


StarMap::StarMap(std::istream& stream){
    int count = 1;
    std::string x, y, z;

    while(stream >> x >> y >> z){
        Star aStar;
        
        aStar.x = std::stof(x);
        aStar.y = std::stof(y);
        aStar.z = std::stof(z);
        aStar.id = count;
        myStars->push_back(aStar);
        
        count++;
    }
}

StarMap::~StarMap(){
    delete myStars;
}


StarMap* StarMap::create(std::istream& stream) {
  // This default implementation will probably do what you want.
  // If you use a different constructor, you'll need to change it.
  return new StarMap(stream);
}

std::vector<Star> StarMap::find(size_t n, float x, float y, float z){
    std::vector<Star> mine;
    return mine;
}
