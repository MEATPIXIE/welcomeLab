
#include "StarMap.h"



StarMap::StarMap(std::istream& stream){
}

StarMap::~StarMap(){
    /*
    for(std::map<std::string, Person*>::iterator itr = pool.begin(); itr != pool.end(); itr++){
        delete itr->second;
    }
    */
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
