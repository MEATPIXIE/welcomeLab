
#include "GenePool.h"
#include <sstream>
using namespace std;

GenePool::GenePool(std::istream& stream){
    
    std::string line;
    std::string nombre;
    std::string genero;
    std::string mamaSeLlama;
    std::string papaSeLlama;
    
    Gender gender;
    Person* mama;
    Person* papa;

    while(getline(stream, line)){
        istringstream leer(line);
        if(line[0] == '#' || line.empty()){
            continue;
        }else{
            getline(leer, nombre, '\t');
            getline(leer, genero, '\t');
            getline(leer, mamaSeLlama, '\t');
            getline(leer, papaSeLlama, '\t');
        }
        
        if(genero == "male"){
            gender = Gender::MALE;
        }else if(genero == "female"){
            gender = Gender::FEMALE;
        }
        
        if(mamaSeLlama == "???"){
            mama = NULL;
        }else{
            mama = find(mamaSeLlama);
        }
        if(papaSeLlama == "???"){
            papa = NULL;
        }else{
            papa = find(papaSeLlama);
        }
        
        Person* person = new Person(nombre, genero, mama, papa);
        pool.insert({nombre, person});
        
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
