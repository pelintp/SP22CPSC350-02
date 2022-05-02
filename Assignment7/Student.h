#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>


using namespace std;

class Student{
    public:
        Student();
        Student(int ID, string name, string level, string major, double GPA, int advisor); // overloaded constructor
        ~Student();

        // overloaded operators here
        bool operator!=(Student student);
        bool operator>(Student student);
        bool operator==(Student student);
        bool operator<(Student student);
        bool operator>=(Student student);


        // getters and setters
        void setName(string name);
        string getName();

        void setID(int ID);
        int getId();

        void setLevel(string level);
        string getLevel();

        void setMajor(string major);
        string getMajor();

        void setGPA(double gpa);
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