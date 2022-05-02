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
Student::Student(int ID, string name, string level, string major, double GPA, int advisor){
    stID = ID;
    name = name;
    level = level;
    major = major;
    gpa = GPA;
    advisorID = advisor;
}

Student::~Student(){
    // delete ?
}

void Student::setName(string name){
    name = name;
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

void Student::setLevel(string level){
    level = level;
}

string Student::getLevel(){
    return level;
}

void Student::setMajor(string major){
    major = major;
}

string Student::getMajor(){
    return major;
}

void Student::setGPA(double gpa){
    gpa = gpa;
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


