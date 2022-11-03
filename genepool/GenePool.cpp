#include "GenePool.h"
//#include <string>

GenePool::GenePool(std::istream& stream){
    std::string line;
    while(getline(stream, line)){
        //istringstream ss(line);
        if(line == "#" || line == "\n"){
            continue;
        }
    }
}
GenePool::~GenePool(){
    for(std::map<string, Person*>::iterator itr = pool.begin(); itr != pool.end(); itr++){
        delete itr->second;
    }
}
Person* GenePool::find(const std::string& name) const{
    /*
    for(std::map<string, Person*>::iterator itr = pool.begin(); itr != pool.end(); itr++){
        if(pool[i].myName == name){
            itr = pool.find(name);
            return itr;
        }else{
            return nullptr;
        }  
    }
    */
    return nullptr;
}
