#include "Faculty.h"
#include <iostream>
#include <string>


using namespace std;

Faculty::Faculty(){
    // constructor
}

Faculty::~Faculty(){
    // constructor
}

Faculty::Faculty(int ID, string name, string level, string dept) {
    id = ID;
    name = name;
    level = level;
    department = dept;
}

void Faculty::setName(string name) {
    name = name;
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

void Faculty::setLevel(string level){
    level = level;
}
string Faculty::getLevel(){
    return level;
}

void Faculty::setDept(string dept){
    department = dept;
}
string Faculty::getDept(){
    return department;
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