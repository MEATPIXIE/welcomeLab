#include "Person.h"

Person::Person(std::string name, Gender gender, Person* mother, Person* father){
    myName = name;
    myGender = gender;
    myMom = mother;
    myDad = father;
    if(myMom != NULL){
        myMom->myKids.insert({this});
    }
    if(myDad != NULL){
        myDad->myKids.insert({this});
    }
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



std::set<Person*> Person::ancestors(PMod pmod){
    std::set<Person*> empty = {};
    return empty;
}
std::set<Person*> Person::aunts(PMod pmod, SMod smod){
    std::set<Person*> empty = {};
    return empty;
}
std::set<Person*> Person::brothers(PMod pmod, SMod smod){
    std::set<Person*> empty = {};
    return empty;
}

std::set<Person*> Person::children() {
    return myKids;
}

std::set<Person*> Person::cousins(PMod pmod, SMod smod){
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

std::set<Person*> Person::descendants(){
    std::set<Person*> empty = {};
    return empty;
}
std::set<Person*> Person::grandchildren(){
    std::set<Person*> grandchild = {};
    std::set<Person*> child = children();
    for(auto itr = child.begin(); itr != child.end(); itr++){
        grandchild.insert(*itr);
    }
    return grandchild;
}
std::set<Person*> Person::granddaughters(){
    std::set<Person*> granddaughter = {};
    std::set<Person*> gChild = grandchildren();
    for(auto itr = gChild.begin(); itr != gChild.end(); itr++){
        if ((*itr)->gender() == Gender::FEMALE){
            granddaughter.insert(*itr);
        }
    }
    return granddaughter;
}


std::set<Person*> Person::grandfathers(PMod pmod){
    std::set<Person*> grandfather = {};
    std::set<Person*> gParent = parents();
    for(auto itr = gParent.begin(); itr != gParent.end(); itr++){
        if ((*itr)->gender() == Gender::MALE){
                grandfather.insert(*itr);
        }
    }
    return grandfather;
}
std::set<Person*> Person::grandmothers(PMod pmod){
    std::set<Person*> grandmother = {};
    std::set<Person*> gParent = grandparents();
    for(auto itr = gParent.begin(); itr != gParent.end(); itr++){
        if ((*itr)->gender() == Gender::FEMALE){
                grandmother.insert(*itr);
        }
    }
    return grandmother;
}
std::set<Person*> Person::grandparents(PMod pmod){
    std::set<Person*> grandparent = {};
    std::set<Person*> parent = parents();
    for(auto itr = parent.begin(); itr != parent.end(); itr++){
        parent.insert(*itr);
    }
    return grandparent;
}



std::set<Person*> Person::grandsons(){
    std::set<Person*> grandson = {};
    std::set<Person*> gChild = grandchildren();
    for(auto itr = gChild.begin(); itr != gChild.end(); itr++){
        if ((*itr)->gender() == Gender::MALE){
            grandson.insert(*itr);
        }
    }
    return grandson;
}
std::set<Person*> Person::nephews(PMod pmod, SMod smod){
    std::set<Person*> empty = {};
    return empty;
}
std::set<Person*> Person::nieces(PMod pmod, SMod smod){
    std::set<Person*> empty = {};
    return empty;
}

std::set<Person*> Person::parents(PMod pmod){
    std::set<Person*> parents = {};
    if (pmod == PMod::PATERNAL && myDad != NULL){
        parents.insert({myDad});
    }else if (pmod == PMod::MATERNAL && myMom != NULL){
        parents.insert({myMom});
    }else if (pmod == PMod::ANY){
        if (myDad != NULL){
            parents.insert({myDad});
        }
        if (myMom != NULL){
            parents.insert({myMom});
        }
    }
    return parents;
}

std::set<Person*> Person::siblings(PMod pmod, SMod smod){
    std::set<Person*> empty = {};
    return empty;
}
std::set<Person*> Person::sisters(PMod pmod, SMod smod){
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

std::set<Person*> Person::uncles(PMod pmod, SMod smod){
    std::set<Person*> empty = {};
    return empty;
}
