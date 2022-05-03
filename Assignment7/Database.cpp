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
    studentTree.studentInOrder(studentTree.getRoot());
}

void Database::printFaculty(){
    facultyTree.facultyInOrder(facultyTree.getRoot());
}

void Database::displayStudentInfo(int id){
}

void Database::displayFacultyInfo(int id){
}

void Database::addNewStudent(int id, string name, string level, string major, double gpa, int advisor){
    Student student(id, name, level, major, gpa, advisor);
    student.setName(name);

    //PRINT  TEST
    //PRINT student.getName()
    //PRINT name

    studentTree.insert(student);
}

void Database::addNewFaculty(int id, string name, string level, string department){
    Faculty faculty(id, name, level, department);
    faculty.setName(name);
    faculty.setDept(department);
    faculty.setLevel(level);

    facultyTree.insert(faculty);
}

void Database::deleteStudent(int id) {
    studentTree.remove(id);
}
void Database::deleteFaculty(int id) {
    facultyTree.remove(id);
}

void Database::startProgram() {
    // student
    // faculty
    string line;
    string l1;
    ifstream file("facultyTable.txt");
    if (!file.is_open()) {
        cout << "Could not open file" << endl;
        //exit

    }
    else {
            cout << "inside" << endl;

        while(getline(file, line)) {
            Faculty faculty;
            faculty.setName(line);
            getline(file, line);
            faculty.setID(stoi(line));
            getline(file, line);

            faculty.setLevel(line);
            getline(file, line);
            faculty.setDept(line);
            getline(file, line);
            facultyTree.insert(faculty);
            TreeNode<Faculty> *current = facultyTree.getRoot();

            // finding faculty member in tree to load advisees
            while(current->key.getId() != faculty.getId()){
                if(faculty.getId() >= current->key.getId()){

                    current = current->right;
                }else{
                    current = current->left;
                }
            }
            current->key.getAdvisees(line);

            l1 = "";
        }
    }
    file.close();
    cout << "pt 1" << endl;
    ifstream stFile("studentTable.txt");

    if (!stFile.is_open())
    {
        //PRINT Could not open file
    }
    else {
        while(getline(stFile, line)) {
            Student student;

            student.setName(line);
            getline(stFile, line);
            student.setID(stoi(line));
            getline(stFile, line);
            student.setLevel(line);
            getline(stFile, line);
            student.setMajor(line);
            getline(stFile, line);
            student.setGPA(stod(line)); // to get double value
            getline(stFile, line);
            student.setAdvisor(stoi(line));

            studentTree.insert(student);
        }
    }
    file.close();
        cout << "pt 2" << endl;

}

void Database::Simulation() {
    bool exit = false;
    string input;
    cout << "pt 3" << endl;

    startProgram();
        cout << "pt 4" << endl;

    do
    {
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
            int stID;

            bool exists = false;
            // checking if id exists
            while (!exists)
            {
                cout << "Enter a valid ID for new student" << endl;
                cin >> stID;

                Student st;
                st.setID(stID);

                if(!studentTree.containsID(st.getId())){
                    cout << "Invalid ID. Try Again." << endl;

                }else{
                    exists = true;
                }
            }

            cout << "Advisor for " << stID << endl;
            displayAdvisor(stID);
        }
        else if (input == "6"){
            // int facultyID;

            // PRINT ENTER FACULTY ID
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

            string name = firstName +" " + secondName;
            // cout << name << " TEST" << endl;
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

                // print fac id

                if(!facultyTree.containsID(faculty.getId())){
                    cout << "Member does not exist. Try Again" << endl;

                }else{
                    contains = true;
                }
            }

            deleteFaculty(facultyID);
        }
        else if (input == "11"){
            int STUDENTid;
            int facultyID;
            bool idExists = false;

            while(!idExists) {
                cout << "Enter student id: ";
                cin >> STUDENTid;

                Student st;
                st.setID(STUDENTid);



                if(!studentTree.containsID(st.getId())){
                    cout << "Invalid ID. Try Again." << endl;

                }else{
                    idExists = true;
                }
            }

            idExists = false;
            while (!idExists)
            {
                cout << "Enter faculty id: ";
                cin >> facultyID;

                Faculty f;
                f.setID(facultyID);



                if(!facultyTree.containsID(f.getId())){
                    cout << "Invalid ID. Try Again." << endl;

                }else{
                    idExists = true;
                }
            }
            changeAdvisor(STUDENTid, facultyID);
        }
        else if (input == "12"){
            int STUDENTid;
            int facultyID;
            bool idExists = false;

            while(!idExists) {
                cout << "Enter student id: ";
                cin >> STUDENTid;

                Student st;
                st.setID(STUDENTid);



                if(!studentTree.containsID(st.getId())){
                    cout << "Invalid ID. Try Again." << endl;

                }else{
                    idExists = true;
                }
            }

            idExists = false;
            while (!idExists)
            {
                cout << "Enter faculty id: ";
                cin >> facultyID;

                Faculty f;
                f.setID(facultyID);



                if(!facultyTree.containsID(f.getId())){
                    cout << "Invalid ID. Try Again." << endl;

                }else{
                    idExists = true;
                }
            }

            removeAdvisee(facultyID, STUDENTid);
        }
        else if (input == "13"){
            // rollback();
        }
        else if (input == "14"){
            saveInfoFaculty();
            saveInfoStudents();
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

    string toPrint = "";

    TreeNode<Faculty> *node = facultyTree.getRoot(); // get root to print all nodes later
    writeFaculty << facultyToPrint(node);

    writeFaculty.close();
}

