
#include "StarMap.h"
#include "Helpers.h"


StarMap::StarMap(std::istream& stream){
    theUniverse = new std::vector<Star>;
    int count = 1;
    double x, y, z;

    while(stream >> x >> y >> z){
        Star aStar;
        
        aStar.x = x;
        aStar.y = y;
        aStar.z = z;
        aStar.id = count;
        theUniverse->push_back(aStar);
        
        count++;
    }
}

StarMap::~StarMap(){
    delete theUniverse;
}


StarMap* StarMap::create(std::istream& stream) {
  // This default implementation will probably do what you want.
  // If you use a different constructor, you'll need to change it.
  return new StarMap(stream);
}


std::vector<Star> StarMap::find(size_t n, float x, float y, float z){
    
    Heap distanceStars = Heap(n);
    //std::vector<Star> mine;
    for(Star estrella : *theUniverse){
        float distance = sqrt(((estrella.x - x) * (estrella.x - x)) + ((estrella.y - y) * (estrella.y - y)) + ((estrella.z - z) * (estrella.z - z)));//distanceFrom(x, y, z);
        if (distanceStars.capacity() != distanceStars.count()){
            distanceStars.push(estrella, distance); 
        }else if (distance < distanceStars.top().distance){
            distanceStars.pushpop(estrella, distance);
        }
    }
    
    while(distanceStars.count() != 0){
        mine.push_back(distanceStars.pop().star);
    }
    reverse(mine.begin(), mine.end());

    return mine;
}
