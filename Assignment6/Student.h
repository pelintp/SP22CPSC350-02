#ifndef STUDENT_H
#define STUDENT_H

class Student
{
public:
	Student(int id, int sessionTime);
	
	int getSessionTime();
	int getStudentID();
	int getWaitTime();
	void setWaitTime();

private:
	int id;
	int sessionTime;
	int waitTime;
};
#endif
