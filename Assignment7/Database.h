#ifndef Database_h
#define Database_h
#include <string>
#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include <string>


using namespace std;

class Database{
    public:
        Database();
        ~Database();

        void Simulation();

        void printStudents(); // function 1
        void printFaculty(); // function 2

        void displayStudentInfo(int id); // function 3
        void displayFacultyInfo(int id); // function 4

        void displayAdvisor(int stID); // function 5
        void displayFacultyAdvisees(int facID); // function 6

        void addNewStudent(int id, string name, string level, string major, double gpa, int advisor); // function 7
        void deleteStudent(int id); // function 8
        
        void addNewFaculty(int id, string name, string level, string department); // function 9
        void deleteFaculty(int id); // function 10

        void changeAdvisor(int stID, int newFacID); // function 11
        void removeAdvisee(int facID, int stID); // function 12

        void rollback(); // function 13
        int exit(); // function 14

        void startProgram();
        void saveInfoFaculty();
        void saveInfoStudents();
        string facultyToPrint(TreeNode<Faculty> *node);
        string studentToPrint(TreeNode<Student> *node);

    private:
        BST<Faculty> facultyTree;   
        BST<Student> studentTree;

};

#endif