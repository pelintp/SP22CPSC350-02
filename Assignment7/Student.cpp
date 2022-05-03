#include "Student.h"
#include <iostream>
#include <stdio.h>
#include <string>



using namespace std;

Student::Student(){
    stID = -1;
    name = "NA";
    level = "NA";
    major = "NA";
    gpa = -1;
    advisorID = -1;
}

// overloaded constructor
Student::Student(int ID, string NAME, string lvl, string mjr, double GPA, int advisor){
    stID = ID;
    name = NAME;
    level = lvl;
    major = mjr;
    gpa = GPA;
    advisorID = advisor;
}

Student::~Student(){
    // delete ?
}

void Student::setName(string NAME){
    name = NAME;
    // cout << name << "inside setter" << endl;
    
}

string Student::getName(){
    return name;
}

void Student::setID(int ID){
    stID = ID;
}

int Student::getId(){
    return stID;
}

void Student::setLevel(string lvl){
    level = lvl;
}

string Student::getLevel(){
    return level;
}

void Student::setMajor(string mjr){
    major = mjr;
}

string Student::getMajor(){
    return major;
}

void Student::setGPA(double GPA){
    gpa = GPA;
}

double Student::getGPA(){
    return gpa;
}

void Student::setAdvisor(int advisorID){
    advisorID = advisorID;
}

int Student::getAdvisor(){
    return advisorID;
}

// overloaded operators
bool Student::operator!=(Student student)
{
    return (getId() != student.getId());
}
bool Student::operator==(Student student)
{
    return (getId() == student.getId());
}
bool Student::operator<(Student student)
{
    return (getId() < student.getId());
}
bool Student::operator>(Student student)
{
    return (getId() > student.getId());
}
bool Student::operator>=(Student student)
{
    return (getId() >= student.getId());
}


