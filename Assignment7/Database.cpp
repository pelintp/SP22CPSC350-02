#include <stdio.h>
#include "Database.h"
#include <fstream>
#include <iostream>
#include <string>

Database::Database(){
}

Database::~Database(){
    // destructor
}



void Database::printStudents(){
    //studentTree.inOrder(true, studentTree.getRoot());
    studentTree.studentInOrder(studentTree.getRoot());
}

void Database::printFaculty(){
    // facultyTree.inOrder(true, facultyTree.getRoot());
    facultyTree.facultyInOrder(facultyTree.getRoot());

}

void Database::displayStudentInfo(int id){
    // 
}

void Database::displayFacultyInfo(int id){
    //
}

void Database::addNewStudent(int id, string name, string level, string major, double gpa, int advisor){
    Student student(id, name, level, major, gpa, advisor);

    studentTree.insert(student);
}

void Database::addNewFaculty(int id, string name, string level, string department){
    Faculty faculty(id, name, level, department);

    facultyTree.insert(faculty);
}

void Database::deleteStudent(int id) {
    studentTree.remove(id);
}
void Database::deleteFaculty(int id) {
    facultyTree.remove(id);
}

void Database::startProgram() {
    // Student student;
    // Faculty faculty;
    string line;
    string l1;
    ifstream file("facultyTable.txt");
    if (!file.is_open()) {
        cout << "Could not open file" << endl;
        //exit();
    } 
    else {
        while(getline(file, line)) {
            Faculty faculty;
            faculty.setID(stoi(line));
            getline(file, line);
            faculty.setName(line);
            getline(file, line);
            faculty.setLevel(line);
            getline(file, line);
            faculty.setDept(line);
            facultyTree.insert(faculty);
        }
    }
    file.close();

    ifstream stFile("studentTable.txt");
    
    if (!stFile.is_open())
    {
        cout << "Could not open file" << endl;
    }
    else {
        while(getline(stFile, line)) {
            Student student;
            student.setID(stoi(line));
            getline(stFile, line);
            student.setName(line);
            getline(stFile, line);
            student.setLevel(line);
            getline(stFile, line);
            student.setMajor(line);
            getline(stFile, line);
            student.setGPA(stoi(line));
            getline(stFile, line);
            student.setAdvisor(stoi(line));

            studentTree.insert(student);
        }
    }
    file.close();
}

