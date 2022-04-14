#include "Student.h"

Student::Student(int id, int sessionTime): id(id), sessionTime(sessionTime), waitTime(0){}

int Student::getSessionTime() {	return sessionTime; }

int Student::getStudentID() { return id; }

int Student::getWaitTime() { return waitTime; }

void Student::setWaitTime() { waitTime++; }




