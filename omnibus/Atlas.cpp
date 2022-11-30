#include "Atlas.h"

Atlas::Atlas(std::istream& stream){
}

Atlas::~Atlas(){
}

Atlas* Atlas::create(std::istream& stream) {
  // This default implementation will probably do what you want.
  // If you use a different constructor, you'll need to change it.
  return new Atlas(stream);
}
