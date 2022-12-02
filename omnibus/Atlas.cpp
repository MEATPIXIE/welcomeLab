#include "Atlas.h"

Atlas::Atlas(std::istream& stream){
    int count = 0;
    count++;
}

Atlas::~Atlas(){
  for(std::map<std::string, Station*>::iterator itr = atlas.begin(); itr != atlas.end(); itr++){
    delete itr->second;
  }
}

Atlas* Atlas::create(std::istream& stream) {
  // This default implementation will probably do what you want.
  // If you use a different constructor, you'll need to change it.
  return new Atlas(stream);
}

Trip Atlas::route(const std::string& src, const std::string& dst){
    Trip mine;
    return mine;
}
