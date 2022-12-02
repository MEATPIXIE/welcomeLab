
#include "Atlas.h"
#include <sstream>
#include <iomanip>

Atlas::Atlas(std::istream& stream){
    std::string line;
    std::string id;
    std::string stationName;
    std::string stringNum;
    int intNum;
    
    std::string lineName;

    while(getline(stream, line)){
        std::istringstream newStream(line);
        if(line[0] == '#' || line.empty()){
            continue;
        }
        
        istringstream leer(line);
        leer >> id;
        Station* newStation = new Station();
        newStation->stationName = id;
        
        if (id[0] == '-'){
            leer >> stringNum;
            intNum = stoi(stringNum);
            leer >> std::ws;
            
            getline(leer, line);
            
            newStation->transitLines.push_back(lineName);
            newStation->neighbor.time = intNum;
        }
    }
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