void Database::Simulation() {
    bool exit = false;
    string input;
    


    do {
        cout << "Welcome to the student and faculty databases. Please select a number: \n" << endl;
        cout << "1. Print all students and their info by ascending ID" << endl;
        cout << "2. Print all faculty and their info by ascending ID" << endl;
        cout << "3. Find and display student information given the students id" << endl;
        cout << "4. Find and display faculty information given the faculty id" << endl;
        cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
        cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
        cout << "7. Add a new student" << endl;
        cout << "8. Delete a student given the id" << endl;
        cout << "9. Add a new faculty member" << endl;
        cout << "10. Delete a faculty member given the id." << endl;
        cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
        cout << "12. Remove an advisee from a faculty member given the ids" << endl;
        cout << "13. Rollback" << endl;
        cout << "14. Exit" << endl;

        cin >> input;

        if (input == "1"){
            printStudents();
        }
        else if (input == "2"){
            printFaculty();
        }
        else if (input == "3"){
            int stID = -1;
            cout << "Enter student ID" << endl;
            cin >> stID;
            //displayStudentInfo(stID);

            Student student;
            student.setID(stID); 
            studentTree.printStudentInfo(student);
        }
        else if (input == "4"){
            int facultyID = -1;

            cout << "Enter faculty ID" << endl;
            cin >> facultyID;
            // displayFacultyInfo(facultyID);

            Faculty faculty;
            faculty.setID(facultyID);
            cout << "testing id: " << faculty.getId() << endl;
            facultyTree.printFacultyInfo(faculty);
        }
        else if (input == "5"){
            // int stID;
            // cout << "Enter student ID" << endl;
            // cin >> stID;
            // cout << "Looking up advisor..." << endl;
            // cout << "Advisor for " << stID << endl;
            // displayAdvisor(stID);
        }
        else if (input == "6"){
            // int facultyID;

            // cout << "Enter faculty ID" << endl;
            // cin >> facultyID;
            // displayFacultyAdvisees(facultyID);
        }
        else if (input == "7"){
            int newStID;
            string firstName;
            string secondName;
            string level;
            string major;
            double gpa;
            int advisor;

            bool isUnique = false;
            while (!isUnique)
            {
                cout << "Enter a valid ID for new student" << endl;
                cin >> newStID;

                Student st;
                st.setID(newStID);

                if(studentTree.containsID(st.getId())){
                    cout << "Invalid ID. Try Again." << endl;
                    
                }else{
                    isUnique = true;
                }
            }

            cout << "Enter first name for new student" << endl;
            cin >> firstName;
            cout << "Enter second name for new student" << endl;
            cin >> secondName;
            cout << "Enter level for new student" << endl;
            cin >> level;
            cout << "Enter major for new student" << endl;
            cin >> major;
            cout << "Enter gpa for new student" << endl;
            cin >> gpa;
            cout << "Enter advisor for new student" << endl;
            cin >> advisor;

            string name = firstName + " " + secondName;
            addNewStudent(newStID, name, level, major, gpa, advisor);
        }
        else if (input == "8"){
            int stID;
            

            bool contains = false;
            while (!contains)
            {
                cout << "Enter ID of student to delete" << endl;
                cin >> stID;

                Student student;
                student.setID(stID);

                if(facultyTree.containsID(student.getId())){
                    cout << "Member does not exist. Try Again" << endl;
                    
                }else{
                    contains = true;
                }
            }
            deleteStudent(stID);
            
        }
        else if (input == "9"){
            int newfacultyID;
            string firstName;
            string secondName;
            string level;
            string department;

            bool isUnique = false;
            while (!isUnique)
            {
                cout << "Enter a valid ID for new faculty" << endl;
                cin >> newfacultyID;

                Faculty faculty;
                faculty.setID(newfacultyID);

                if(facultyTree.containsID(faculty.getId())){
                    cout << "Invalid ID. Try Again" << endl;
                    
                }else{
                    isUnique = true;
                }
            }

            cout << "Enter first name for new faculty" << endl;
            cin >> firstName;
            cout << "Enter second name for new faculty" << endl;
            cin >> secondName;
            cout << "Enter level for new faculty" << endl;
            cin >> level;
            cout << "Enter department for new faculty" << endl;
            cin >> department;
            

            string name = firstName + " " + secondName;
            addNewFaculty(newfacultyID, name, level, department);
        }
        else if (input == "10"){
            int facultyID;
            bool contains = false;
            while (!contains)
            {
                cout << "Enter ID of faculty to delete" << endl;
                cin >> facultyID;

                Faculty faculty;
                faculty.setID(facultyID);

                // cout << "fac id: " << faculty.getId() << endl;

                if(!facultyTree.containsID(faculty.getId())){
                    cout << "Member does not exist. Try Again" << endl;
                    
                }else{
                    contains = true;
                }
            }
            
            deleteFaculty(facultyID);
        }
        else if (input == "11"){
            // int STUDENTid;
            // int facultyID;

            // cout << "Enter student id: ";
            // cin >> STUDENTid;
            // cout << "Enter faculty id: ";
            // cin >> facultyID;
            // changeAdvisor(STUDENTid, facultyID);
        }
        else if (input == "12"){
        //     int STUDENTid;
        //     int facultyID;

        //     cout << "Enter student id: ";
        //     cin >> STUDENTid;
        //     cout << "Enter faculty id: ";
        //     cin >> facultyID;
        //     removeAdvisee(STUDENTid, facultyID);
        }
        else if (input == "13"){
            // rollback();
        }
        else if (input == "14"){
            // saveInfoFaculty();
            // saveInfoStudents();
            cout << "Goodbye." << endl;
            exit = true;
        }
        else {
            cout << "Invalid input. Try again." << endl;
        }

    } while (!exit);
}

void Database::saveInfoFaculty(){
    ofstream writeFaculty;
    writeFaculty.open("facultyTable.txt");
    


}

// string Database::writeFaculty(TreeNode<Faculty> *node){
//     string toreturn = "";
//     string secondreturn = "";
//     string studentInfo = ""
//     if (node != NULL)
//     {
//         // studentInfo = node->key.getName
//         // toreturn += node->key
//     }
//     else {
//         return "";
//     }
// }

// string Database::writeStudents(TreeNode<Student> *node){
//     string toreturn = "";
//     bool isEmpty = false;
//     if (node != NULL)
//     {
//         return "";
//     }
//     else {
//         return "";
//     }
// }

void Database::saveInfoStudents(){
    // ofstream writeStudents();
}