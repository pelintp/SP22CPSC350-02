#ifndef FACULTY_H
#define FACULTY_H
#include <iostream>
#include <stdio.h>
#include "List.h"
#include <string>


//#include "LinkedList.h"


using namespace std;

class Faculty {
    public:
        Faculty();
        Faculty(int ID, string n, string l, string dept);
        // overloaded constructor
        ~Faculty();

        void setName(string n);
        string getName();

        void setID(int ID);
        int getId();

        void setLevel(string l);
        string getLevel();

        void setDept(string d);
        string getDept();

        // for advisees
        List<int> *advisees = new List<int>();
        // for advisees
        void addAdvisee(int studentID);
        bool removeAdvisee(int studentId);
        void getAdvisees(string adv);
        // string printAdvisees

        // overloaded constructors
        // overloaded operators here
        bool operator!=(Faculty faculty);
        bool operator>(Faculty faculty);
        bool operator==(Faculty faculty);
        bool operator<(Faculty faculty);
        bool operator>=(Faculty faculty);


    private:
        int id;
        string name;
        string level;
        string department;

};

#endif
