#include "Faculty.h"
#include <iostream>
#include <sstream>
#include <iostream>
#include <string>



using namespace std;

Faculty::Faculty(){
    // constructor
}

Faculty::~Faculty(){
    // constructor
}

Faculty::Faculty(int ID, string n, string l, string dept) {
    id = ID;
    name = n;
    level = l;
    department = dept;
}

void Faculty::setName(string n) {
    name = n;
}

string Faculty::getName(){
    return name;
}

void Faculty::setID(int ID){
    id = ID;
}
int Faculty::getId(){
    return id;
}

void Faculty::setLevel(string l){
    level = l;
}
string Faculty::getLevel(){
    return level;
}

void Faculty::setDept(string d){
    department = d;
}
string Faculty::getDept(){
    return department;
}

// List<int> Faculty::showAdvisees(){
//     return advisees();
// }

void Faculty::addAdvisee(int studentId){
    advisees->insertBack(studentId);
}

bool Faculty::removeAdvisee(int studentId){
    if (!advisees->find(studentId)) {
        return false;
    }
    advisees->remove(studentId);
    return true;
}

void Faculty::getAdvisees(string adv) {
    stringstream s(adv); // to read in
    string tosave = "";

    bool didFind = false;
    while(!didFind) {
        int stID = -1;
        int id;
        s >> id;
        stID = id;
        if(s){
            addAdvisee(stID); // adds advisee
        }
        else {
            break;
        }
    }
    didFind = true;
    tosave = "";

}

// overloaded operators
bool Faculty::operator!=(Faculty faculty)
{
    return (getId() != faculty.getId());
}
bool Faculty::operator==(Faculty faculty)
{
    return (getId() == faculty.getId());
}
bool Faculty::operator<(Faculty faculty)
{
    return (getId() < faculty.getId());
}
bool Faculty::operator>(Faculty faculty)
{
    return (getId() > faculty.getId());
}
bool Faculty::operator>=(Faculty faculty)
{
    return (getId() >= faculty.getId());
}
