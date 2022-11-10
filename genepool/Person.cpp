#include "Person.h"
using namespace std;


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
    if(pmod == PMod::MATERNAL){
        if(myMom != NULL){
            empty.insert(myMom);
            auto mancs = myMom->ancestors();
            for(auto itr = mancs.begin(); itr != mancs.end(); itr++){
                empty.insert(*itr);
            }
        }
    }else if(pmod == PMod::PATERNAL){
        if(myDad != NULL){
            empty.insert(myDad);
            auto pancs = myDad->ancestors();
            for(auto itr = pancs.begin(); itr != pancs.end(); itr++){
                empty.insert(*itr);
            }
        }
    }else{
        if(myMom != NULL){
            empty.insert(myMom);
            auto mancs = myMom->ancestors();
            for(auto itr = mancs.begin(); itr != mancs.end(); itr++){
                empty.insert(*itr);
            }
        }if(myDad != NULL){
            empty.insert(myDad);
            auto pancs = myDad->ancestors();
            for(auto itr = pancs.begin(); itr != pancs.end(); itr++){
                empty.insert(*itr);
            }
        }
    }
    return empty;
}
std::set<Person*> Person::descendants(){
    std::set<Person*> desk = {};
    for(Person* myKid: children()){
        desk.insert(myKid);
        for(Person* des: myKid->descendants()){
            desk.insert(des);
        }
    }
    return desk;
}
std::set<Person*> Person::children() {
    return myKids;
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

std::set<Person*> Person::grandfathers(PMod pmod){
    std::set<Person*> grandfather = {};
    if((pmod == PMod::MATERNAL || pmod == PMod::ANY) && myMom){
        if(myMom -> father()){
            grandfather.insert(myMom -> father());
        }
    }if((pmod == PMod::PATERNAL || pmod == PMod::ANY) && myDad){
        if(myDad -> father()){
            grandfather.insert(myDad -> father());
        }
    }
    return grandfather;
}
std::set<Person*> Person::grandmothers(PMod pmod){
    std::set<Person*> grandmother = {};
    if((pmod == PMod::MATERNAL || pmod == PMod::ANY) && myMom){
        if(myMom -> mother()){
            grandmother.insert(myMom -> mother());
        }
    }if((pmod == PMod::PATERNAL || pmod == PMod::ANY) && myDad){
        if(myDad -> mother()){
            grandmother.insert(myDad -> mother());
        }
    }
    return grandmother;
}
std::set<Person*> Person::grandparents(PMod pmod){
    std::set<Person*> grandparent = {};
    if((pmod == PMod::MATERNAL || pmod == PMod::ANY) && myMom){
        if(myMom -> father()){
            grandparent.insert(myMom -> father());
        }
        if(myMom -> mother()){
            grandparent.insert(myMom -> mother());
        }
    }if((pmod == PMod::PATERNAL || pmod == PMod::ANY) && myDad){
        if(myDad -> father()){
            grandparent.insert(myDad -> father());
        }
        if(myDad -> mother()){
            grandparent.insert(myDad -> mother());
        }
    }
    return grandparent;
}

std::set<Person*> Person::grandchildren(){
    std::set<Person*> grandchild = {};
    auto child = children();
    for(auto itr = child.begin(); itr != child.end(); itr++){
        grandchild.merge((*itr)->children());
        //grandchild.insert(*itr);
    }
    return grandchild;
}
std::set<Person*> Person::granddaughters(){
    std::set<Person*> granddaughter = {};
    auto gChild = grandchildren();
    for(auto itr = gChild.begin(); itr != gChild.end(); itr++){
        if ((*itr)->gender() == Gender::FEMALE){
            granddaughter.insert(*itr);
        }
    }
    return granddaughter;
}
std::set<Person*> Person::grandsons(){
    std::set<Person*> grandson = {};
    auto gChild = grandchildren();
    for(auto itr = gChild.begin(); itr != gChild.end(); itr++){
        if ((*itr)->gender() == Gender::MALE){
            grandson.insert(*itr);
        }
    }
    return grandson;
}
std::set<Person*> Person::siblings(PMod pmod, SMod smod){
    std::set<Person*> empty = {}; 
    std::set<Person*> sibling = {}; 
    for (Person* pair: parents(pmod)){
        empty.merge(pair->children());
        //empty.insert(pair);
    }
    for (Person* kid:empty){
        if (kid -> name() != this->name()){
            switch(smod){
                case SMod::FULL:
                if(((kid->myDad != NULL) && (kid->myMom != NULL)) && ((this->myDad != NULL) && (this->myMom != NULL))){
                    if((kid->myDad->name() == this->myDad->name()) && (kid->myMom->name() == this->myMom->name())){
                        sibling.insert(kid);
                    }
                }
                break;
                case SMod::HALF:
                if(kid->myMom != NULL){
                    if((kid->myMom->name() == this->myMom->name()) && (kid->myDad == NULL || kid->myDad->name() != this->myDad->name())){
                        sibling.insert(kid);
                    }
                }
                if(kid->myDad != NULL){
                    if((kid->myDad->name() == this->myDad->name()) && (kid->myMom == NULL || kid->myMom->name() != this->myMom->name())){
                        sibling.insert(kid);
                    }
                }
                break;
                
                default:
                sibling.insert(kid);
                break;
            }
        }
    }
    return sibling;
}
std::set<Person*> Person::brothers(PMod pmod, SMod smod){
    std::set<Person*> empty = siblings(pmod, smod);
    std::set<Person*> brother = {};
    for(auto itr = empty.begin(); itr != empty.end(); itr++){
        if ((*itr)->gender() == Gender::MALE){
            brother.insert(*itr);
        }
    }
    return brother;
}
std::set<Person*> Person::sisters(PMod pmod, SMod smod){
    std::set<Person*> empty = siblings(pmod, smod);
    std::set<Person*> sister = {};
    for(auto itr = empty.begin(); itr != empty.end(); itr++){
        if ((*itr)->gender() == Gender::FEMALE){
            sister.insert(*itr);
        }
    }
    return sister;
}
std::set<Person*> Person::aunts(PMod pmod, SMod smod){
    std::set<Person*> aunt = {};
    //std::set<Person*> empty = {};
    for(Person* pair:parents(pmod)){
        aunt.merge(pair->sisters(PMod::ANY, smod));
        //aunt.insert(pair);
    }
    return aunt;
}
std::set<Person*> Person::uncles(PMod pmod, SMod smod){
    std::set<Person*> uncle = {};
    //std::set<Person*> empty = {};
    for(Person* pair:parents(pmod)){
        uncle.merge(pair->brothers(PMod::ANY, smod));
        //uncle.insert(pair);
    }
    return uncle;
}
std::set<Person*> Person::cousins(PMod pmod, SMod smod){
    std::set<Person*> cousin = {};
    std::set<Person*> empty = {};
    for(Person* pair:parents(pmod)){
        empty.merge(pair->siblings(PMod::ANY, smod));
        //empty.insert(pair);
    }
    for(auto itr = empty.begin(); itr != empty.end(); itr++){
        cousin.merge((*itr)->children());
        //cousin.insert(*itr);
    }
    return cousin;
}

// done ^ done ^ done ^ done ^ done ^ done ^ done ^ done ^ done ^ done

std::set<Person*> Person::nephews(PMod pmod, SMod smod){
    std::set<Person*> nephew = {};
    for(Person* pair:siblings(pmod, smod)){
        nephew.merge(pair->sons());
        //uncle.insert(pair);
    }
    return nephew;
}
std::set<Person*> Person::nieces(PMod pmod, SMod smod){
    std::set<Person*> niece = {};
    for(Person* pair:siblings(pmod, smod)){
        niece.merge(pair->daughters());
        //uncle.insert(pair);
    }
    return niece;
}