string Database::facultyToPrint(TreeNode<Faculty> *node){
    string toreturn = "";
    string secondreturn = "";
    string facInfo = "";
    if (node != NULL)
    {
        // studentInfo = node->key.getName
        // toreturn += node->key

        // gets all the info from the node to then add to file
        facInfo = node->key.getName() + "\n" + to_string(node->key.getId()) + "\n" + node->key.getLevel() + "\n" + node->key.getDept() + "\n";

        toreturn += facInfo;

        // traversing other nodes
        toreturn += facultyToPrint(node->left);
        toreturn += facultyToPrint(node->right);

        return toreturn;
    }
    else {
        return "";
    }
}

string Database::studentToPrint(TreeNode<Student> *node){
    string toreturn = "";
    string secondreturn = "";
    string studentInfo = "";
    if (node != NULL)
    {
        // gets all the info from the node to then add to file
        studentInfo = node->key.getName() + "\n" + to_string(node->key.getId()) + "\n" + node->key.getLevel() + "\n" + node->key.getMajor() + "\n" + to_string(node->key.getGPA()) + "\n" + to_string(node->key.getAdvisor());

        toreturn += studentInfo;

        // traversing other nodes
        toreturn += studentToPrint(node->left);
        toreturn += studentToPrint(node->right);

        return toreturn;
    }
    else {
        return "";
    }
}

void Database::saveInfoStudents(){
    ofstream writeStudents;
    writeStudents.open("studentTable.txt");

    string toPrint = "";

    TreeNode<Student> *node = studentTree.getRoot(); // get root to print all nodes later
    writeStudents << studentToPrint(node);

    writeStudents.close();
}

void Database::removeAdvisee(int facID, int stID){

    TreeNode<Faculty> *faculty = facultyTree.getRoot();
    while (faculty->key.getId() != facID) {
        if (facID >= faculty->key.getId()){
            faculty = faculty->right;
        }
        else{
            faculty = faculty->left;
        }
    }
    // remove advisee
    if (faculty->key.removeAdvisee(facID)) {
        cout << "Successfully removed avisee" << endl;
    }
    else {
        cout << "Could not remove, not contained in tree." << endl;
    }

}

void Database::changeAdvisor(int stID, int newFacID) {
    TreeNode<Student> *current = studentTree.getRoot(); // start from top
    while(current->key.getId() != stID) {
        if (stID >= current->key.getId()){
            current = current->right;
        }
        else {
            current = current->left;
        }
    }
    // have the student
    current->key.setAdvisor(newFacID); // updating
    // updating faculty tree
    TreeNode<Faculty> *faculty = facultyTree.getRoot();
    while (faculty->key.getId() != newFacID) {
        if (newFacID >= faculty->key.getId()){
            faculty = faculty->right;
        }
        else{
            faculty = faculty->left;
        }
    }
    faculty->key.addAdvisee(stID);
    cout << "Successfully added advisee." << endl;
}

void Database::displayAdvisor(int stID){

    int id;
    TreeNode<Student> *current = studentTree.getRoot(); // start at top to search
    while(current->key.getId() != stID) {
        if (stID >= current->key.getId()) {
            current = current->right;
        }
        else {
            current = current->left;
        }
    }

    id = current->key.getAdvisor();
    if (id == -1) {
        cout << "No advisor for student with id: " << stID << endl;
    }
    else {
        Faculty f;
        f.setID(id);
        facultyTree.printFacultyInfo(f);
    }
}

void Database::displayFacultyAdvisees(int facID) {

}
