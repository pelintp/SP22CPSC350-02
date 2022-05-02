#ifndef FACULTY_H
#define FACULTY_H
#include <iostream>
#include <stdio.h>
#include <string>

//#include "LinkedList.h"


using namespace std;

class Faculty {
    public:
        Faculty();
        Faculty(int ID, string name, string level, string dept); // overloaded constructor
        ~Faculty();

        void setName(string name);
        string getName();

        void setID(int ID);
        int getId();

        void setLevel(string level);
        string getLevel();

        void setDept(string dept);
        string getDept();

        //DoublyLinkedList<int> getAdviseeList();


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