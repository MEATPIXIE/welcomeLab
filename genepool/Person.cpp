#include "Person.h"


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

std::set<Person*> Person::children() {
    return this->myKids;
}
std::set<Person*> cousins(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    std::set<Person*> empty = {};
    return empty;
}
std::set<Person*> Person::daughters(){
    std::set<Person*> daughter = {};
    std::set<Person*> child = children();
    for(auto itr = child.begin(); itr != child.end(); itr++){
        if ((*itr)->gender() == Gender::FEMALE){
                daughter.insert(*itr);
        }
    }
    return daughter;
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
std::set<Person*> Person::sons(){
    std::set<Person*> son = {};
    std::set<Person*> child = children();
    for(auto itr = child.begin(); itr != child.end(); itr++){
        if ((*itr)->gender() == Gender::MALE){
                son.insert(*itr);
        }
    }
    return son;
}
std::set<Person*> uncles(PMod pmod = PMod::ANY, SMod smod = SMod::ANY){
    std::set<Person*> empty = {};
    return empty;
}
