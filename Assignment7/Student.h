#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>


using namespace std;

class Student{
    public:
        Student();
        Student(int ID, string NAME, string lvl, string mjr, double GPA, int advisor); // overloaded constructor
        ~Student();

        // overloaded operators here
        bool operator!=(Student student);
        bool operator>(Student student);
        bool operator==(Student student);
        bool operator<(Student student);
        bool operator>=(Student student);


        // gets and sets
        void setName(string NAME);
        string getName();

        void setID(int ID);
        int getId();

        void setLevel(string lvl);
        string getLevel();

        void setMajor(string mjr);
        string getMajor();

        void setGPA(double GPA);
        double getGPA();

        void setAdvisor(int advisorID);
        int getAdvisor();



    private:
        int stID;
        string name;
        string level;
        string major;
        double gpa;
        int advisorID;
};

#endif
