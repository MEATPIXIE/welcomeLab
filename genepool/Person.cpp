#include "Person.h"
//#include "GenePool.h"


Person::Person(std::string name, std::string gender, Person* mother, Person* father){
    myName = name;
    if(gender == "male"){
        myGender = Gender::MALE;
    }else if(gender == "female"){
        myGender = Gender::FEMALE;
    }
    myMom = mother;
    myDad = father;
}
const std::string& Person::name() const{
    return this->myName;
}
Gender Person::gender() const{
    return this->myGender;
}
Person* Person::mother(){
    return myMom;
}
Person* Person::father(){
    return myDad;
}


std::set<Person*> ancestors(PMod pmod = PMod::ANY){
    std::set<Person*> empty = {};
    return empty;
}
std::set<Person*> aunts(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    std::set<Person*> empty = {};
    return empty;
}
std::set<Person*> brothers(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    std::set<Person*> empty = {};
    return empty;
}
std::set<Person*> children(){
    std::set<Person*> empty = {};
    return empty;
    //return this->myKids;
}
std::set<Person*> cousins(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    std::set<Person*> empty = {};
    return empty;
}
std::set<Person*> daughters(){
    std::set<Person*> empty = {};
    /*
    for(int i = 0; i < myKids.size(); i++){
        if(myKids[i].gender() == Gender::FEMALE){
            empty.insert(itr);
        }
    }
    */
    return empty;
}
std::set<Person*> descendants(){
    std::set<Person*> empty = {};
    return empty;
}
std::set<Person*> grandchildren(){
    std::set<Person*> empty = {};
    return empty;
}
std::set<Person*> granddaughters(){
    std::set<Person*> empty = {};
    return empty;
}
std::set<Person*> grandfathers(PMod pmod = PMod::ANY){
    std::set<Person*> empty = {};
    return empty;
}
std::set<Person*> grandmothers(PMod pmod = PMod::ANY){
    std::set<Person*> empty = {};
    return empty;
}
std::set<Person*> grandparents(PMod pmod = PMod::ANY){
    std::set<Person*> empty = {};
    return empty;
}
std::set<Person*> grandsons(){
    std::set<Person*> empty = {};
    return empty;
}
std::set<Person*> nephews(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    std::set<Person*> empty = {};
    return empty;
}
std::set<Person*> nieces(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    std::set<Person*> empty = {};
    return empty;
}
std::set<Person*> parents(PMod pmod = PMod::ANY){
    std::set<Person*> empty = {};
    return empty;
}
std::set<Person*> siblings(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    std::set<Person*> empty = {};
    return empty;
}
std::set<Person*> sisters(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    std::set<Person*> empty = {};
    return empty;
}
std::set<Person*> sons(){
    std::set<Person*> empty = {};
    /*
    for(auto itr = pool.begin(); itr != pool.end(); itr++){
        for(int i = 0; i < myKids.size(); i++){
            if(myKids[i].gender() == Gender::MALE){
                empty.insert(itr);
            }
        }
    }
    */
    return empty;
}
std::set<Person*> uncles(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    std::set<Person*> empty = {};
    return empty;
}
