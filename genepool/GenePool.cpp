#include "GenePool.h"

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
    for(std::map<std::string, Person*>::iterator itr = pool.begin(); itr != pool.end(); itr++){
        delete itr->second;
    }
}
Person* GenePool::find(const std::string& name) const{
    auto itr = pool.find(name);
    if (pool.find(name) == pool.end()){
        return NULL;
    }else{
        return itr->second;
    }
}
